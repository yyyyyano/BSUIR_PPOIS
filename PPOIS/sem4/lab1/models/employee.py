from .human import Human
from .date import Date
from .table import Table
from .customer import Customer
from .order import Order, OrderStatus
from enum import Enum
from .menu import Menu
from enum import Enum


# class EmployeeStatus(Enum):
#     FREE = "FREE"
#     BUSY = "BUSY"
#     UNAVAILABLE = "UNAVAILABLE"


class Employee(Human):
    __employee_id=0
    def __init__(self,name:str,surname:str,bday:Date,position:str):
        super().__init__(name,surname,bday)
        self.__position=position
        Employee.__employee_id+=1
        self.__personal_id=position[:4] + "_" +str(self.__employee_id)
        self.__availability="FREE"

    def __str__(self):
        return super().__str__() + f"\nPosition: {self.__position} \nPersonal ID: {self.__personal_id}"

    def is_available(self):
        if self.availability == "FREE":
            print(f"Employee {self.full_name} is available. How can we help you?")
            self.availability = "ONLINE"
        else:
            print(f"Sorry, employee {self.full_name} is not available at the moment.")

    @property
    def availability(self):
        return self.__availability

    @availability.setter
    def availability(self, value):
        if not isinstance(value, str):
            raise ValueError("Invalid availability status")
        self.__availability = value

    #work
    def serve_customer(self,customer:Customer,menu:Menu):
        self.availability = "UNAVAILABLE"
        order=customer.make_order(menu)
        for dish in order.dishes:
            dish.cook()
        print(f"Order #{order.order_id} is ready. Enjoy!")


    def manage_orders(self,orders:list):
        if self.availability=="FREE":
            print(f"Employee {self.full_name} is managing orders.")
            self.availability="UNAVAILABLE"
            for order in orders:
                print(f"Order {order.order_id} is processed...")
                if order.order_status==OrderStatus.PENDING:
                    print(f"Order {order.order_id} will be processed in {round(order.calculate_serving_time(), 2)} minutes.")
                    order.order_status=OrderStatus.IN_PROGRESS
                    for dish in order.dishes:
                        dish.cook()
                elif order.order_status==OrderStatus.IN_PROGRESS:
                    order.order_status=OrderStatus.COMPLETE
                    print(f"Order {order.order_id} has been completed.")
                else:
                    print(f"Order {order.order_id} has already been processed.")
                    orders.remove(order)
                print("-"*40)
        else:
            print(f"Sorry, employee {self.full_name} is not available at the moment.")


    def clean_table(self,table:'Table'):
        if table.need_cleaning and self.availability=="FREE":
            self.availability="UNAVAILABLE"
            print(f"Employee {self.full_name} is cleaning table {table.table_number}.")
            table.need_cleaning=False
        elif table.need_cleaning and self.availability=="UNAVAILABLE":
            print(f"Employee {self.full_name} cannot clean table {table.table_number} right now")
        else:
            print(f"Table {table.table_number} is already clean.")