import pytest
import json
import os
from ..models.menu import Menu
from ..models.dish import Dish

@pytest.fixture
def sample_menu():
    menu = Menu()
    dish1 = Dish("Pizza", 10.99, {"tomato": 5, "cheese": 3}, 250)
    dish2 = Dish("Pasta", 7.99, {"spaghetti": 3, "cheese": 2}, 300)
    dish3 = Dish("Soup", 5.99, {"carrot": 2, "potato": 3}, 200)

    menu.add_dish("Italian", dish1)
    menu.add_dish("Italian", dish2)
    menu.add_dish("Soup", dish3)

    return menu, dish1, dish2, dish3


@pytest.fixture
def setup_menu():
    menu = Menu()
    test_file = os.path.join("C:\\Users\\Bankevich\\PycharmProjects\\PythonProject\\PPOIS\\lab1\\menu.json")

    try:
        menu.load_from_file(test_file)
    except FileNotFoundError:
        pytest.fail("Файл menu.json не найден!")

    return menu


def test_plan_menu(setup_menu):
    menu = setup_menu
    day_menu = menu.plan_menu_for_day()

    expected_str = ('\x1b[1mBREAKFAST:\x1b[0m\n'
                    'Dish name: Porridge \n'
                    'Price: 5.0 \n'
                    "Ingredients: {'porridge': 5, 'water': 0} \n"
                    'Weight: 200\n'
                    '\n'
                    'Dish name: Green Tea \n'
                    'Price: 2.5 \n'
                    "Ingredients: {'tea': 5, 'water': 3} \n"
                    'Weight: 330\n'
                    '\n'
                    '\x1b[1mLAUNCH:\x1b[0m\n'
                    'Dish name: Borshch \n'
                    'Price: 11.5 \n'
                    "Ingredients: {'water': 10, 'cabbage': 5, 'potato': 5, 'meat': 2, 'beets': "
                    '4} \n'
                    'Weight: 500\n'
                    '\n'
                    'Dish name: Mac-n-cheese \n'
                    'Price: 16.7 \n'
                    "Ingredients: {'macaroni': 14, 'cheese souse': 5} \n"
                    'Weight: 430\n'
                    '\n'
                    'Dish name: Orange juice \n'
                    'Price: 5.0 \n'
                    "Ingredients: {'orange juice': 1} \n"
                    'Weight: 330\n'
                    '\n'
                    '\x1b[1mDINNER:\x1b[0m\n'
                    'Dish name: Red fish \n'
                    'Price: 4.15 \n'
                    "Ingredients: {'red fish': 7, 'oregano': 1} \n"
                    'Weight: 150\n'
                    '\n'
                    'Dish name: Macaroni \n'
                    'Price: 4.0 \n'
                    "Ingredients: {'macaroni': 1} \n"
                    'Weight: 330\n'
                    '\n'
                    'Dish name: Apple juice \n'
                    'Price: 5.0 \n'
                    "Ingredients: {'apple juice': 1} \n"
                    'Weight: 330\n'
                    '\n')
    assert str(day_menu) == expected_str

def test_add_dish(sample_menu):
    menu, dish1, dish2, dish3 = sample_menu

    assert "Italian" in menu._Menu__menu
    assert len(menu._Menu__menu["Italian"]) == 2
    assert dish1 in menu._Menu__menu["Italian"]
    assert dish2 in menu._Menu__menu["Italian"]

    assert "Soup" in menu._Menu__menu
    assert len(menu._Menu__menu["Soup"]) == 1
    assert dish3 in menu._Menu__menu["Soup"]


def test_find_dish_by_name(sample_menu):
    menu, dish1, dish2, _ = sample_menu

    assert menu.find_dish_by_name("Pizza") == dish1
    assert menu.find_dish_by_name("Pasta") == dish2
    assert menu.find_dish_by_name("Burger") is None


def test_list_by_category(sample_menu, capsys):
    menu, _, _, _ = sample_menu

    menu.list_by_category("Italian")
    captured = capsys.readouterr()

    assert "List of dishes in the ITALIAN category:" in captured.out
    assert "Pizza" in captured.out
    assert "Pasta" in captured.out


def test_list_by_category_invalid(sample_menu):
    menu, _, _, _ = sample_menu

    with pytest.raises(ValueError, match="Invalid category"):
        menu.list_by_category("Desserts")


def test_menu_str(sample_menu):
    menu, _, _, _ = sample_menu
    menu_str = str(menu)

    assert "ITALIAN:" in menu_str
    assert "Pizza" in menu_str
    assert "Pasta" in menu_str
    assert "SOUP:" in menu_str
    assert "Soup" in menu_str


def test_save_and_load_menu(sample_menu):
    menu, _, _, _ = sample_menu
    test_filename = "test_menu.json"

    menu.save_to_file(test_filename)
    assert os.path.exists(test_filename)

    new_menu = Menu()
    new_menu.load_from_file(test_filename)

    assert "Italian" in new_menu._Menu__menu
    assert "Soup" in new_menu._Menu__menu
    assert len(new_menu._Menu__menu["Italian"]) == 2
    assert len(new_menu._Menu__menu["Soup"]) == 1

    os.remove(test_filename)
