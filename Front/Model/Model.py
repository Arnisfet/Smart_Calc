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

    def add_value(self, value, token):
        self._value = value
        self._token = token

    def getValue(self):
        """ Геттер лежащего значения """
        return self._value

    def getToken(self):
        """ Геттер лежащего токена """
        return self._token


class CalcModel:
    def __init__(self, string):
        self.input_string = string
        self._lexems = list()

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
        for lex in self._lexems:
            print(lex.getValue(), lex.getToken())

    def priority(self):
        """ Формирование приоритета значений для постфиксной нотации """
        pass

def base():
    Input_str = CalcModel('134.567e+10 + ( 2 + 3 ) + sin ( 1  ) + 25')
    Input_str.lexer()


base()
