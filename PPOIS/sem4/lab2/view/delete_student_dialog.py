import sys
import os
from PPOIS.lab2.models.student import *
from PyQt5 import QtWidgets, QtCore
from PyQt5.QtWidgets import QMainWindow, QTableWidgetItem, QInputDialog, QMessageBox, QTableWidget
from PyQt5.QtGui import QFont


class DeleteStudentDialog(QtWidgets.QDialog):
    def __init__(self, controller, parent=None):
        super().__init__(parent)
        self.controller = controller
        self.setWindowTitle("Удаление студентов")
        self.setGeometry(300, 150, 800, 600)

        self.layout = QtWidgets.QVBoxLayout()
        self.first_criteria_layout = QtWidgets.QHBoxLayout()
        self.second_criteria_layout = QtWidgets.QHBoxLayout()

        self.criteria_mapping = {
            "ФИО": "full_name",
            "Группа": "study_group",
            "Курс": "course",
            "Язык программирования": "programming_language",
            "Количество работ": "number_of_works",
            "Выполнено работ": "made_works",
            "Число невыполненных работ": "not_made_works"
        }

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
        self.criteria_dropdown.setFixedSize(150, 30)

        self.first_criteria_input = QtWidgets.QStackedWidget()
        self.first_criteria_line_edit = QtWidgets.QLineEdit()
        self.first_criteria_course_combo = QtWidgets.QComboBox()
        self.first_criteria_lang_combo = QtWidgets.QComboBox()
        self.first_criteria_input.addWidget(self.first_criteria_line_edit)
        self.first_criteria_input.addWidget(self.first_criteria_course_combo)
        self.first_criteria_input.addWidget(self.first_criteria_lang_combo)
        self.first_criteria_layout.addWidget(self.first_criteria_input)
        self.first_criteria_input.setFixedSize(200, 30)

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
        self.second_criteria_input.setFixedSize(200, 30)

        self.layout.addLayout(self.second_criteria_layout)

        self.search_button = QtWidgets.QPushButton("Найти студентов")
        self.search_button.clicked.connect(self.find_students)

        search_button_layout = QtWidgets.QHBoxLayout()
        search_button_layout.addStretch()
        search_button_layout.addWidget(self.search_button)
        search_button_layout.addStretch()
        self.layout.addLayout(search_button_layout)
        self.search_button.setFixedSize(200, 30)

        self.result_table = QtWidgets.QTableWidget()
        self.result_table.setColumnCount(8)
        self.result_table.setHorizontalHeaderLabels([
            "", "id", "ФИО", "Курс", "Группа", "Количество работ",
            "Выполнено работ", "Язык программирования"
        ])
        self.layout.addWidget(self.result_table)

        self.delete_button = QtWidgets.QPushButton("Удалить выбранных")
        self.delete_button.clicked.connect(self.confirm_deletion)
        self.layout.addWidget(self.delete_button)

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


    def find_students(self):
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
            QMessageBox.warning(self, "Ошибка", "Введите значение первого критерия.")
            return


        first_criteria_db = self.criteria_mapping.get(first_criteria)
        second_criteria_db = self.criteria_mapping.get(second_criteria) if second_criteria else None

        filters = {first_criteria_db: first_value}
        if second_criteria_db and second_value:
            filters[second_criteria_db] = second_value

        students = self.controller.find_students_by_filters(filters)

        if not students:
            QMessageBox.information(self, "Результаты поиска", "Студенты не найдены.")
            return

        self.result_table.setRowCount(len(students))
        for row, student in enumerate(students):
            checkbox = QtWidgets.QCheckBox()
            self.result_table.setCellWidget(row, 0, checkbox)
            for col, value in enumerate(student):
                self.result_table.setItem(row, col + 1, QTableWidgetItem(str(value)))


    def confirm_deletion(self):
        selected_students = []
        for row in range(self.result_table.rowCount()):
            checkbox = self.result_table.cellWidget(row, 0)
            if checkbox and checkbox.isChecked():
                student_data = [self.result_table.item(row, col).text() for col in range(1, 8)]
                selected_students.append(student_data)

        if not selected_students:
            QMessageBox.warning(self, "Ошибка", "Выберите студентов для удаления.")
            return

        confirmation_msg = "Вы уверены, что хотите удалить следующих студентов?\n"
        confirmation_msg += "\n".join([", ".join(student) for student in selected_students])

        reply = QMessageBox.question(
            self, "Подтверждение удаления", confirmation_msg,
            QMessageBox.Yes | QMessageBox.No, QMessageBox.No
        )

        if reply == QMessageBox.Yes:
            student_ids = [student[0] for student in selected_students]
            deleted_count = self.controller.delete_students_by_ids(student_ids)
            self.controller.add_deleted_students(selected_students)
            QMessageBox.information(self, "Удаление завершено", f"Удалено {deleted_count} студентов.")
            self.close()
