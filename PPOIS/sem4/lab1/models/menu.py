from .dish import Dish
import json

class Menu:
    def __init__(self):
        self.__menu={} #category - dish


    def add_dish(self,category:str,dish:Dish):
        if category not in self.__menu.keys():
            self.__menu[category]=[dish]
        else:
            self.__menu[category].append(dish)


    def __str__(self):
        result=""
        for category,dishes in self.__menu.items():
            result+=f"\033[1m{category.upper()}:\033[0m\n"
            for dish in dishes:
                result=result + f"{dish}\n\n"
            self.__print_separator()
        return result


    @staticmethod
    def __print_separator(num=30,sep='-'):
        separator=sep*num
        return separator


    def list_by_category(self,category:str):
        if category not in self.__menu.keys():
            raise ValueError("Invalid category")
        else:
            print(f"List of dishes in the {category.upper()} category:")
            print(self.__print_separator())
            for dish in self.__menu[category]:
                print(dish)
                print(self.__print_separator())


    def plan_menu_for_day(self):

        menu_plan = Menu()
        menu_plan.add_dish("Breakfast", self.__menu["Breakfast"][1])
        menu_plan.add_dish("Breakfast",self.__menu["Hot drinks"][0])

        menu_plan.add_dish("Launch",self.__menu["Soup"][0])
        menu_plan.add_dish("Launch", self.__menu["Hot combo"][2])
        menu_plan.add_dish("Launch", self.__menu["Cold drinks"][1])

        menu_plan.add_dish("Dinner",self.__menu["Fish"][0])
        menu_plan.add_dish("Dinner", self.__menu["Garnish"][1])
        menu_plan.add_dish("Dinner", self.__menu["Cold drinks"][0])
        return menu_plan

    def find_dish_by_name(self, dish_name: str):
        for category, dishes in self.__menu.items():
            for dish in dishes:
                if dish.name.lower() == dish_name.lower():
                    return dish
        return None

    def save_to_file(self, filename="menu.json"):
        menu_data = {
            category: [dish.to_dict() for dish in dishes] for category, dishes in self.__menu.items()
        }
        with open(filename, "w", encoding="utf-8") as f:
            json.dump(menu_data, f, indent=4, ensure_ascii=False)
        print("Menu saved successfully!")

    def load_from_file(self, filename="menu.json"):
        try:
            with open(filename, "r", encoding="utf-8") as f:
                menu_data = json.load(f)
                for category, dishes in menu_data.items():
                    self.__menu[category] = [Dish.from_dict(dish) for dish in dishes]
            print("Menu loaded successfully!")
        except (FileNotFoundError, json.JSONDecodeError):
            print("Menu file not found or corrupted. Create a new menu.")
