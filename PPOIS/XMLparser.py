import xml.dom.minidom as minidom
import xml.sax


class XMLWriter:
    @staticmethod
    def save_to_file(students, file_path):
        doc = minidom.Document()

        root = doc.createElement("students")
        doc.appendChild(root)

        for student in students:
            student_element = doc.createElement("student")

            id_element = doc.createElement("id")
            id_element.appendChild(doc.createTextNode(str(student[0])))
            student_element.appendChild(id_element)

            fields = ["full_name", "course", "group", "number_of_works", "made_works", "programming_language"]
            for tag, value in zip(fields, student[1:]):
                field_element = doc.createElement(tag)
                field_element.appendChild(doc.createTextNode(str(value)))
                student_element.appendChild(field_element)

            root.appendChild(student_element)

        with open(file_path, "w", encoding="utf-8") as file:
            file.write(doc.toprettyxml(indent="    ", encoding="utf-8").decode("utf-8"))



class XMLReader(xml.sax.ContentHandler):
    def __init__(self):
        super().__init__()
        self.students = []
        self.current_data = ""
        self.current_student = {}
        self.current_field = ""


    def startElement(self, tag, attributes):
        self.current_data = tag
        if tag == "student":
            self.current_student = {}


    def characters(self, content):
        if self.current_data:
            self.current_field = content.strip()


    def endElement(self, tag):
        if tag == "student":
            self.students.append(
                (
                    int(self.current_student.get("id", 0)),
                    self.current_student.get("full_name", ""),
                    self.current_student.get("course", ""),
                    int(self.current_student.get("group", 0)),
                    int(self.current_student.get("number_of_works", 0)),
                    int(self.current_student.get("made_works", 0)),
                    self.current_student.get("programming_language", "")
                )
            )
            self.current_student = {}
        elif tag != "students":
            if self.current_data:
                self.current_student[tag] = self.current_field

        self.current_data = ""
