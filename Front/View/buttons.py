from PyQt5.QtWidgets import QApplication, QWidget
from PyQt5 import uic
from Front.Presenter.presenter import Controller


class App(QWidget):
    def __init__(self):
        self.ui = None
        self.start()
        self.controller = Controller(self.ui)


    def start(self):
        self.ui = uic.loadUi("mainwindow.ui")
        self.ui.show()
