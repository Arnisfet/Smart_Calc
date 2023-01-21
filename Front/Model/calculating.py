import re

class Tokens:
    def __init__(self, string):
        self.string = string
        self.lexem = ''
        self.priority = 0

    def lexer(self):
        tokens = self.string.split()
        print(type(tokens))



def base():
    Input_str = Tokens('1 + 2 + 3 / 4 + sin ( 12 ) - 8 + sin ( 1 )')
    Input_str.lexer()

base()