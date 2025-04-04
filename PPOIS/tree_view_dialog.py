from PyQt5 import QtWidgets
from PyQt5.QtWidgets import QTreeWidgetItem


class TreeViewDialog(QtWidgets.QDialog):
    def __init__(self, students, parent=None):
        super().__init__(parent)
        self.setWindowTitle("Дерево студентов")
        self.setGeometry(300, 200, 600, 400)

        self.layout = QtWidgets.QVBoxLayout(self)
        self.tree = QtWidgets.QTreeWidget(self)
        self.tree.setColumnCount(2)
        self.tree.setHeaderLabels(["Поле", "Значение"])

        self.populate_tree(students)

        self.layout.addWidget(self.tree)
        self.setLayout(self.layout)

    def populate_tree(self, students):
        for student in students:
            student_item = QTreeWidgetItem(self.tree)
            student_item.setText(0, f"Студент №{student[0]}")

            fields = ["ФИО", "Курс", "Группа", "Число работ", "Выполнено работ", "Язык программирования"]
            for field_name, value in zip(fields, student[1:]):
                field_item = QTreeWidgetItem(student_item)
                field_item.setText(0, field_name)
                field_item.setText(1, str(value))
