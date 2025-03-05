class Dish:
    def __init__(self, name: str, price: float, ingredients: dict, weight: float):
        self.__name = name
        self.__price = price
        self.__ingredients = ingredients
        self.__weight = weight


    @property
    def name(self):
        return self.__name


    def __str__(self):
        return f"Dish name: {self.__name} \nPrice: {self.__price} \nIngredients: {self.__ingredients} \nWeight: {self.__weight}"


    def add_ingredient(self, new_ingredient: str):
        if new_ingredient in self.__ingredients:
            print(f"Ingredient {new_ingredient} is already present in the menu.")
        else:
            self.__ingredients[new_ingredient] = 5
            print(f"Ingredient {new_ingredient} has been added to the menu.")


    def remove_ingredient(self, rem_ingredient: str):
        if rem_ingredient not in self.__ingredients:
            print(f"Ingredient {rem_ingredient} is not present in the menu.")
        else:
            self.__ingredients.pop(rem_ingredient)
            print(f"Ingredient {rem_ingredient} has been removed from the menu.")


    @property
    def price(self):
        return self.__price


    @price.setter
    def price(self, price: float):
        self.__price = price

    #
    # def apply_discount(self):
    #     if self.price <= 10.00:
    #         self.price *= 0.8
    #     elif 10.00 < self.price <= 50.00:
    #         self.__price = self.price * 0.9 + 1.45
    #     else:
    #         self.price -= 1.99
    #

    def calculate_cook_time(self):
        if not self.__ingredients:
            return 0
        else:
            return int(max(self.__ingredients.values()) * 1.1) + 10


    def cook(self):
        cook_time = self.calculate_cook_time()
        if cook_time == 0:
            raise ValueError("Dish has no ingredients")
        else:
            print(f"Dish {self.__name} is being prepared for {cook_time} minutes.")
            steps = [f"    Step 1: Preparing ingredients: {', '.join(self.__ingredients.keys())},\n"
                     f"    Step 2: Heat treatment\n"
                     f"    Step 3: Readiness check\n"
                     f"    Step 4: Serving"]
            for step in steps:
                print(step)
            print(f"Dish {self.__name} is ready to be eaten. Enjoy!")


    def to_dict(self):
        return {
            "name": self.name,
            "price": self.price,
            "ingredients": self.__ingredients,
            "weight": self.__weight
        }


    @classmethod
    def from_dict(cls, data):
        return cls(data["name"], data["price"], data["ingredients"], data["weight"])