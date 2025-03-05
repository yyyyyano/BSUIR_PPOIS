from .models.date import Date
from .models.customer import Customer
from .models.canteen import Canteen
from .models.dish import Dish

def action_one(canteen:Canteen):
    canteen.show_menu()

def action_two(canteen:Canteen):
    canteen.plan_menu_for_day()

def action_three(canteen:Canteen):
    print("Creating new dish...\nEnter dish info:")
    category=input("Dish category: ")
    dish_name=input("Dish name: ")
    dish_price=float(input("Dish price: "))
    num=input("Enter number of ingredients:")
    dish_ingredients= {}
    for i in range(0,int(num)):
        print("Ingredient #",i+1,"info:")
        ingredient=input("Enter ingredient: ")
        cook_time=int(input("Enter cook time: "))
        dish_ingredients[ingredient]=cook_time
    weight=int(input("Enter weight of dish: "))
    dish=Dish(dish_name,dish_price,dish_ingredients,weight)
    canteen.menu.add_dish(category,dish)
    print("Dish has been successfully added to the menu.")
    canteen.menu.save_to_file()

def action_four(canteen:Canteen):
    canteen.cleaning()
    # for employee in canteen.employees:
    #     employee.clean_tables()

def action_five(canteen:Canteen):
    canteen.manage_orders()

def action_six(canteen:Canteen):
    print("Enter customer info:")
    name = input("Name: ")
    surname = input("Surname: ")
    phone = input("Phone number (start with +375...)")
    day, month, year = input("Enter date (dd.mm.yyyy): ").split(".")
    date = Date(int(day), int(month), int(year))
    customer = Customer(name, surname, date, phone)
    capacity = int(input("Enter table capacity: "))
    customer.book_table(canteen.tables[0], capacity)

def action_seven(canteen:Canteen):
    print("Enter customer info:")
    name = input("Name: ")
    surname = input("Surname: ")
    phone = input("Phone number (start with +375...)")
    day,month,year=input("Enter date (dd.mm.yyyy): ").split(".")
    date = Date(int(day), int(month), int(year))
    customer = Customer(name, surname, date, phone)
    canteen.serve_customer(customer)

def action_eight(canteen:Canteen):
    print(canteen.menu)

def exit_program(canteen:Canteen):
    print("Exit program")
    exit()

def invalid_choice(canteen:Canteen):
    print("Incorrect choice. Please try again.")

menu_actions = {
    "1": action_one,
    "2": action_two,
    "3": action_three,
    "4": action_four,
    "5": action_five,
    "6": action_six,
    "7": action_seven,
    "8": action_eight,
    "0": exit_program
}

def menu_of_selections(canteen:Canteen):
    while True:
        print("\n","-"*40,"\n")
        choice = input("Choose an option:\n"
                       "1 - get menu\n"
                       "2 - plan menu for day\n"
                       "3 - add new dish to menu\n"
                       "4 - clean tables\n"
                       "5 - manage all orders\n"
                       "6 - book table\n"
                       "7 - get served (make order)\n"
                       "8 - norm menu\n"
                       "0 - quit\n ")

        action = menu_actions.get(choice, invalid_choice)
        action(canteen)
