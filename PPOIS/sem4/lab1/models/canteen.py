from .menu import Menu
from .customer import Customer
from .order import Order
from .mouse import Mouse
# from .employee import EmployeeStatus

class Canteen:
    def __init__(self,name:str,menu:Menu,staff:list, address:str,orders:list,tables:list):
        self.__menu=menu
        self.__address=address
        self.__name=name
        self.__staff=staff
        self.__orders=orders
        self.__tables=tables

    @property
    def menu(self):
        return self.__menu

    @property
    def tables(self):
        return self.__tables

    @property
    def  employees(self):
        return self.__staff


    def show_menu(self):
        print(f"Welcome to {self.__name} Canteen!")
        print(f"Menu for {self.__address} Canteen:")
        print("Going to the warehouse for the menu...")
        mouse=Mouse("Mikky")
        mouse.dance()
        print(self.__menu)


    def plan_menu_for_day(self):
        print(f"Menu for day:")
        print(self.__menu.plan_menu_for_day())


    def serve_customer(self,customer:Customer):
        served=False
        for employee in self.__staff:
            if employee.availability=="FREE":
                print(f"Congratulations, {customer.full_name}! You are being served by employee {employee.full_name}.")
                employee.serve_customer(customer,self.menu)
                self.__orders.append(self.menu)
                served=True
                break
            else:
                continue
        if not served:
            print("You don't have enough money!")

    # def cleaning(self):
    #     tables_num=self.__tables.__len__()
    #     counter=0
    #     while counter<tables_num:
    #         for employee in self.__staff:
    #             print(f"Cleaning tables for employee {employee.full_name}...")
    #             for table in self.__tables:
    #                 print(f"Table #{table.table_number} is being cleaned...")
    #                 employee.clean_table(table)
    #                 counter+=1
    def cleaning(self):
        for employee in self.__staff:
            if employee.availability == "FREE":
                print(f"Cleaning tables for employee {employee.full_name}...")
                for table in self.__tables:
                    print(f"Table #{table.table_number} is being cleaned by {employee.full_name}...")
                    employee.clean_table(table)
                return  # Завершаем функцию после уборки
            else:
                print(f"Employee {employee.full_name} is busy. Moving to the next employee.")
        print("No free employees available for cleaning.")

        # print(type(employee.availability))
            # print(type(EmployeeStatus.FREE))
            # print(f"Employee {employee.full_name} status {employee.availability}")
            # if employee.availability==EmployeeStatus.FREE:
            #     for table in self.__tables:
            #         employee.clean_table(table)
            #     return
            # else:
            #     print(f"Sorry, employee {employee.full_name} busy right now.")

    #work
    def manage_orders(self):
        for employee in self.__staff:
            employee.manage_orders(self.__orders)



