from PyQt5.QtWidgets import QApplication, QWidget
from PyQt5 import uic
from Front.Presenter.Presenter import Presenter


class App(QWidget):
    def __init__(self):
        self.ui = None
        self.start()
        self.controller = Presenter(self.ui)

    def start(self):

        self.ui = uic.loadUi("View/mainwindow.ui")
        self.ui.show()
