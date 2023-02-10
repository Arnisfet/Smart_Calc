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
        self.ui.cleargraph.clicked.connect(lambda: self.ui.graph.clear())
        self.ui.copy.clicked.connect(lambda: self.ui.functionlab.setText(self.ui.label.text()))

    def calculate_graph(self):
        y = []
        x = []
        res_value = 0.
        try:
            xmin = float(self.ui.xminval.toPlainText())
            xmax = float(self.ui.xmaxval.toPlainText())
            accur = float(self.ui.accur.toPlainText())
        except ValueError:
            self.ui.Error.setText('Error: The incorrect values!!!')
            return None
        iter = xmin
        while iter < 100000 and iter <= xmax and iter > -100000 and iter >= xmin:
            Model = GraphModel(self.ui.functionlab.text(), str(iter))
            Model.lexer()
            Model.priority()
            Model.shuntin_yard()
            try:
                res_value = float(Model.calc_polish())
            except ValueError:
                iter += accur
                continue
            except Exception:
                self.ui.Error.setText('Error: The incorrect formula')
                return None
            y.append(res_value)
            x.append(iter)
            iter += accur
        print(x, y)
        self.ui.graph.plot(x, y)
        self.ui.Error.setText('')