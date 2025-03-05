# Canteen System

## Описание проекта

**Canteen System** — симуляция столовой. В проекте предусмотрены такие функции, как работа с меню, обслуживание клиентов, управление заказами, чистка столов, обработка статусов сотрудников, обработка заказов и взаимодействие всех элементов системы.

## Основные классы и их функции:

### 1. **Canteen**
Класс представляет саму столовую. Отвечает за запуск системы, управление персоналом, заказами, столами и меню.

- **Основные функции:**
  - Загрузка меню.
  - Назначение сотрудников для обслуживания клиентов.
  - Управление таблицами.
  - Обработка заказов.

---

### 2. **Menu**
Класс меню, который позволяет управлять списком блюд и организовывать меню для клиентов.

- **Основные функции:**
  - Добавление и удаление блюд.
  - Отображение списка блюд по категориям.
  - Поиск блюд по названию.
  - Планирование меню на день.
  - Сохранение и загрузка меню в JSON файл.

---

### 3. **Dish**
Класс, представляющий блюдо.

- **Основные функции:**
  - Хранение данных о блюде: название, цена, ингредиенты, вес.
  - Изменение состава ингредиентов.
  - Расчёт времени приготовления.
  - Эмуляция процесса готовки блюд.

---

### 4. **Employee**
Класс, представляющий сотрудников столовой.

- **Основные функции:**
  - Хранение информации о сотрудниках: личные данные, идентификатор, статус доступности.
  - Переключение статусов сотрудника (`FREE`, `ONLINE`, `UNAVAILABLE`).
  - Обслуживание клиентов: приготовление заказов, управление заказами, чистка столов.

---

### 5. **Customer**
Класс, представляющий клиента столовой.

- **Основные функции:**
  - Хранение данных клиента: имя, фамилия, дата рождения, номер телефона.
  - Сделать заказ, выбирая блюда из меню.
  - Забронировать стол, если он доступен.

---

### 6. **Order**
Класс заказа.

- **Основные функции:**
  - Создание заказа клиента (с добавлением блюд и привязкой к дате).
  - Хранение деталей: блюда, стоимость, статус заказа (`PENDING`, `IN_PROGRESS`, `COMPLETE`).
  - Расчёт времени на приготовление заказа.

---

### 7. **Table**
Класс, представляющий столы в столовой.

- **Основные функции:**
  - Управление доступным количеством мест.
  - Объединение столов при необходимости.
  - Проверка и переключение статуса на "нуждается в чистке".

---

### 8. **Mouse**
Класс, созданный для забавы. Симулирует неожиданное появление мыши в столовой.

- **Особенность:**
  - Воспроизводит заранее выбранное видео, имитируя танцующего мышонка.

---

### 9. **Date**
Класс для работы с датами (например, для заказов).

- **Основные функции:**
  - Проверка корректности даты.
  - Учет високосных годов.
  - Сравнение и хранение даты.

---

### 10. **Human**
Базовый класс для общих характеристик людей (клиентов и сотрудников).

- **Основные функции:**
  - Хранение личной информации: имя, фамилия, дата рождения.
  - Представление общего интерфейса для других классов.

---

## Взаимодействие классов

Классы отлично взаимодействуют друг с другом:
- **Customer** делает заказ, используя **Menu**. Заказ создаётся через **Order**.
- **Employee** проверяет доступные столы через **Table**, обслуживает клиентов и управляет заказами.
- **Canteen** работает как управляющая структура, связывая все классы между собой.

## UML-диаграмма

**Диаграмма классов**:

![diagram_uml](https://github.com/user-attachments/assets/d84d2410-0b53-4213-b6c2-2f084b3c60fb)


**Диаграмма состояний**:

```plaintext
@startuml
skinparam style rose

[*] --> Initialization : Program start
Initialization --> load_from_file : Loading Menu from json
load_from_file --> menu_of_selections : Main menu_of_selections
menu_of_selections --> action_one : 1 choice
action_one --> show_menu : Viewing menu*
show_menu --> mouse_dance : Bonus
mouse_dance --> menu_of_selections : Return

menu_of_selections --> action_two : 2 choice
action_two --> plan_menu_for_day : Planning Menu
plan_menu_for_day --> menu_of_selections : Return

menu_of_selections --> action_three : 3 choice
action_three --> init_dish : Entering dish info
init_dish --> add_dish : Adding new dish to menu
add_dish --> save_to_file : Saving updated menu to json
save_to_file --> menu_of_selections: Return

menu_of_selections --> action_four: 4 choice
action_four --> cleaning : Cleaning all tables
cleaning --> menu_of_selections : Return

menu_of_selections --> action_five: 5 choice
action_five --> manage_orders : Managing all orders by employees
manage_orders --> menu_of_selections : Return

menu_of_selections --> action_six : 6 choice
action_six --> init_customer : Creating customer
init_customer --> book_table : Booking table for entered capacity
book_table --> menu_of_selections: Return

menu_of_selections --> action_seven : 7 choice
action_seven --> init_customer : Creating customer
init_customer --> serve_customer : Serving customer by Employee
serve_customer --> make_order : Customer makes Order
make_order --> cook : Cooking dishes from Order
cook --> menu_of_selections : Return

menu_of_selections --> action_eight : 8 choice
action_eight --> menu : Viewing menu
menu --> menu_of_selections: Return

menu_of_selections --> exit : 0 choice
exit --> [*]

@enduml

```

![diagram_PPOIS1](https://github.com/user-attachments/assets/9afc900b-b387-4e2d-8efe-d59afb59e01e)

