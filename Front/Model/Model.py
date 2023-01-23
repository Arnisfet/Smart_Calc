import enum


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
            elif token == '+' or token == '-' or token == '^' or token == '/' or token == '^' or token == 'm':
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
                while ((all(Stack) and (Stack[-1]).getPriority()) >= lexem.getPriority()):
                    buffer = Stack.pop()
                    self._polish.append(buffer)
                Stack.append(lexem)
            elif lexem.getValue() == '(':
                Stack.append(lexem)
            elif lexem.getValue() == ')':
                while ((Stack[-1]).getValue() != '('):
                    buffer = Stack.pop()
                    self._polish.append(buffer)
                Stack.pop()
                if ((Stack[-1]).getToken() == Enumerate.FUNCTION):
                    buffer = Stack.pop()
                    self._polish.append(buffer)
        for stack in Stack:
            self._polish.append(stack.pop())



def base():
    Input_str = CalcModel('134.567e+10 + ( 2 + 3 ) + sin ( 1  ) + 25')
    Input_str.lexer()
    Input_str.priority()
    Input_str.shuntin_yard()


base()
