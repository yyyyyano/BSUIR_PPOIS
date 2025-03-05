import pytest
from unittest.mock import patch
from ..models.customer import Customer
from ..models.date import Date
from ..models.menu import Menu
from ..models.dish import Dish
from ..models.table import Table

@pytest.fixture
def sample_customer():
    return Customer("John", "Doe", Date(15, 6, 1990), "+375291234567")

@pytest.fixture
def sample_menu():
    menu = Menu()
    pizza=Dish("Pizza", 10.99, {"tomato": 5, "cheese": 3}, 250)
    pasta=Dish("Pasta", 7.99, {"spaghetti": 3, "cheese": 2}, 300)
    menu.add_dish("Fast food",pizza)
    menu.add_dish("Fast food",pasta)
    return menu

@pytest.fixture
def sample_table():
    return Table()

def test_customer_initialization_valid_phone():
    customer = Customer("Alice", "Smith", Date(10, 5, 1985), "+375291234567")
    assert customer.phone == "+375291234567"

def none_phone():
    customer = Customer("Alice", "Smith", Date(10, 5, 1985), "+dstfrdewrqas")
    assert customer.phone == "+375000000000"

def test_customer_initialization_invalid_phone():
    customer = Customer("Alice", "Smith", Date(10, 5, 1985), "12345")
    assert customer.phone == "+375000000000"

@patch("builtins.input", side_effect=["Pizza", "Pasta"])
def test_make_order(mock_input, sample_customer, sample_menu):
    order = sample_customer.make_order(sample_menu)
    assert order is not None
    assert len(order.dishes) == 2
    assert order.dishes[0].name == "Pizza"
    assert order.dishes[1].name == "Pasta"

@patch("builtins.input", side_effect=["Burger", "Pizza", "Pasta"])
def test_make_order_invalid_dish(mock_input, sample_customer, sample_menu, capsys):
    order = sample_customer.make_order(sample_menu)
    captured = capsys.readouterr()
    assert "❌ This dish was not found. Please try again." in captured.out
    assert order.dishes[0].name == "Pizza"
    assert order.dishes[1].name == "Pasta"

def test_book_table_clean(sample_customer, sample_table, capsys):
    sample_table.need_cleaning = False
    sample_customer.book_table(sample_table, 4)
    captured = capsys.readouterr()
    assert f"Table #{sample_table.table_number} has been booked for 4 people on name Doe John.\n" in captured.out

def test_book_table_needs_cleaning(sample_customer, sample_table, capsys):
    sample_table.need_cleaning = True
    sample_customer.book_table(sample_table, 4)
    captured = capsys.readouterr()
    assert f"Table #{sample_table.table_number} needs cleaning. Please choose another table\n" in captured.out
