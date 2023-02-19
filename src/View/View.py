from PyQt5.QtWidgets import QApplication, QWidget, QMainWindow
from PyQt5 import uic
from Front.Presenter.Presenter import Presenter
from Front.Presenter.GraphPresenter import GraphPresenter


class App(QMainWindow):
    def __init__(self):
        super(App, self).__init__()
        self.ui = None
        self.start()
        self.presenter = Presenter(self.ui)
        self.graph_presenter = GraphPresenter(self.ui)

    def start(self):

        self.ui = uic.loadUi("View/mainwindow.ui")

        self.ui.show()

