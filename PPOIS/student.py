class Student:
    def __init__(self, surname:str, name:str, patronymic:str, course:str, group:int, num_of_works:int,made_works:int,progr_lang:str):
        self.__surname=surname
        self.__name=name
        self.__patronymic=patronymic
        self.__course=course  #Freshman, Sophomore, Junior, Senior
        self.__group=group
        self.__num_of_works=num_of_works
        self.__made_works=made_works
        self.__progr_lang=progr_lang

    def to_dict(self):
        return {
            "full_name": self.__surname + ' '+self.__name+' '+self.__patronymic,
            "course": str(self.__course),
            "group": self.__group,
            "num_of_works": str(self.__num_of_works),
            "made_works": str(self.__made_works),
            "programming_language": self.__progr_lang
        }

    @property
    def full_name(self):
        return self.__surname+' '+self.__name+' '+self.__patronymic

    @property
    def programming_language(self):
        return self.__progr_lang

    @property
    def group(self):
        return self.__group

    @property
    def course(self):
        return self.__course

    @property
    def number_of_works(self):
        return self.__num_of_works

    @property
    def made_works(self):
        return self.__made_works