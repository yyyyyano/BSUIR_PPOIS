import pytest
from ..models.date import Date
from ..models.human import Human


def test_human_initialization():
    date = Date(15, 6, 1990)
    person = Human("John", "Doe", date)

    assert person._Human__name == "John"
    assert person._Human__surname == "Doe"
    assert person._Human__bday == date


def test_human_str():
    date = Date(15, 6, 1990)
    person = Human("John", "Doe", date)

    expected_str = "Full name: Doe John \nBirthday: 15.6.1990"
    assert str(person) == expected_str


def test_full_name_property():
    date = Date(15, 6, 1990)
    person = Human("John", "Doe", date)

    expected_full_name = "Doe John"
    assert person.full_name == expected_full_name


def test_full_name_change():
    date = Date(15, 6, 1990)
    person = Human("John", "Doe", date)

    person._Human__name = "Jane"
    expected_full_name = "Doe Jane"
    assert person.full_name == expected_full_name
