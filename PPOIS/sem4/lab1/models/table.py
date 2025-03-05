from .customer import Customer

class Table:
    table_counter=1
    def __init__(self,capacity=6):
        self.__table_number = self.table_counter
        Table.table_counter+=1
        self.__capacity = capacity
        self.__is_occupied = False
        self.__need_cleaning=self.__needs_cleaning()
        self.__merged_tables=[self.__table_number]

    @property
    def table_number(self):
        return self.__table_number

    @property
    def need_cleaning(self):
        return self.__need_cleaning

    @need_cleaning.setter
    def need_cleaning(self,value):
        self.__need_cleaning=value

    def __needs_cleaning(self):
        if not self.__is_occupied:
            return False
        else:
            return True


    def __merge_tables(self,other_table):
        other_table.__merged_tables.append(self.__table_number)
        self.__merged_tables.append(other_table.__table_number)
        self.__capacity+=4


    def __str__(self):
        return f"Table #{self.__table_number} with capacity {self.__capacity}. Merged tables: {self.__merged_tables}"


    def increase_capacity(self, new_capacity):
        new_capacity-=6
        while new_capacity > 0:
            new_table = Table(capacity=self.__capacity+4)
            self.__merge_tables(new_table)
            new_capacity-=4


    def occupy(self,people_number:int):
        if people_number<=self.__capacity:
            self.__is_occupied=True
            self.need_cleaning=self.__needs_cleaning()
        else:
            self.increase_capacity(people_number)
            self.__is_occupied=True
            self.need_cleaning = self.__needs_cleaning()
            print(f"Tables {self.__merged_tables} have been merged into one table #{self.__table_number}")

