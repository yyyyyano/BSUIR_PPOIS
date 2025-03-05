import pytest
from unittest.mock import patch, MagicMock
from ..models.menu import Menu
from ..models.customer import Customer
from ..models.mouse import Mouse
from ..models.employee import Employee
from ..models.canteen import Canteen
from ..models.table import Table
from ..models.date import Date


@pytest.fixture
def sample_menu():
    menu = Menu()
    menu.load_from_file("C:\\Users\\Bankevich\\PycharmProjects\\PythonProject\\PPOIS\\lab1\\menu.json")
    return menu

@pytest.fixture
def sample_employee():
    return Employee("John", "Doe", Date(1, 1, 1990), "Waiter")

@pytest.fixture
def sample_customer():
    return Customer("Alice", "Smith", Date(5, 7, 1995), "+375291234567")

@pytest.fixture
def sample_table():
    return Table(capacity=4)

@pytest.fixture
def sample_canteen(sample_menu, sample_employee, sample_table):
    return Canteen(
        name="Sunny Side",
        menu=sample_menu,
        staff=[sample_employee],
        address="123 Main Street",
        orders=[],
        tables=[sample_table]
    )

def test_show_menu(sample_canteen):
    with patch("builtins.print") as mock_print, patch.object(Mouse, "dance"):
        sample_canteen.show_menu()
        mock_print.assert_any_call("Going to the warehouse for the menu...")

def test_plan_menu_for_day(sample_canteen):
    with patch("builtins.print") as mock_print:
        sample_canteen.plan_menu_for_day()
        mock_print.assert_any_call("Menu for day:")

def test_serve_customer_with_free_employee(sample_canteen, sample_customer):
    with patch("builtins.print") as mock_print, patch.object(Employee, "serve_customer"):

        sample_canteen.serve_customer(sample_customer)
        mock_print.assert_any_call(f"Congratulations, {sample_customer.full_name}! You are being served by employee Doe John.")

def test_serve_customer_with_no_available_employees(sample_canteen, sample_customer, sample_employee):
    sample_employee.availability = "UNAVAILABLE"
    with patch("builtins.print") as mock_print:
        sample_canteen.serve_customer(sample_customer)
        mock_print.assert_any_call("You don't have enough money!")

def test_cleaning(sample_canteen, sample_employee, sample_table):
    sample_table.need_cleaning = True
    with patch.object(Employee, "clean_table") as mock_clean:
        sample_canteen.cleaning()
        mock_clean.assert_called_with(sample_table)

def test_manage_orders(sample_canteen):
    with patch.object(Employee, "manage_orders") as mock_manage_orders:
        sample_canteen.manage_orders()
        mock_manage_orders.assert_called()
