from ctypes import *


def calc():
    adder = CDLL('./libshuntin.so')
    i = adder.result()
    print(i)


calc()
