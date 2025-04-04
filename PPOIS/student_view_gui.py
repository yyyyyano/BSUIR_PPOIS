import sys
import os
from PPOIS.lab2.models.student import *
from PyQt5 import QtWidgets,QtCore
from PyQt5.QtWidgets import QMainWindow, QTableWidgetItem,QFileDialog, QInputDialog, QMessageBox, QTableWidget
from PyQt5.QtGui import QFont
from PPOIS.lab2.view.add_student_dialog import AddStudentDialog
from PPOIS.lab2.view.search_students_dialog import SearchStudentDialog
from PPOIS.lab2.view.delete_student_dialog import DeleteStudentDialog
from PPOIS.lab2.view.tree_view_dialog import TreeViewDialog
from PPOIS.lab2.models.XMLparser import *

class StudentViewGUI(QMainWindow):
    def __init__(self, controller):
        super().__init__()
        self.controller = controller
        self.current_page = 1
        self.records_per_page = 10
        self.total_records = 0
        self.total_pages = 1

        self.setWindowTitle("Student Management System")
        self.setGeometry(100, 100, 1200, 800)

        self.load_styles()


        self.main_widget = QtWidgets.QWidget()
        self.main_layout = QtWidgets.QHBoxLayout(self.main_widget)


        self.left_panel = QtWidgets.QVBoxLayout()
        self.add_student_button = QtWidgets.QPushButton("Добавить студента", self)
        self.add_student_button.clicked.connect(self.add_student)
        self.left_panel.addWidget(self.add_student_button)

        self.search_student_button = QtWidgets.QPushButton("Поиск студентов", self)
        self.search_student_button.clicked.connect(self.search_student)
        self.left_panel.addWidget(self.search_student_button)

        self.delete_student_button = QtWidgets.QPushButton("Удалить студентов", self)
        self.delete_student_button.clicked.connect(self.delete_student)
        self.left_panel.addWidget(self.delete_student_button)

        self.tree_view_button = QtWidgets.QPushButton("Показать дерево", self)
        self.tree_view_button.clicked.connect(self.show_tree_view)
        self.left_panel.addWidget(self.tree_view_button)

        self.load_from_predefined_files_button = QtWidgets.QPushButton("Загрузить из файла", self)
        self.load_from_predefined_files_button.clicked.connect(self.load_from_predefined_file)
        self.left_panel.addWidget(self.load_from_predefined_files_button)

        self.export_to_xml_button = QtWidgets.QPushButton("Экспортировать в XML", self)
        self.export_to_xml_button.clicked.connect(self.export_to_xml_file)
        self.left_panel.addWidget(self.export_to_xml_button)

        self.left_panel.addStretch()


        self.main_layout.addLayout(self.left_panel)


        self.central_layout = QtWidgets.QVBoxLayout()
        self.table = QTableWidget(self)
        self.table.setColumnCount(7)
        self.table.setHorizontalHeaderLabels(["№", "ФИО", "Курс", "Группа", "Число работ", "Выполнено работ", "ЯП"])
        self.table.setFont(QFont("Arial", 10))
        self.table.setSelectionBehavior(QtWidgets.QAbstractItemView.SelectRows)
        self.central_layout.addWidget(self.table)


        self.page_controls_layout = QtWidgets.QHBoxLayout()
        self.first_page_button = QtWidgets.QPushButton("<< Первая")
        self.first_page_button.clicked.connect(self.to_first_page)
        self.page_controls_layout.addWidget(self.first_page_button)

        self.previous_page_button = QtWidgets.QPushButton("< Предыдущая")
        self.previous_page_button.clicked.connect(self.to_previous_page)
        self.page_controls_layout.addWidget(self.previous_page_button)

        self.page_info_label = QtWidgets.QLabel("Страница: 1 / 1, записей: 0")
        self.page_controls_layout.addWidget(self.page_info_label)

        self.next_page_button = QtWidgets.QPushButton("Следующая >")
        self.next_page_button.clicked.connect(self.to_next_page)
        self.page_controls_layout.addWidget(self.next_page_button)

        self.last_page_button = QtWidgets.QPushButton("Последняя >>")
        self.last_page_button.clicked.connect(self.to_last_page)
        self.page_controls_layout.addWidget(self.last_page_button)

        self.records_per_page_label = QtWidgets.QLabel("Записей на страницу:")
        self.page_controls_layout.addWidget(self.records_per_page_label)

        self.records_per_page_dropdown = QtWidgets.QComboBox()
        self.records_per_page_dropdown.addItems(["5", "10", "20", "50"])
        self.records_per_page_dropdown.currentIndexChanged.connect(self.change_records_per_page)
        self.page_controls_layout.addWidget(self.records_per_page_dropdown)

        self.central_layout.addLayout(self.page_controls_layout)

        self.main_layout.addLayout(self.central_layout)

        self.setCentralWidget(self.main_widget)

        self.update_student_table()


    def export_to_xml_file(self):
        file_path = "data/students_file3.xml"

        if file_path:
            try:
                students = self.controller.get_all_students()
                XMLWriter.save_to_file(students, file_path)
                QMessageBox.information(self, "Успех", f"База данных экспортирована в файл {file_path}.")
            except Exception as e:
                QMessageBox.critical(self, "Ошибка", f"Ошибка экспорта: {str(e)}")


    def load_from_predefined_file(self):
        predefined_files = [
            "data/students_file1.xml",
            "data/students_file2.xml"
        ]

        file_path, ok = QtWidgets.QInputDialog.getItem(
            self,
            "Выбор файла",
            "Выберите файл для загрузки:",
            predefined_files,
            0,
            False
        )

        if ok and file_path:
            try:
                handler = XMLReader()
                parser = xml.sax.make_parser()
                parser.setContentHandler(handler)
                parser.parse(file_path)

                students = handler.students
                for student in students:
                    self.controller.add_student_from_file(student)

                self.update_student_table()
                QMessageBox.information(
                    self, "Успех",
                    f"Данные успешно загружены из файла: {file_path}"
                )

            except Exception as e:
                QMessageBox.critical(
                    self, "Ошибка",
                    f"Произошла ошибка при загрузке данных: {str(e)}"
                )


    def save_to_file(self):
        file_path, _ = QFileDialog.getSaveFileName(self, "Сохранить файл", "", "XML Files (*.xml)")

        if file_path:
            try:
                students = self.controller.get_all_students()
                XMLWriter.save_to_file(students, file_path)
                QMessageBox.information(self, "Успех", f"Данные успешно сохранены в файл: {file_path}")
            except Exception as e:
                QMessageBox.critical(self, "Ошибка", f"Ошибка при сохранении данных: {str(e)}")


    def show_tree_view(self):
        students = self.controller.get_all_students()
        dialog = TreeViewDialog(students, self)
        dialog.exec_()


    def load_styles(self):
        with open(os.path.join(os.path.dirname(__file__), "../view/styles.css"), 'r') as css_file:
            self.setStyleSheet(css_file.read())


    def update_student_table(self):
        self.total_records = self.controller.get_total_records()
        self.total_pages = max(1, (self.total_records + self.records_per_page - 1) // self.records_per_page)

        students = self.controller.get_students_by_page(self.current_page, self.records_per_page)

        self.table.setRowCount(len(students))
        self.table.setColumnCount(7)

        for i, student in enumerate(students):
            self.table.setItem(i, 0, QTableWidgetItem(str(student[0])))
            self.table.setItem(i, 1, QTableWidgetItem(student[1]))
            self.table.setItem(i, 2, QTableWidgetItem(student[2]))
            self.table.setItem(i, 3, QTableWidgetItem(str(student[3])))
            self.table.setItem(i, 4, QTableWidgetItem(str(student[4])))
            self.table.setItem(i, 5, QTableWidgetItem(str(student[5])))
            self.table.setItem(i, 6, QTableWidgetItem(student[6]))

        self.page_info_label.setText(
            f"Страница: {self.current_page} / {self.total_pages}, записей: {self.total_records}"
        )


    def to_first_page(self):
        self.current_page = 1
        self.update_student_table()

    def to_previous_page(self):
        if self.current_page > 1:
            self.current_page -= 1
            self.update_student_table()

    def to_next_page(self):
        if self.current_page < self.total_pages:
            self.current_page += 1
            self.update_student_table()

    def to_last_page(self):
        self.current_page = self.total_pages
        self.update_student_table()

    def change_records_per_page(self):
        self.records_per_page = int(self.records_per_page_dropdown.currentText())
        self.current_page = 1
        self.update_student_table()

    def add_student(self):
        dialog = AddStudentDialog(self.controller, self)
        dialog.exec_()
        self.update_student_table()

    def search_student(self):
        dialog = SearchStudentDialog(self.controller, self)
        dialog.exec_()

    def delete_student(self):
        dialog = DeleteStudentDialog(self.controller, self)
        dialog.exec_()
        self.update_student_table()

