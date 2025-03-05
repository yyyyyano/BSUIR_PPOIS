import pytest
import time
import subprocess
from unittest.mock import patch
from ..models.mouse import Mouse

def test_mouse_initialization():
    mouse = Mouse("Jerry")
    assert mouse.name == "Jerry"

@patch("time.sleep", return_value=None)
@patch("subprocess.Popen")
def test_mouse_dance(mock_popen, mock_sleep, capsys):
    mouse = Mouse("Jerry")
    mouse.dance()
    captured = capsys.readouterr()
    assert "Oh no... Mouse Jerry is here..." in captured.out

    mock_popen.assert_called_once_with([
        "C:\\Program Files\\Windows Media Player\\wmplayer.exe",
        "C:\\Users\\Bankevich\\Downloads\\dancing_mouse.mp4"
    ])

    mock_sleep.assert_called_once_with(5)
