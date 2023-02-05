from ..Model.GraphModel import GraphModel
from math import *
class GraphPresenter:
    """Класс презентер, занимается принятием сигнала от View и передает данные внутр модели
    при условии запуска расчета"""

    def __init__(self, ui):
        self.ui = ui
        self.ui.label.setWordWrap(True)
        self.add_functions()

    def add_functions(self):
        """Метод отлова клавиш из вью"""
        self.ui.graph_button.clicked.connect(lambda: self.calculate_graph())

    def calculate_graph(self):
        y = []
        x = []
        res_value = 0.
        iter = -10000
        res = log(-1000)
        while iter < 10000:
            Model = GraphModel(self.ui.label.text(), str(iter))
            Model.lexer()
            Model.priority()
            Model.shuntin_yard()
            try:
                res_value = float(Model.calc_polish())
            except Exception:
                self.ui.label.setText('Error: The incorrect formula')
            y.append(res_value)
            x.append(iter)
            iter += 0.1
        self.ui.graph.plot(x, y)