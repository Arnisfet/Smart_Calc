# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'mainwindow.ui'
#
# Created by: PyQt5 UI code generator 5.9.2
#
# WARNING! All changes made in this file will be lost!
#
# Проект SmartCalc реализован с использованием Qt5 на паттерне MVP

from PyQt5 import QtWidgets
from src.View.View import App

import sys
import os

if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    View = App()
    app.exec_()