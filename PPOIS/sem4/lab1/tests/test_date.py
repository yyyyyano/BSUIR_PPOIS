import pytest
from ..models.date import Date

def test_valid_date():
    date = Date(15, 6, 2023)
    assert str(date) == "15.6.2023"

def test_invalid_day():
    with pytest.raises(ValueError, match="Invalid date: 32.1.2023"):
        Date(32, 1, 2023)

def test_invalid_month():
    with pytest.raises(ValueError, match="Invalid date: 10.13.2023"):
        Date(10, 13, 2023)

def test_invalid_year():
    with pytest.raises(ValueError, match="Invalid date: 10.5.1800"):
        Date(10, 5, 1800)

def test_leap_year():
    date = Date(29, 2, 2024)
    assert str(date) == "29.2.2024"

def test_non_leap_year():
    with pytest.raises(ValueError, match="Invalid date: 29.2.2023"):
        Date(29, 2, 2023)

def test_min_boundary_year():
    with pytest.raises(ValueError, match="Invalid date: 1.1.1900"):
        Date(1, 1, 1900)

def test_max_boundary_year():
    with pytest.raises(ValueError, match="Invalid date: 31.12.2025"):
        Date(31, 12, 2025)
