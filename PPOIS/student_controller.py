from PPOIS.lab2.models.student_model import *


class StudentController:
    def __init__(self):
        self.model = StudentModel()

    def get_all_students(self):
        return self.model.get_all_students()

    def add_student(self, student: Student):
        self.model.add_student(student)

    def get_total_records(self):
        return self.model.count_students()

    def get_students_by_page(self, page, records_per_page):
        offset = (page - 1) * records_per_page
        return self.model.get_students_limit_offset(records_per_page, offset)

    def get_programming_languages(self):
        return [lang.strip() for lang in self.model.get_languages().split(',')]

    def find_students_by_filters(self, filters):
        filtered_filters = {k: v for k, v in filters.items() if v}

        if not filtered_filters:
            return self.model.get_all_students()
        return self.model.filter_students(filtered_filters)

    def delete_students_by_ids(self, student_ids):
        try:
            deleted_count = self.model.delete_students_by_ids(student_ids)
            return deleted_count
        except Exception as e:
            raise Exception(f"Ошибка при удалении студентов: {str(e)}")


    def add_student_from_file(self, student_data):
        student = Student(
            student_data[1],
            "",
            "",
            student_data[2],
            student_data[3],
            student_data[4],
            student_data[5],
            student_data[6]
        )
        self.model.add_student(student)

    def add_deleted_students(self, deleted_students):
        print("Adding the following students to deleted log:", deleted_students)
        try:
            self.model.add_deleted_students(deleted_students)
            print("Deleted students were successfully logged.")
        except Exception as e:
            print("Error when adding deleted students:", e)
            raise Exception(f"Ошибка при сохранении удаленных студентов: {str(e)}")
