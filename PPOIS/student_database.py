import sqlite3
import os
from PPOIS.lab2.models.student import *

class StudentDatabase:
    def __init__(self):
        self.db_path = os.path.join(os.path.dirname(__file__), "../database/students.db")
        self.create_db()

    def count_students(self):
        with sqlite3.connect(self.db_path) as db:
            cursor = db.cursor()
            cursor.execute("SELECT COUNT(*) FROM students")
            return cursor.fetchone()[0]

    def get_students_limit_offset(self, limit, offset):
        with sqlite3.connect(self.db_path) as db:
            cursor = db.cursor()
            query = "SELECT * FROM students LIMIT ? OFFSET ?"
            cursor.execute(query, (limit, offset))
            return cursor.fetchall()

    def create_db(self):
        with sqlite3.connect(self.db_path) as db:
            cursor=db.cursor()
            query="""
            CREATE TABLE IF NOT EXISTS students(
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            full_name TEXT,
            course TEXT,
            study_group INTEGER,
            number_of_works INTEGER,
            made_works INTEGER,
            programming_language TEXT)
            """

            cursor.execute(query)
            db.commit()

    def add_student(self,student:Student):
        with sqlite3.connect(self.db_path) as db:
            cursor=db.cursor()

            query = """ INSERT INTO students(full_name, course, study_group, number_of_works, made_works, programming_language)
                        VALUES (?, ?, ?, ?, ?, ?)"""

            cursor.execute(query, (
                student.full_name,
                student.course,
                student.group,
                student.number_of_works,
                student.made_works,
                student.programming_language
            ))

        db.commit()

    def get_students_by_num_of_unfulfilled_works(self, number: int):
        with sqlite3.connect(self.db_path) as db:
            cursor = db.cursor()
            query = """
                  SELECT * FROM students WHERE number_of_works - made_works = ?
            """
            st = cursor.execute(query, (number,))
            return st.fetchall()


    def get_students_by_criteria(self, filters):
        with sqlite3.connect(self.db_path) as db:
            cursor = db.cursor()

            query = "SELECT * FROM students"
            conditions = []
            parameters = []

            for key, value in filters.items():
                if value is not None and value != "":
                    if key == "full_name":

                        name_parts = value.split()
                        name_conditions = []
                        for part in name_parts:
                            name_conditions.append("full_name LIKE ?")
                            parameters.append(f"%{part}%")
                        conditions.append("(" + " OR ".join(name_conditions) + ")")

                    elif key == "not_made_works":
                        return self.get_students_by_num_of_unfulfilled_works(int(value))

                    elif key == "study_group":
                        conditions.append('"study_group" = ?')
                        parameters.append(value.strip())

                    else:
                        conditions.append(f"{key} = ?")
                        parameters.append(value.strip())

            if conditions:
                query += " WHERE " + " AND ".join(conditions)

            st = cursor.execute(query, parameters)
            return st.fetchall()

    def get_all_students(self):
        with sqlite3.connect(self.db_path) as db:
            cursor = db.cursor()
            query = """SELECT * FROM students"""

            st = cursor.execute(query)
            return st.fetchall()

    def get_programming_languages(self):
        with sqlite3.connect(self.db_path) as db:
            cursor = db.cursor()
            query = """SELECT * FROM programming_languages"""
            st = cursor.execute(query)
            languages = [row[0] for row in st.fetchall()]
            return ", ".join(languages)


    def delete_students_by_ids(self, student_ids):
        with sqlite3.connect(self.db_path) as db:
            cursor = db.cursor()

            query = f"DELETE FROM students WHERE id IN ({','.join('?' * len(student_ids))})"
            cursor.execute(query, student_ids)

            deleted_count = cursor.rowcount

        db.commit()
        return deleted_count

    def add_deleted_students(self, deleted_students):
        with sqlite3.connect(self.db_path) as db:
            cursor = db.cursor()
            query1 = """CREATE TABLE IF NOT EXISTS deleted_students (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                full_name TEXT,
                course TEXT,
                study_group INTEGER,
                number_of_works INTEGER,
                made_works INTEGER,
                programming_language TEXT
            )"""
            cursor.execute(query1)


            query = """INSERT INTO deleted_students 
                       (full_name, course, study_group, number_of_works, made_works, programming_language) 
                       VALUES (?, ?, ?, ?, ?, ?)"""


            for student in deleted_students:
                data = student[1:]
                print("Inserting student data:", data)
                cursor.execute(query, data)

    def clear_students(self):
        with sqlite3.connect(self.db_path) as db:
            cursor = db.cursor()
            cursor.execute("DELETE * FROM students")
            db.commit()

