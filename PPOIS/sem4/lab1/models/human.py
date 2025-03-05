from .date import Date

class Human:
    def __init__(self,name:str,surname:str,bday:Date):
        self.__name=name
        self.__surname=surname
        self.__bday=bday


    def __str__(self):
        return f"Full name: {self.full_name} \nBirthday: {self.__bday}"


    @property
    def full_name(self):
        return self.__surname + " " + self.__name