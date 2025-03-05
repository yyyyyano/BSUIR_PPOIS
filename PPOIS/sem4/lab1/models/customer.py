from .human import Human
from .date import Date
from .order import Order
from .menu import Menu

class Customer(Human):
    def __init__(self, name: str, surname: str, bday: Date, phone: str):
        super().__init__(name, surname, bday)

        try:
            if not self.__is_correct_phone_number(phone):
                raise ValueError("Invalid phone number")
            self.__phone = phone
        except ValueError as e:
            print(f"⚠️ Warning: {e}. Setting default phone number.")
            self.__phone = "+375000000000"

    @property
    def phone(self):
        return self.__phone


    @staticmethod
    def __is_correct_phone_number(phone_number: str) -> bool:
        if not phone_number:
            return False
        correct_size = 12
        current_size = 0
        if phone_number[0] == '+':
            for i in range(1, len(phone_number)):
                if phone_number[i].isdigit():
                    current_size += 1
                else:
                    return False
        return current_size == correct_size


    def make_order(self, menu: Menu):
        print("Input 2 dishes: ")

        while True:
            dish1_str = input("Dish 1: ")
            dish1 = menu.find_dish_by_name(dish1_str)
            if dish1:
                break
            print("❌ This dish was not found. Please try again.")

        while True:
            dish2_str = input("Dish 2: ")
            dish2 = menu.find_dish_by_name(dish2_str)
            if dish2:
                break
            print("❌ This dish was not found. Please try again.")

        date = Date(1, 3, 2024)
        order = Order(date, [dish1, dish2])
        print(f"✅ Dear {self.full_name}, Your order has been successfully placed. \nDetails:\n{order}")
        return order


    def book_table(self, table, capacity):
        if table.need_cleaning:
            print(f"Table #{table.table_number} needs cleaning. Please choose another table")
        else:
            table.occupy(capacity)
            print(f"Table #{table.table_number} has been booked for {capacity} people on name {self.full_name}.")

