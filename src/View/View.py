from PyQt5.QtWidgets import QApplication, QWidget, QMainWindow
from PyQt5 import uic
from ..Presenter.Presenter import Presenter
from ..Presenter.GraphPresenter import GraphPresenter


class App(QMainWindow):
    def __init__(self):
        super(App, self).__init__()
        self.ui = None
        self.start()
        self.presenter = Presenter(self.ui)
        self.graph_presenter = GraphPresenter(self.ui)

    def start(self):

        self.ui = uic.loadUi("/home/arnisfet/Desktop/Smart_Calc/src/View/mainwindow.ui")

        self.ui.show()

