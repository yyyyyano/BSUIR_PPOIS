class Date:
    def __init__(self, day: int, month: int, year: int):
        if not self.__is_valid_date(day, month, year):
            raise ValueError(f"Invalid date: {day}.{month}.{year}")
        self.__day = day
        self.__month = month
        self.__year = year


    @staticmethod
    def __is_leap_year(year: int) -> bool:
        return year % 4 == 0 and year % 100 != 0 or year % 400 == 0


    def __max_days_in_month(self, month: int, year: int) -> int:
        if month == 2:
            return 29 if self.__is_leap_year(year) else 28
        elif month in (4, 6, 9, 11):
            return 30
        else:
            return 31


    def __str__(self):
        return f"{self.__day}.{self.__month}.{self.__year}"


    def __is_valid_date(self, day: int, month: int, year: int) -> bool:
        if not 1901 < year < 2025:
            return False
        if not 1 <= month <= 12:
            return False
        if not 1 <= day <= self.__max_days_in_month(month, year):
            return False
        return True