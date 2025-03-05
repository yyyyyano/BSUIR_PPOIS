import pytest
from ..models.dish import Dish


def test_dish_initialization():
    ingredients = {"tomato": 5, "cheese": 3}
    dish = Dish("Pizza", 10.99, ingredients, 250.0)

    assert dish.name == "Pizza"
    assert dish.price == 10.99
    assert dish._Dish__ingredients == ingredients
    assert dish._Dish__weight == 250.0


def test_add_ingredient():
    ingredients = {"tomato": 5, "cheese": 3}
    dish = Dish("Pizza", 10.99, ingredients, 250.0)

    dish.add_ingredient("basil")
    assert "basil" in dish._Dish__ingredients

    dish.add_ingredient("tomato")


def test_remove_ingredient():
    ingredients = {"tomato": 5, "cheese": 3}
    dish = Dish("Pizza", 10.99, ingredients, 250.0)

    dish.remove_ingredient("tomato")
    assert "tomato" not in dish._Dish__ingredients

    dish.remove_ingredient("mushrooms")


def test_dish_str():
    ingredients = {"tomato": 5, "cheese": 3}
    dish = Dish("Pizza", 10.99, ingredients, 250.0)

    expected_str = ("Dish name: Pizza \n"
                    "Price: 10.99 \n"
                    "Ingredients: {'tomato': 5, 'cheese': 3} \n"
                    "Weight: 250.0")
    assert str(dish) == expected_str


def test_calculate_cook_time():
    ingredients = {"tomato": 5, "cheese": 3}
    dish = Dish("Pizza", 10.99, ingredients, 250.0)

    expected_cook_time = int(5 * 1.1) + 10
    assert dish.calculate_cook_time() == expected_cook_time


def test_cook():
    ingredients = {"tomato": 5, "cheese": 3}
    dish = Dish("Pizza", 10.99, ingredients, 250.0)

    dish.cook()


def test_to_dict():
    ingredients = {"tomato": 5, "cheese": 3}
    dish = Dish("Pizza", 10.99, ingredients, 250.0)

    expected_dict = {
        "name": "Pizza",
        "price": 10.99,
        "ingredients": {"tomato": 5, "cheese": 3},
        "weight": 250.0
    }
    assert dish.to_dict() == expected_dict


def test_from_dict():
    data = {
        "name": "Pizza",
        "price": 10.99,
        "ingredients": {"tomato": 5, "cheese": 3},
        "weight": 250.0
    }

    dish = Dish.from_dict(data)
    assert dish.name == "Pizza"
    assert dish.price == 10.99
    assert dish._Dish__ingredients == {"tomato": 5, "cheese": 3}
    assert dish._Dish__weight == 250.0
