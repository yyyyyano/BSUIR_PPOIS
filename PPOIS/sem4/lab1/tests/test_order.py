import pytest
from ..models.order import Order, OrderStatus
from ..models.date import Date
from ..models.dish import Dish


@pytest.fixture(autouse=True)
def reset_order_counter():
    Order.order_id_counter = 1


def test_order_str():
    date = Date(15, 6, 2023)
    dish1 = Dish("Pizza", 10.99, {"tomato": 5, "cheese": 3}, 250)
    dish2 = Dish("Pasta", 7.99, {"spaghetti": 3, "cheese": 2}, 300)
    order = Order(date, [dish1, dish2])

    expected_str = ("Order ID: 15.6.2023_1\nDate: 15.6.2023\n"
                    "Dishes: \n------------------------------\n"
                    "Dish name: Pizza \nPrice: 10.99 \nIngredients: {'tomato': 5, 'cheese': 3} \nWeight: 250\n------------------------------\n"
                    "Dish name: Pasta \nPrice: 7.99 \nIngredients: {'spaghetti': 3, 'cheese': 2} \nWeight: 300\n------------------------------\n"
                    "Status: OrderStatus.PENDING\nTotal price: 18.98")

    assert str(order) == expected_str


def test_order_initialization():
    date = Date(15, 6, 2023)
    dish1 = Dish("Pizza", 10.99, {"tomato": 5, "cheese": 3}, 250)
    dish2 = Dish("Pasta", 7.99, {"spaghetti": 3, "cheese": 2}, 300)
    order = Order(date, [dish1, dish2])

    assert order.order_id.startswith("15.6.2023_1")
    assert order.order_status == OrderStatus.PENDING
    assert order.get_total_price([dish1, dish2]) == 18.98
    assert len(order.dishes) == 2


def test_get_total_price():
    dish1 = Dish("Pizza", 10.99, {"tomato": 5, "cheese": 3}, 250)
    dish2 = Dish("Pasta", 7.99, {"spaghetti": 3, "cheese": 2}, 300)
    total_price = Order.get_total_price([dish1, dish2])
    assert total_price == 18.98


def test_calculate_serving_time():
    date = Date(15, 6, 2023)
    dish1 = Dish("Pizza", 10.99, {"tomato": 5, "cheese": 3}, 250)
    dish2 = Dish("Pasta", 7.99, {"spaghetti": 3, "cheese": 2}, 300)

    order = Order(date, [dish1, dish2])

    serving_time = order.calculate_serving_time()
    expected_time = 0.7 * (dish1.calculate_cook_time() + dish2.calculate_cook_time())

    assert serving_time == expected_time


def test_calculate_serving_time_zero():
    date = Date(15, 6, 2023)

    order = Order(date, [])

    serving_time = order.calculate_serving_time()
    expected_time = 0

    assert serving_time == expected_time


def test_order_status_setter():
    date = Date(15, 6, 2023)
    dish1 = Dish("Pizza", 10.99, {"tomato": 5, "cheese": 3}, 250)
    order = Order(date, [dish1])

    order.order_status = OrderStatus.IN_PROGRESS
    assert order.order_status == OrderStatus.IN_PROGRESS

    with pytest.raises(ValueError, match="Invalid order status"):
        order.order_status = "INVALID_STATUS"


def test_dishes_list():
    date = Date(15, 6, 2023)
    dish1 = Dish("Pizza", 10.99, {"tomato": 5, "cheese": 3}, 250)
    dish2 = Dish("Pasta", 7.99, {"spaghetti": 3, "cheese": 2}, 300)
    order = Order(date, [dish1, dish2])

    dish_list_str = order.dishes_list
    assert "Dish name: Pizza" in dish_list_str
    assert "Dish name: Pasta" in dish_list_str
