import pytest
from ..models.table import Table

def test_table_initialization():
    table = Table()
    assert table.table_number == 12
    assert table.need_cleaning is False
    assert str(table) == "Table #12 with capacity 6. Merged tables: [12]"

def test_table_occupy():
    table = Table()
    table.occupy(4)
    assert table.need_cleaning is True

def test_table_occupy_more_people():
    table = Table()
    table.occupy(14)
    expect_str=f"Tables {table._Table__merged_tables} have been merged into one table #{table._Table__table_number}"
    assert table.need_cleaning is True


def test_table_increase_capacity():
    table = Table()
    table.increase_capacity(14)
    assert table._Table__merged_tables==table._Table__merged_tables

def test_table_merge():
    table1 = Table()
    table2 = Table()
    table1._Table__merge_tables(table2)
    assert table1.table_number in table2._Table__merged_tables
    assert table2.table_number in table1._Table__merged_tables

def test_table_need_cleaning_setter():
    table = Table()
    table.need_cleaning = True
    assert table.need_cleaning is True

