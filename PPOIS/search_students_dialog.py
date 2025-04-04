import sys
import os
from PPOIS.lab2.models.student import *
from PyQt5 import QtWidgets,QtCore
from PyQt5.QtWidgets import QMainWindow, QTableWidgetItem, QInputDialog, QMessageBox, QTableWidget
from PyQt5.QtGui import QFont

class SearchStudentDialog(QtWidgets.QDialog):
    def __init__(self, controller, parent=None):
        super().__init__(parent)
        self.controller = controller
        self.setWindowTitle("Поиск студента")
        self.setGeometry(300, 150, 800, 600)


        self.layout = QtWidgets.QVBoxLayout()
        self.first_criteria_layout=QtWidgets.QHBoxLayout()
        self.second_criteria_layout=QtWidgets.QHBoxLayout()


        self.allowed_combinations = {
            "ФИО": "Группа",
            "Группа": "ФИО",
            "Курс": "Язык программирования",
            "Язык программирования": "Курс",
            "Количество работ": "Выполнено работ",
            "Выполнено работ": "Количество работ",
            "Число невыполненных работ": None
        }


        self.criteria_dropdown = QtWidgets.QComboBox()
        self.criteria_dropdown.addItems(self.allowed_combinations.keys())
        self.criteria_dropdown.currentTextChanged.connect(self.update_second_criteria)
        self.first_criteria_layout.addWidget(QtWidgets.QLabel("Выберите первый критерий:"))
        self.first_criteria_layout.addWidget(self.criteria_dropdown)
        self.criteria_dropdown.setFixedSize(150,30)


        self.first_criteria_input = QtWidgets.QStackedWidget()
        self.first_criteria_line_edit = QtWidgets.QLineEdit()
        self.first_criteria_course_combo = QtWidgets.QComboBox()
        self.first_criteria_lang_combo = QtWidgets.QComboBox()
        self.first_criteria_input.addWidget(self.first_criteria_line_edit)
        self.first_criteria_input.addWidget(self.first_criteria_course_combo)
        self.first_criteria_input.addWidget(self.first_criteria_lang_combo)
        self.first_criteria_layout.addWidget(self.first_criteria_input)
        self.first_criteria_input.setFixedSize(200,30)

        self.layout.addLayout(self.first_criteria_layout)

        self.second_criteria_label = QtWidgets.QLabel("Второй критерий:")
        self.second_criteria_layout.addWidget(self.second_criteria_label)
        self.second_criteria_input = QtWidgets.QStackedWidget()
        self.second_criteria_line_edit = QtWidgets.QLineEdit()
        self.second_criteria_course_combo = QtWidgets.QComboBox()
        self.second_criteria_lang_combo = QtWidgets.QComboBox()
        self.second_criteria_input.addWidget(self.second_criteria_line_edit)
        self.second_criteria_input.addWidget(self.second_criteria_course_combo)
        self.second_criteria_input.addWidget(self.second_criteria_lang_combo)
        self.second_criteria_layout.addWidget(self.second_criteria_input)
        self.second_criteria_input.setFixedSize(200,30)

        self.layout.addLayout(self.second_criteria_layout)
        self.layout.addLayout(self.layout)

        self.search_button = QtWidgets.QPushButton("Найти")
        self.search_button.clicked.connect(self.search_students)

        search_button_layout = QtWidgets.QHBoxLayout()
        search_button_layout.addStretch()
        search_button_layout.addWidget(self.search_button)
        search_button_layout.addStretch()
        self.layout.addLayout(search_button_layout)
        self.search_button.setFixedSize(200, 30)

        self.result_table = QtWidgets.QTableWidget()
        self.result_table.setColumnCount(7)
        self.result_table.setHorizontalHeaderLabels([
            "id","ФИО", "Курс", "Группа", "Количество работ",
            "Выполнено работ", "Язык программирования"
        ])
        self.layout.addWidget(self.result_table)

        self.setLayout(self.layout)

        self.load_dropdown_values()


    def load_dropdown_values(self):
        courses = ["", "Freshman", "Sophomore", "Junior", "Senior"]
        languages = [""] + self.controller.get_programming_languages()

        self.first_criteria_course_combo.addItems(courses)
        self.second_criteria_course_combo.addItems(courses)

        self.first_criteria_lang_combo.addItems(languages)
        self.second_criteria_lang_combo.addItems(languages)


    def update_second_criteria(self, selected_first):
        second_criteria = self.allowed_combinations.get(selected_first)

        if selected_first == "Курс":
            self.first_criteria_input.setCurrentWidget(self.first_criteria_course_combo)
        elif selected_first == "Язык программирования":
            self.first_criteria_input.setCurrentWidget(self.first_criteria_lang_combo)
        else:
            self.first_criteria_input.setCurrentWidget(self.first_criteria_line_edit)

        if second_criteria:
            self.second_criteria_label.setText(f"Второй критерий ({second_criteria}):")
            self.second_criteria_input.setEnabled(True)

            if second_criteria == "Курс":
                self.second_criteria_input.setCurrentWidget(self.second_criteria_course_combo)
            elif second_criteria == "Язык программирования":
                self.second_criteria_input.setCurrentWidget(self.second_criteria_lang_combo)
            else:
                self.second_criteria_input.setCurrentWidget(self.second_criteria_line_edit)
        else:
            self.second_criteria_label.setText("Второй критерий: (не требуется)")
            self.second_criteria_input.setEnabled(False)


    def search_students(self):
        first_criteria = self.criteria_dropdown.currentText()
        second_criteria = self.allowed_combinations.get(first_criteria)

        if first_criteria == "Курс":
            first_value = self.first_criteria_course_combo.currentText()
        elif first_criteria == "Язык программирования":
            first_value = self.first_criteria_lang_combo.currentText()
        else:
            first_value = self.first_criteria_line_edit.text().strip()

        if self.second_criteria_input.isEnabled():
            if second_criteria == "Курс":
                second_value = self.second_criteria_course_combo.currentText()
            elif second_criteria == "Язык программирования":
                second_value = self.second_criteria_lang_combo.currentText()
            else:
                second_value = self.second_criteria_line_edit.text().strip()
        else:
            second_value = None

        if not first_value:
            QMessageBox.warning(self, "Ошибка", "Введите значение для первого критерия поиска или выберите из списка.")
            return

        criteria_mapping = {
            "ФИО": "full_name",
            "Группа": "study_group",
            "Курс": "course",
            "Язык программирования": "programming_language",
            "Количество работ": "number_of_works",
            "Выполнено работ": "made_works",
            "Число невыполненных работ": "not_made_works"
        }

        filters = {}
        if first_value:
            filters[criteria_mapping[first_criteria]] = first_value
        if second_criteria and second_value:
            filters[criteria_mapping[second_criteria]] = second_value

        try:
            students = self.controller.find_students_by_filters(filters)
        except Exception as e:
            QMessageBox.critical(self, "Ошибка", f"Ошибка при поиске студентов: {str(e)}")
            return

        if not students:
            QMessageBox.information(self, "Результаты поиска", "Студенты, подходящие под эти критерии, не найдены.")
            return

        self.result_table.setRowCount(len(students))
        for row, student in enumerate(students):
            for col, value in enumerate(student):
                self.result_table.setItem(row, col, QTableWidgetItem(str(value)))