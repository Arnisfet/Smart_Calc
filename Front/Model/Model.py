import enum
from math import *


class Enumerate(enum.Enum):
    NUMBER = 1
    OPERATION = 2
    FUNCTION = 3
    BRACKET = 4


class Lexems:
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
    def __init__(self, string):
        self.input_string = string
        self._lexems = list()
        self._polish = list()
        self.result = list()

    # def postfix(self):

    def lexer(self):
        """ Функция делит полученную строку на лексемы, данные разбиваются, и кладутся в список классов Лексем"""
        self.tokens = self.input_string.split()
        for token in self.tokens:
            lexema = Lexems()
            if token == 'acos' or token == 'asin' or token == 'atan' or token == 'cos' or token == 'sin' \
                    or token == 'tan' or token == 'ln' or token == 'log' or token == 'sqrt':
                lexema.add_value(token, Enumerate.FUNCTION)
                # value = token[:token.find('e')]
                # pow = token[token.find('e')+1:]
                # result = float(value) * (10 ** float(pow))
                # self._lexems.add()
                # print(pow, value, result)
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
        for value in self._polish:
            if value.getToken() == Enumerate.NUMBER:
                self.result.append(float(value.getValue()))
            elif value.getToken() == Enumerate.OPERATION or value.getToken() == Enumerate.FUNCTION:
                if value.getToken() == Enumerate.OPERATION:
                    if value.getValue() == '+':
                        self.result.append(self.result.pop() + self.result.pop())
                    elif value.getValue() == '-':
                        self.result.append(-(self.result.pop() - self.result.pop()))
                    elif value.getValue() == '*':
                        self.result.append(self.result.pop()*self.result.pop())
                    elif value.getValue() == '/':
                        first = self.result.pop()
                        second = self.result.pop()
                        self.result.append(second / first)
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
                    elif value.getValue() == 'tan':
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
        print(self.result)

def base():
    Input_str = CalcModel('49 - 8 - 50 - 800 + log ( 12 ) - tan ( 99 ) + cos ( sin ( 8 ) )')
    Input_str.lexer()
    Input_str.priority()
    Input_str.shuntin_yard()
    Input_str.calc_polish()


base()
