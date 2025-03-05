import subprocess
import time
class Mouse:
    def __init__(self, name: str):
        self.name = name


    def dance(self):
        print(f"Oh no... Mouse {self.name} is here...")
        time.sleep(5)
        subprocess.Popen(["C:\\Program Files\\Windows Media Player\\wmplayer.exe",
                          "C:\\Users\\Bankevich\\Downloads\\dancing_mouse.mp4"])

