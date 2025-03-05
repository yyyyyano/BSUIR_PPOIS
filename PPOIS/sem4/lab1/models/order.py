from .date import Date
from enum import Enum

OrderStatus = Enum('OrderStatus', ['PENDING', 'IN_PROGRESS', 'COMPLETE'])


class Order:
    order_id_counter = 1

    def __init__(self, date: Date, dishes: list):
        self.__order_id = date.__str__()+ "_" + str(self.order_id_counter)
        Order.order_id_counter += 1
        self.__date = date
        self.__dishes = dishes
        self.__total_price = self.get_total_price(dishes)
        self.__order_status = OrderStatus.PENDING


    def __str__(self):
        return (f"Order ID: {self.__order_id}"
                f"\nDate: {self.__date}"
                f"\nDishes: {self.dishes_list}"
                f"\nStatus: {self.__order_status}"
                f"\nTotal price: {self.__total_price}")
    #def __str__(self):
    #     return f"Order ID: {self.__order_id} \nDate: {self.__date} \n" + \
    #         f"Dishes:\n------------------------------\n" + \
    #         f"{self.dishes_list}" + \
    #         f"------------------------------\n" + \
    #         f"Status: {self.__order_status} \nTotal price: {self.__total_price}"

    @property
    def dishes_list(self):
        dish_list="\n"+"-"*30
        for dish in self.__dishes:
            dish_list=dish_list+"\n"+dish.__str__()+"\n"
            dish_list+="-"*30
        return dish_list


    @staticmethod
    def get_total_price(dishes) -> float:
        total_price = 0.0
        for dish in dishes:
            total_price += dish.price
        return round(total_price,2)

    @property
    def dishes(self):
        return self.__dishes

    def calculate_serving_time(self):
        if not self.__dishes:
            return 0
        return 0.7 * sum(dish.calculate_cook_time() for dish in self.__dishes)

    @property
    def order_id(self):
        return self.__order_id

    @property
    def order_status(self):
        return self.__order_status

    @order_status.setter
    def order_status(self,value):
        if not isinstance(value, OrderStatus):
            raise ValueError("Invalid order status")
        self.__order_status=value
