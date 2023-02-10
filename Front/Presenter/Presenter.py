from ..Model.Model import *
from PyQt5.QtWidgets import QMessageBox
from pyqtgraph import PlotWidget, plot
from math import *


class Presenter:
    """Класс презентер, занимается принятием сигнала от View и передает данные внутр модели
    при условии запуска расчета"""

    def __init__(self, ui):
        self._dub_flag = 0
        self._exp_flag = 0
        self.ui = ui
        self.leftbr = 0
        self.rightbr = 0
        self.ui.label.setWordWrap(True)
        self.history_point = 0
        self.read_history()
        self.history_point = sum(1 for line in open("../History.txt")) - 1
        self.add_functions()

    def add_functions(self):
        """Метод отлова клавиш из вью"""
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
        self.ui.leftBR.clicked.connect(lambda: self.enter_bracket(self.ui.leftBR.text()))
        self.ui.rightBR.clicked.connect(lambda: self.enter_bracket(self.ui.rightBR.text()))
        self.ui.ln.clicked.connect(lambda: self.enter_function(self.ui.ln.text()))
        self.ui.log.clicked.connect(lambda: self.enter_function(self.ui.log.text()))
        self.ui.sqrt.clicked.connect(lambda: self.enter_function(self.ui.sqrt.text()))
        self.ui.sin.clicked.connect(lambda: self.enter_function(self.ui.sin.text()))
        self.ui.tg.clicked.connect(lambda: self.enter_function(self.ui.tg.text()))
        self.ui.mod.clicked.connect(lambda: self.enter_operation(self.ui.mod.text()))
        self.ui.cos.clicked.connect(lambda: self.enter_function(self.ui.cos.text()))
        self.ui.atg.clicked.connect(lambda: self.enter_function(self.ui.atg.text()))
        self.ui.acos.clicked.connect(lambda: self.enter_function(self.ui.acos.text()))
        self.ui.asin.clicked.connect(lambda: self.enter_function(self.ui.asin.text()))
        self.ui.e.clicked.connect(lambda: self.enter_exp(self.ui.e.text()))
        self.ui.X_sign.clicked.connect(lambda: self.enter_x(self.ui.X_sign.text()))
        self.ui.drop.clicked.connect(lambda: self.ui.label.setText("0"))
        self.ui.result.clicked.connect(lambda: self.calculate())
        self.ui.droplast.clicked.connect(lambda: self.droplast())
        self.ui.unoper.clicked.connect(lambda: self.unar())
        self.ui.history_clean.clicked.connect(lambda: self.clean_history())
        self.ui.up.clicked.connect(lambda: self.up_history())
        self.ui.down.clicked.connect(lambda: self.down_history())
        self.ui.load.clicked.connect(lambda: self.load_history())

    def up_history(self):
        if self.history_point > 0:
            self.history_point -= 1
        f = open("../History.txt")
        line = f.read().split('\n')[self.history_point]
        if line != '\n' or line != '':
            self.ui.history.setText(line)
        f.close()

    def down_history(self):
        if self.history_point < (sum(1 for line in open("../History.txt")) - 1):
            self.history_point += 1
        f = open("../History.txt")
        line = f.read().split('\n')[self.history_point]
        if line != '\n' or line != '':
            self.ui.history.setText(line)
        f.close()

    def clean_history(self):
        f = open("../History.txt", 'w')
        f.close()
        self.history_point = 0
        self.read_history()

    def load_history(self):
        self.ui.label.setText(self.ui.history.text())

    def enter_bracket(self, bracket):
        """Функция для ввода скобок"""
        self.check_error()
        list1 = (self.ui.label.text()).split()
        if len(list1) == 0:
            self.write_number(bracket)
            return
        check_oper = list1.pop()
        if bracket == '(':
            self.leftbr += 1
        else:
            self.rightbr += 1
        if check_oper == '0':
            self.ui.label.setText(bracket + ' ')
        elif (check_oper.isdigit() or check_oper == 'X') and bracket == '(':
            return
        elif check_oper.find('.') > 0 or check_oper.find('e') > 0:
            return
        elif check_oper == '(' and bracket == ')':
            return
        else:
            self.ui.label.setText(self.ui.label.text() + ' ' + bracket + ' ')

    def enter_x(self, x):
        """Функция для ввода икса"""
        self.check_error()
        functions = ['+', '-', '*', '/', 'mod', '(']
        list1 = (self.ui.label.text()).split()
        if len(list1) == 0:
            self.write_number(x)
            return
        check_oper = list1.pop()
        if check_oper == '0':
            self.ui.label.setText(x)
        elif check_oper == 'X':
            return
        for func in functions:
            if check_oper == func:
                operation = ' ' + x + ' '
                self.write_number(operation)

    def enter_dub(self, dub):
        """Функция для ввода точки"""
        self.check_error()
        list1 = (self.ui.label.text()).split()
        if len(list1) == 0:
            return
        check_oper = list1.pop()
        if check_oper.isdigit():
            self.ui.label.setText(self.ui.label.text() + dub)

    def enter_exp(self, exponent):
        """Функция для ввода экспоненты"""
        self.check_error()
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
        """Функция для вставки операторов"""
        self.check_error()
        operations = ['+', '-', '*', '/', 'ln', 'log', 'sqrt', '^', 'tg', 'cos', 'sin', 'asin', 'mod', 'atag', 'acos',
                      'e', '(']
        list1 = (self.ui.label.text()).split()
        if len(list1) == 0:
            return
        check_oper = list1.pop()
        if check_oper == '0':
            return
        for val in operations:
            if check_oper == val:
                return
            # специальные условия для ввода операторов в экспоненциальных выражениях
        if check_oper.find('e') > 0 and self._exp_flag == 0 and check_oper.find('+') < 0 \
                and (operation == '+' or operation == '-'):
            self._exp_flag = 1
            self.ui.label.setText(self.ui.label.text() + operation)
            return
        operation = ' ' + operation + ' '
        self.write_number(operation)
        self._exp_flag = 0

    def enter_function(self, function):
        self.check_error()
        """Функция для вставки функций внутрь выражения"""
        functions = ['+', '-', '*', '/', 'mod', '(']
        list1 = (self.ui.label.text()).split()
        if len(list1) == 0:
            self.write_number(function)
            return None
        check_oper = list1.pop()
        if check_oper == '0':
            self.ui.label.setText(function)
        for val in functions:
            if check_oper == val:
                function = ' ' + function + ' '
                self.write_number(function)
                break

    def unar(self):
        self.check_error()
        """Функция обрабатывающая унарный плюс и унарный минус"""
        check1 = self.ui.label.text()
        list1 = check1.split()
        if len(list1) > 1 or len(list1) == 0:
            return
        if check1.find('-') != -1:
            newtext = check1[1:]
            self.ui.label.setText(newtext)
        else:
            self.ui.label.setText('-' + check1)

    def droplast(self):
        self.check_error()
        """ Функция удаляющая последний введенный токен"""
        check1 = self.ui.label.text()
        list1 = check1.split()
        if len(list1) == 0:
            return
        list1.pop()
        if len(list1) == 0:
            self.ui.label.setText("0")
            return
        else:
            check1 = ' '.join(list1)
        self.ui.label.setText(check1 + ' ')

    def calculate(self):
        """ Функция связи презентера и модели. Основная функция: передача данных в модель и получение значения.
        Так же занимается проверкой эксепшенов во всей модели"""
        text = self.ui.XText.toPlainText()
        # Вот это говно конечно со скобочками...
        if self.leftbr != self.rightbr:
            self.ui.label.setText("Error: The odd number of brackets")
            self.rightbr = 0
            self.leftbr = 0
            return
        try:
            num = float(text)
            Model = CalcModel(self.ui.label.text(),
                              text)  # Вызов конструктора модели при условии что есть значения для х.
        except:
            Model = CalcModel(self.ui.label.text())
        self.history_point += 1
        self.read_history()
        Model.lexer()
        Model.priority()
        Model.shuntin_yard()
        try:
            res_value = Model.calc_polish()
        except Exception:
            self.ui.label.setText('Error: The incorrect formula')
        else:
            self.ui.label.setText(res_value + ' ')

    def read_history(self):
        # Работа с записью истории в лейбл
        line = 0
        try:
            read_f = open("../History.txt", 'r')
        except IOError:
            error = QMessageBox()
            error.setWindowTitle("Error")
            error.setText("The history file was recreated!")
            error.setStandardButtons(QMessageBox.Ok)
            error.exec_()
            read_f = open("../History.txt", 'w')
            read_f.close()
        else:
            if self.history_point >= 0:
                line = read_f.read().split('\n')[sum(1 for line in open("../History.txt")) - 1]
            if line:
                self.ui.history.setText(line)
            else:
                self.ui.history.setText("")
            read_f.close()

    def write_number(self, number):
        """Функция записи цифр"""
        self.check_error()
        # Условие при котором мы затираем поле если в конце расчета получили ошибку
        if self.ui.label.text() == "0" or self.ui.label.text() == 'Error: Zero Division ' or self.ui.label.text() == "Error: The odd number of brackets" \
                or self.ui.label.text() == "Error: The incorrect formula":
            self.ui.label.setText(number)
        else:
            self.ui.label.setText(self.ui.label.text() + number)

    def check_error(self):
        error = QMessageBox()
        error.setWindowTitle("Error")
        list1 = (self.ui.label.text()).split()
        check_len = list()
        if len(list1) > 0:
            check_len = list1.pop()
        if len(self.ui.label.text()) > 255:
            error.setText("You can't put more than 250 symbols in one calc iteration!")
            error.setStandardButtons(QMessageBox.Ok)
            error.exec_()
        elif len(check_len) > 49:
            error.setText(
                "Sorry, but you can't put an argument with size more than 50 symbols.\n Please, try to use an "
                "exponential form for big numbers!")
            error.setStandardButtons(QMessageBox.Ok)
            error.exec_()
