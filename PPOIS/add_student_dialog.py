import sys
import os
from PPOIS.lab2.models.student import *
from PyQt5 import QtWidgets,QtCore
from PyQt5.QtWidgets import QMainWindow, QTableWidgetItem, QInputDialog, QMessageBox, QTableWidget
from PyQt5.QtGui import QFont

class AddStudentDialog(QtWidgets.QDialog):
    def __init__(self, controller, parent=None):
        super().__init__(parent)
        self.controller = controller
        self.setWindowTitle("Добавить студента")
        self.setGeometry(300, 200, 400, 300)

        self.layout = QtWidgets.QVBoxLayout()
        self.fields = {}

        for label in ["Фамилия", "Имя", "Отчество", "Группа", "Количество работ", "Выполнено работ"]:
            h_layout = QtWidgets.QHBoxLayout()
            lbl = QtWidgets.QLabel(label)
            line_edit = QtWidgets.QLineEdit()
            h_layout.addWidget(lbl)
            h_layout.addWidget(line_edit)
            self.fields[label] = line_edit
            self.layout.addLayout(h_layout)


        h_layout_course = QtWidgets.QHBoxLayout()
        lbl_course = QtWidgets.QLabel("Курс")
        self.course_dropdown = QtWidgets.QComboBox()
        self.course_dropdown.addItems(["Freshman", "Sophomore", "Junior", "Senior"])
        h_layout_course.addWidget(lbl_course)
        h_layout_course.addWidget(self.course_dropdown)
        self.layout.addLayout(h_layout_course)


        h_layout_proglang = QtWidgets.QHBoxLayout()
        lbl_proglang = QtWidgets.QLabel("Язык программирования")
        self.proglang_dropdown = QtWidgets.QComboBox()
        programming_languages = self.controller.get_programming_languages()
        self.proglang_dropdown.addItems(programming_languages)
        h_layout_proglang.addWidget(lbl_proglang)
        h_layout_proglang.addWidget(self.proglang_dropdown)
        self.layout.addLayout(h_layout_proglang)

        self.add_button = QtWidgets.QPushButton("Добавить")
        self.add_button.clicked.connect(self.add_student)
        self.layout.addWidget(self.add_button)

        self.setLayout(self.layout)


    def add_student(self):
        surname = self.fields["Фамилия"].text()
        name = self.fields["Имя"].text()
        patronymic = self.fields["Отчество"].text()
        course = self.course_dropdown.currentText()
        group = self.fields["Группа"].text()
        num_of_works = self.fields["Количество работ"].text()
        made_works = self.fields["Выполнено работ"].text()
        progr_lang = self.proglang_dropdown.currentText()

        try:
            group = int(group)
            if len(str(group)) != 6:
                group = 123456
        except ValueError:
            group = 123456

        try:
            num_of_works = int(num_of_works)
            if num_of_works < 0:
                num_of_works = abs(num_of_works)
        except ValueError:
            num_of_works = 0

        try:
            made_works = int(made_works)
            if made_works < 0:
                made_works = abs(made_works)
        except ValueError:
            made_works = 0

        student = Student(surname, name, patronymic, course, group, num_of_works, made_works, progr_lang)
        self.controller.add_student(student)
        self.accept()