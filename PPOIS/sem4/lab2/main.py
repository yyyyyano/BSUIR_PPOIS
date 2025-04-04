from PPOIS.lab2.controllers.student_controller import StudentController
from PPOIS.lab2.view.student_view_gui import *

if __name__ == "__main__":

    app = QtWidgets.QApplication(sys.argv)
    controller = StudentController()
    gui = StudentViewGUI(controller)
    gui.show()
    sys.exit(app.exec_())
