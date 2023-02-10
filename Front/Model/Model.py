import enum
from math import *
from decimal import getcontext
from decimal import Decimal


class Enumerate(enum.Enum):
    NUMBER = 1
    OPERATION = 2
    FUNCTION = 3
    BRACKET = 4


class Lexems:
    """Класс являющийся полем для основного класса Модели. Основные поля:
    value - значение, token - enum элемент для лучшей читаемости кода,
    priority - приоритет вычесления элемента, при условии что токен - действие, а не число"""
    def __init__(self):
        self._value = 0
        self._token = 0
        self._priority = 0

    # Getter part
    def add_value(self, value, token):
        self._value = value
        self._token = token

    def getValue(self):
        """ Геттер лежащего значения """
        return self._value

    def getToken(self):
        """ Геттер лежащего токена """
        return self._token

    def getPriority(self):
        return self._priority

    # Setter part
    def setPriority(self, priority):
        self._priority = priority


class CalcModel:
    """Основной класс расчетной модели (без графика).
    Основные поля: input_string - входная строка,
    xvalue - х значение в выражении,
    _lexems - лист с лексемами класса лексем
    _polish - лист (стек) с классами лексема но отсоритрованный по shunting yard
    result - финальный список для обработки польской нотации"""
    def __init__(self, string, xvalue=''):
        self.input_string = string
        self.FileManagment()
        self.xvalue = xvalue
        self._lexems = list()
        self._polish = list()
        self.result = list()

    def FileManagment(self):
        history_f = open("../History.txt", 'a')
        history_f.write(self.input_string + '\n')
        history_f.close()

    def getValue(self):
        return str(self.result.pop())

    def lexer(self):
        """ Функция делит полученную строку на лексемы, данные разбиваются, и кладутся в список классов Лексем"""
        self.tokens = self.input_string.split()
        for token in self.tokens:
            lexema = Lexems()
            if token.find('X') >= 0:
                    token = self.xvalue
            if token == 'acos' or token == 'asin' or token == 'atan' or token == 'cos' or token == 'sin' \
                     or token == 'ln' or token == 'log' or token == 'sqrt' or token == 'tg':
                lexema.add_value(token, Enumerate.FUNCTION)
                self._lexems.append(lexema)
            elif token == '(' or token == ')':
                lexema.add_value(token, Enumerate.BRACKET)
                self._lexems.append(lexema)
            elif token == '+' or token == '-' or token == '^' or token == '/' or token == '^' or token == 'mod' or token == '*':
                lexema.add_value(token, Enumerate.OPERATION)
                self._lexems.append(lexema)
            else:
                lexema.add_value(token, Enumerate.NUMBER)
                self._lexems.append(lexema)

    def priority(self):
        """ Формирование приоритета значений для постфиксной нотации:
         числа и скобки имеют самый низкий приоритет, + и минус имеют 1 приоритет
         * / и остаток от деления имеют 2 приоритет, возведение в степень 3 и функции 4"""
        for lexem in self._lexems:
            if lexem.getValue() == '+' or lexem.getValue() == '-':
                lexem.setPriority(1)
            elif lexem.getValue() == '*' or lexem.getValue() == '/' or lexem.getValue() == 'mod':
                lexem.setPriority(2)
            elif lexem.getValue() == '^':
                lexem.setPriority(3)
            elif lexem.getToken() == Enumerate.FUNCTION:
                lexem.setPriority(4)
            else:
                lexem.setPriority(0)
            print(lexem.getValue(), lexem.getToken(), lexem.getPriority())

    def shuntin_yard(self):
        """Алгоритм сортировочной станции"""
        Stack = list()
        for lexem in self._lexems:
            if lexem.getToken() == Enumerate.NUMBER:
                self._polish.append(lexem)
            elif lexem.getToken() == Enumerate.FUNCTION:
                Stack.append(lexem)
            elif lexem.getToken() == Enumerate.OPERATION:
                while Stack and (Stack[len(Stack) - 1]).getPriority() >= lexem.getPriority():
                    buffer = Stack.pop()
                    self._polish.append(buffer)
                Stack.append(lexem)
            elif lexem.getValue() == '(':
                Stack.append(lexem)
            elif lexem.getValue() == ')':
                while Stack and (Stack[len(Stack) - 1]).getValue() != '(':
                    buffer = Stack.pop()
                    self._polish.append(buffer)
                Stack.pop()
                if Stack and (Stack[len(Stack) - 1]).getToken() == Enumerate.FUNCTION:
                    buffer = Stack.pop()
                    self._polish.append(buffer)
        while Stack:
            self._polish.append(Stack.pop())
        for check in self._polish:
            print(check.getValue())

    def calc_polish(self):
        """Алгоритм расчета значения из польской нотации"""
        getcontext().prec = 10
        for value in self._polish:
            if value.getToken() == Enumerate.NUMBER:
                self.result.append(Decimal(value.getValue()))
            elif value.getToken() == Enumerate.OPERATION or value.getToken() == Enumerate.FUNCTION:
                if value.getToken() == Enumerate.OPERATION:
                    if value.getValue() == '+':
                        checker = self.result.pop() + self.result.pop()
                        print(checker)
                        self.result.append(checker)
                    elif value.getValue() == '-':
                        checker = -(self.result.pop() - self.result.pop())
                        self.result.append(checker)
                    elif value.getValue() == '*':
                        checker = self.result.pop()*self.result.pop()
                        print(checker)
                        self.result.append(checker)
                    elif value.getValue() == '/':
                        first = self.result.pop()
                        second = self.result.pop()
                        try:
                            checker = second / first
                        except ZeroDivisionError:
                            return 'Error: Zero Division'
                        else:
                            self.result.append(checker)
                    elif value.getValue() == '^':
                        first = self.result.pop()
                        second = self.result.pop()
                        self.result.append(second ** first)
                    elif value.getValue() == 'mod':
                        first = self.result.pop()
                        second = self.result.pop()
                        self.result.append(second % first)
                else:
                    if value.getValue() == 'sin':
                        self.result.append(sin(self.result.pop()))
                    elif value.getValue() == 'cos':
                        self.result.append(cos(self.result.pop()))
                    elif value.getValue() == 'tg':
                        self.result.append(tan(self.result.pop()))
                    elif value.getValue() == 'asin':
                        self.result.append(asin(self.result.pop()))
                    elif value.getValue() == 'acos':
                        self.result.append(acos(self.result.pop()))
                    elif value.getValue() == 'atan':
                        self.result.append(atan(self.result.pop()))
                    elif value.getValue() == 'log':
                        self.result.append(log10(self.result.pop()))
                    elif value.getValue() == 'ln':
                        self.result.append(log(self.result.pop()))
                    elif value.getValue() == 'sqrt':
                        self.result.append(sqrt(self.result.pop()))
        endres = self.result.pop()
        if str(endres)[str(endres).find('.')+1:] == '0':
            return str(int(endres))
        return str(endres)



# def base():
#     Input_str = CalcModel('49 - 8 - 50 - 800 + log ( 12 ) - tan ( 99 ) + cos ( sin ( 8 ) )')
#     Input_str.lexer()
#     Input_str.priority()
#     Input_str.shuntin_yard()
#     Input_str.calc_polish()


# base()
