
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
        self.ui.dub.clicked.connect(lambda: self.enter_dub(self.ui.dub.text()))
        self.ui.plus.clicked.connect(lambda: self.enter_operation(self.ui.plus.text()))
        self.ui.minus.clicked.connect(lambda: self.enter_operation(self.ui.minus.text()))
        self.ui.divivsion.clicked.connect(lambda: self.enter_operation(self.ui.divivsion.text()))
        self.ui.miltiply.clicked.connect(lambda: self.enter_operation(self.ui.miltiply.text()))
        self.ui.square.clicked.connect(lambda: self.enter_operation(self.ui.square.text()))
        self.ui.leftBR.clicked.connect(lambda: self.write_number(self.ui.leftBR.text()))
        self.ui.rightBR.clicked.connect(lambda: self.write_number(self.ui.rightBR.text()))
        self.ui.ln.clicked.connect(lambda: self.enter_function(self.ui.ln.text()))
        self.ui.log.clicked.connect(lambda: self.enter_function(self.ui.log.text()))
        self.ui.sqrt.clicked.connect(lambda: self.enter_function(self.ui.sqrt.text()))
        self.ui.sin.clicked.connect(lambda: self.enter_function(self.ui.sin.text()))
        self.ui.tg.clicked.connect(lambda: self.enter_function(self.ui.tg.text()))
        self.ui.mod.clicked.connect(lambda: self.enter_function(self.ui.mod.text()))
        self.ui.cos.clicked.connect(lambda: self.enter_function(self.ui.cos.text()))
        self.ui.atg.clicked.connect(lambda: self.enter_function(self.ui.atg.text()))
        self.ui.acos.clicked.connect(lambda: self.enter_function(self.ui.acos.text()))
        self.ui.asin.clicked.connect(lambda: self.enter_function(self.ui.asin.text()))
        self.ui.e.clicked.connect(lambda: self.enter_exp(self.ui.e.text()))
        self.ui.X_sign.clicked.connect(lambda: self.write_number(self.ui.X_sign.text()))
        self.ui.drop.clicked.connect(lambda: self.ui.label.setText(""))
        self.ui.result.clicked.connect(lambda: self.calculate())
        self.ui.droplast.clicked.connect(lambda: self.droplast())
        self.ui.unoper.clicked.connect(lambda: self.unar())

    def enter_dub(self, dub):
        list1 = (self.ui.label.text()).split()
        if len(list1) == 0:
            return
        check_oper = list1.pop()
        if check_oper.isdigit():
            self.ui.label.setText(self.ui.label.text() + dub)

    def enter_exp(self, exponent):
        operations = ['+', '-', '*', '/', 'ln', 'log', 'sqrt', '^', 'tg', 'cos', 'sin', 'asin', 'mod', 'atag', 'acos',
                      'e', '(', ')', 'X']
        list1 = (self.ui.label.text()).split()
        if len(list1) == 0:
            return
        check_oper = list1.pop()
        if check_oper.find('e') > 0:
            return
        for val in operations:
            if check_oper == val:
                return
        self.ui.label.setText(self.ui.label.text() + exponent)


    def enter_operation(self, operation):
        operations = ['+', '-', '*', '/', 'ln', 'log', 'sqrt', '^', 'tg', 'cos', 'sin', 'asin', 'mod', 'atag', 'acos', 'e', '(']
        list1 = (self.ui.label.text()).split()
        if len(list1) == 0:
            return
        check_oper = list1.pop()
        if check_oper == '0':
            return
        for val in operations:
            if check_oper == val:
                return
        if check_oper.find('e') > 0 and self._exp_flag == 0 and (operation == '+' or operation == '-'):
            self._exp_flag = 1
            self.ui.label.setText(self.ui.label.text() + operation)
            return
        operation = ' '+operation+' '
        self.write_number(operation)
        self._exp_flag = 0

    def enter_function(self, function):
        functions = ['+', '-', '*', '/', 'mod', '(']
        list1 = (self.ui.label.text()).split()
        if len(list1) == 0:
            self.write_number(function)
            return
        check_oper = list1.pop()
        if check_oper == '0':
            self.ui.label.setText(function)
        for val in functions:
            if check_oper == val:
                break
            else:
                return
        function = ' '+function+' '
        self.write_number(function)

    def unar(self):
        check1 = self.ui.label.text()
        list1 = check1.split()
        if len(list1) > 1 or len(list1) == 0:
            return
        if check1.find('-') != -1:
            newtext = check1[1:]
            self.ui.label.setText(newtext)
        else:
            self.ui.label.setText('-'+check1)

    def droplast(self):
        check1 = self.ui.label.text()
        list1 = check1.split()
        if len(list1) == 0:
            return
        list1.pop()
        check1 = ' '.join(list1)
        self.ui.label.setText(check1 + ' ')

    def calculate(self):
        text = self.ui.XText.toPlainText()
        if text.isdigit():
            Model = CalcModel(self.ui.label.text(), text)
        else:
            Model = CalcModel(self.ui.label.text())
        Model.lexer()
        Model.priority()
        Model.shuntin_yard()
        res_value = Model.calc_polish()
        self.ui.label.setText(res_value)

    def write_number(self, number):
        # Метод по помещению строки в поле ввода
        if self.ui.label.text() == "0":
            self.ui.label.setText(number)
        else:
            self.ui.label.setText(self.ui.label.text() +number)