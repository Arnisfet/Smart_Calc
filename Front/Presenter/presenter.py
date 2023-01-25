
from ..Model.Model import *


class Controller:
    def __init__(self, ui):
        self._dub_flag = 0
        self._exp_flag = 0
        self.ui = ui
        self.add_functions()

    def add_functions(self):
        self.ui.button1.clicked.connect(lambda: self.write_number(self.ui.button1.text()))
        self.ui.button2.clicked.connect(lambda: self.write_number(self.ui.button2.text()))
        self.ui.button3.clicked.connect(lambda: self.write_number(self.ui.button3.text()))
        self.ui.button4.clicked.connect(lambda: self.write_number(self.ui.button4.text()))
        self.ui.button5.clicked.connect(lambda: self.write_number(self.ui.button5.text()))
        self.ui.button6.clicked.connect(lambda: self.write_number(self.ui.button6.text()))
        self.ui.button7.clicked.connect(lambda: self.write_number(self.ui.button7.text()))
        self.ui.button8.clicked.connect(lambda: self.write_number(self.ui.button8.text()))
        self.ui.button9.clicked.connect(lambda: self.write_number(self.ui.button9.text()))
        self.ui.zero.clicked.connect(lambda: self.write_number(self.ui.zero.text()))
        self.ui.dub.clicked.connect(lambda: self.write_number(self.ui.dub.text()))
        self.ui.plus.clicked.connect(lambda: self.write_number(self.ui.plus.text()))
        self.ui.minus.clicked.connect(lambda: self.write_number(self.ui.minus.text()))
        self.ui.divivsion.clicked.connect(lambda: self.write_number(self.ui.divivsion.text()))
        self.ui.miltiply.clicked.connect(lambda: self.write_number(self.ui.miltiply.text()))
        self.ui.square.clicked.connect(lambda: self.write_number(self.ui.square.text()))
        self.ui.leftBR.clicked.connect(lambda: self.write_number(self.ui.leftBR.text()))
        self.ui.rightBR.clicked.connect(lambda: self.write_number(self.ui.rightBR.text()))
        self.ui.ln.clicked.connect(lambda: self.write_number(self.ui.ln.text()))
        self.ui.log.clicked.connect(lambda: self.write_number(self.ui.log.text()))
        self.ui.sqrt.clicked.connect(lambda: self.write_number(self.ui.sqrt.text()))
        self.ui.sin.clicked.connect(lambda: self.write_number(self.ui.sin.text()))
        self.ui.tg.clicked.connect(lambda: self.write_number(self.ui.tg.text()))
        self.ui.mod.clicked.connect(lambda: self.write_number(self.ui.mod.text()))
        self.ui.cos.clicked.connect(lambda: self.write_number(self.ui.cos.text()))
        self.ui.atg.clicked.connect(lambda: self.write_number(self.ui.atg.text()))
        self.ui.acos.clicked.connect(lambda: self.write_number(self.ui.acos.text()))
        self.ui.asin.clicked.connect(lambda: self.write_number(self.ui.asin.text()))
        self.ui.e.clicked.connect(lambda: self.write_number(self.ui.e.text()))
        self.ui.X_sign.clicked.connect(lambda: self.write_number(self.ui.X_sign.text()))
        self.ui.drop.clicked.connect(lambda: self.ui.label.setText(""))
        self.ui.result.clicked.connect(lambda: self.calculate())

    def calculate(self):
        text = self.ui.XText.toPlainText()
        if text.isdigit():
            Model = CalcModel(self.ui.label.text(), text)
        else:
            Model = CalcModel(self.ui.label.text())
        Model.lexer()
        Model.priority()
        Model.shuntin_yard()
        Model.calc_polish()
        self.ui.label.setText(Model.getValue())
    def write_number(self, number):
        # Метод по помещению строки в поле ввода
        if self.ui.label.text() == "0":
            self.ui.label.setText(number)
        elif number.isdigit():
            self.ui.label.setText(self.ui.label.text() + number)

        elif number == '.' and self._dub_flag == 0:
            self.ui.label.setText(self.ui.label.text() + number)
            self._dub_flag = 1
        elif number == 'e' and self._exp_flag == 0:
            self.ui.label.setText(self.ui.label.text() + number)
            self._exp_flag = 1
        elif (number == '.' and self._dub_flag == 1) or (number == 'e' and self._exp_flag == 1):
            return
        else:
            if self._exp_flag == 1 and (number == '-' or number == '+'):
                self.ui.label.setText(self.ui.label.text() + number)
                self._exp_flag = 0
            else:
                self.ui.label.setText(self.ui.label.text() + ' ' + number + ' ')
                self._dub_flag = 0
                self._exp_flag = 0
