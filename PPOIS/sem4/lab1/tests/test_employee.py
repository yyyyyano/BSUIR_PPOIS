import pytest
from unittest.mock import patch
from ..models.employee import Employee
from ..models.customer import Customer
from ..models.date import Date
from ..models.menu import Menu
from ..models.dish import Dish
from ..models.order import Order, OrderStatus
from ..models.table import Table

@pytest.fixture(autouse=True)
def reset_employee_counter():
    Order.__employee_id = 0

@pytest.fixture
def sample_employee():
    return Employee("Yana", "Banka", Date(10, 5, 1985), "Waiter")

@pytest.fixture
def sample_customer():
    return Customer("Nika", "Nika", Date(15, 6, 1990), "+375291234567")

@pytest.fixture
def sample_menu():
    menu = Menu()
    pizza=Dish("Pizza", 10.99, {"tomato": 5, "cheese": 3}, 250)
    pasta=Dish("Pasta", 7.99, {"spaghetti": 3, "cheese": 2}, 300)
    menu.add_dish("Fast food",pizza)
    menu.add_dish("Fast food",pasta)
    return menu

@pytest.fixture
def sample_order(sample_menu):
    date = Date(1, 3, 2024)
    dish1 = sample_menu.find_dish_by_name("Pizza")
    dish2 = sample_menu.find_dish_by_name("Pasta")
    return Order(date, [dish1, dish2])

@pytest.fixture
def sample_table():
    return Table(5)


def test_employee_initialization(sample_employee):
    assert sample_employee.availability == "FREE"
    assert sample_employee._Employee__personal_id=="Wait_7"


def test_employee_is_available(sample_employee, capsys):
    sample_employee.is_available()
    captured = capsys.readouterr()
    assert "is available. How can we help you?" in captured.out
    assert sample_employee.availability == "ONLINE"

def test_str(sample_employee):
    expect_str="Full name: Banka Yana \nBirthday: 10.5.1985\nPosition: Waiter \nPersonal ID: Wait_9"
    assert expect_str==str(sample_employee)


def test_employee_is_not_available(sample_employee, capsys):
    sample_employee.availability = "UNAVAILABLE"
    sample_employee.is_available()
    captured = capsys.readouterr()
    assert "is not available at the moment." in captured.out


@patch("builtins.input", side_effect=["Pizza", "Pasta"])
def test_serve_customer(mock_input, sample_employee, sample_customer, sample_menu, capsys):
    sample_employee.serve_customer(sample_customer, sample_menu)
    captured = capsys.readouterr()
    expect_str=('Input 2 dishes: \n✅ Dear Nika Nika, Your order has been successfully placed. \nDetails:\n'
                'Order ID: 1.3.2024_3\n'
                'Date: 1.3.2024\n'
                'Dishes: \n'
                '------------------------------\n'
                'Dish name: Pizza \n'
                'Price: 10.99 \n'
                "Ingredients: {'tomato': 5, 'cheese': 3} \n"
                'Weight: 250\n'
                '------------------------------\n'
                'Dish name: Pasta \n'
                'Price: 7.99 \n'
                "Ingredients: {'spaghetti': 3, 'cheese': 2} \n"
                'Weight: 300\n'
                '------------------------------\n'
                'Status: OrderStatus.PENDING\n'
                'Total price: 18.98\n'
                'Dish Pizza is being prepared for 15 minutes.\n'
                '    Step 1: Preparing ingredients: tomato, cheese,\n'
                '    Step 2: Heat treatment\n'
                '    Step 3: Readiness check\n'
                '    Step 4: Serving\n'
                'Dish Pizza is ready to be eaten. Enjoy!\n'
                'Dish Pasta is being prepared for 13 minutes.\n'
                '    Step 1: Preparing ingredients: spaghetti, cheese,\n'
                '    Step 2: Heat treatment\n'
                '    Step 3: Readiness check\n'
                '    Step 4: Serving\n'
                'Dish Pasta is ready to be eaten. Enjoy!\n'
                'Order #1.3.2024_3 is ready. Enjoy!\n')
    assert expect_str in captured.out
    assert sample_employee.availability == "UNAVAILABLE"


def test_manage_orders(sample_employee, sample_order, capsys):
    orders = [sample_order]
    sample_employee.manage_orders(orders)
    captured = capsys.readouterr()
    assert f"Order {sample_order.order_id} will be processed" in captured.out
    assert sample_order.order_status == OrderStatus.IN_PROGRESS

def test_manage_orders_not_free(sample_employee, sample_order, capsys):
    orders = [sample_order]
    sample_employee.availability = "UNAVAILABLE"
    sample_employee.manage_orders(orders)
    captured = capsys.readouterr()
    assert f"Sorry, employee {sample_employee.full_name} is not available at the moment." in captured.out

def test_manage_orders_in_progress(sample_employee, sample_order, capsys):
    sample_order.order_status = OrderStatus.IN_PROGRESS
    orders = [sample_order]
    sample_employee.manage_orders(orders)
    captured = capsys.readouterr()
    expected_output=('Employee Banka Yana is managing orders.\n'
                     'Order 1.3.2024_6 is processed...\n'
                     'Order 1.3.2024_6 has been completed.\n'
                     '----------------------------------------\n')
    assert expected_output in captured.out
    assert sample_order.order_status == OrderStatus.COMPLETE

def test_manage_orders_completed(sample_employee, sample_order, capsys):
    sample_order.order_status = OrderStatus.COMPLETE
    orders = [sample_order]
    sample_employee.manage_orders(orders)
    captured = capsys.readouterr()
    expected_output=('Employee Banka Yana is managing orders.\n'
                     'Order 1.3.2024_7 is processed...\n'
                     'Order 1.3.2024_7 has already been processed.\n'
                     '----------------------------------------\n')
    assert expected_output in captured.out



def test_clean_table(sample_employee, sample_table, capsys):
    sample_table.need_cleaning = True
    sample_employee.clean_table(sample_table)
    captured = capsys.readouterr()
    assert f"Employee Banka Yana is cleaning table 9.\n" in captured.out
    assert not sample_table.need_cleaning
    assert sample_employee.availability == "UNAVAILABLE"


def test_clean_table_already_clean(sample_employee, sample_table, capsys):
    sample_table.need_cleaning = False
    sample_employee.clean_table(sample_table)
    captured = capsys.readouterr()
    assert f"Table {sample_table.table_number} is already clean." in captured.out

def test_clean_table_unavailable(sample_employee, sample_table, capsys):
    sample_table.need_cleaning = True
    sample_employee.availability = "UNAVAILABLE"
    sample_employee.clean_table(sample_table)
    captured = capsys.readouterr()
    assert f"Employee Banka Yana cannot clean table {sample_table.table_number} right now\n" in captured.out
