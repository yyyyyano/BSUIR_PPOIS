from PPOIS.lab2.models.student import *
from PPOIS.lab2.database.student_database import StudentDatabase

class StudentModel:
    def __init__(self):
        self.database=StudentDatabase()

    def get_all_students(self):
        return self.database.get_all_students()

    def add_student(self,student:Student):
        self.database.add_student(student)

    def get_languages(self):
        return self.database.get_programming_languages()

    def filter_students(self, filters):
        return self.database.get_students_by_criteria(filters)

    def count_students(self):
        return self.database.count_students()

    def get_students_limit_offset(self, limit, offset):
        return self.database.get_students_limit_offset(limit, offset)

    def delete_students_by_ids(self, student_ids):
        return self.database.delete_students_by_ids(student_ids)

    def add_deleted_students(self, deleted_students):
        self.database.add_deleted_students(deleted_students)

    def clear_students(self):
        self.database.clear_students()
