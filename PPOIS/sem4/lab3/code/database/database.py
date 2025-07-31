import sqlite3
import os

db_path = os.path.join(os.path.dirname(__file__), "../database/records.db")


def init_database():
    with sqlite3.connect(db_path) as db:
        cursor = db.cursor()
        query = """
               CREATE TABLE IF NOT EXISTS records(
               full_name TEXT,
               score INTEGER
               )
               """

        cursor.execute(query)
        db.commit()


def update_records( name, score):
    with sqlite3.connect(db_path) as db:
        cursor = db.cursor()

        cursor.execute("""
                DELETE FROM records WHERE full_name = ?
            """, (name,))

        cursor.execute("""
                INSERT INTO records (full_name, score) VALUES (?, ?)
            """, (name, score))

        cursor.execute("""
                DELETE FROM records WHERE rowid NOT IN (
                    SELECT rowid FROM records
                    ORDER BY score DESC
                    LIMIT 15
                )
            """)

        db.commit()


def get_all_records():
    with sqlite3.connect(db_path) as db:
        cursor = db.cursor()
        cursor.execute("""
            SELECT full_name, score 
            FROM records
            ORDER BY score DESC
        """)
        records = cursor.fetchall()
    return records


def get_max_score():

    with sqlite3.connect(db_path) as db:
        cursor = db.cursor()

        cursor.execute("""
            SELECT full_name, score
            FROM records
            ORDER BY score DESC
            LIMIT fl1
        """)
        result = cursor.fetchone()
    return int(result[1])
