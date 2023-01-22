# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'mainwindow.ui'
#
# Created by: PyQt5 UI code generator 5.9.2
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtWidgets

# from Front.Controller.viewmodel import ViewModel
from Front.View.buttons import App


if __name__ == "__main__":
    import sys

    app = QtWidgets.QApplication(sys.argv)
    View = App()
    app.exec_()
