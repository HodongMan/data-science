import re, math, random
from collections import defaultdict, Counter
from functools import partial, reduce

import matplotlib.pyplot as plt


class Vector:

    def __init__(self, x, y):
        
        self.x = x
        self.y = y

    def __add__(self, other):
        
        '''
            add Vector
        '''

        if not isinstance(other, Vector):
            return NotImplemented

        result = Vector(self.x + other.x, self.y + other.y)

        return result

    def __sub__(self, other):
        
        '''
            sub Vector
        '''

        if not isinstance(other, Vector):
            return NotImplemented

        result = Vector(self.x - other.x, self.y - other.y)

        return result

    def print_vector(self):

        print(self.x, self.y)

    def get_list(self):

        return [self.x, self.y]

    def sum(self, *args):

        return reduce(self.__add__, args)

    def scala_multiply(self, value):

        self.x = self.x * value
        self.y = self.y * value

    def dot(self, other):

        if not isinstance(other, Vector):
            return NotImplemented

        return sum([self.x * other.x, self.y * other.y])
        #return sum(self_i * other_i for self_i, other_i in zip())
        



def vector_sum(vectors):

    return reduce(vectors.__add__, vectors)

def vector_mean(vectors):

    n = len(vectors)

    return vector_sum(vectors).scala_multiply(1/n)

def make_graph_dot_product_as_vector_projection(plt):

    vector = Vector(2, 1)
    w = Vector(math.sqrt(.25), math.sqrt(.75))
    c = vector.dot(w)

    vonw = vector.scala_multiply(c)
    o = [0, 0]

    plt.arrow(0, 0, vector.x, vector.y,
              width=0.002, head_width=.1, length_includes_head=True)
    plt.annotate("v", vector.get_list(), xytext=[vector.x + 0.1, vector.y])
    plt.arrow(0 ,0, w.x, w.y,
              width=0.002, head_width=.1, length_includes_head=True)
    plt.annotate("w", w.get_list(), xytext=[w.x - 0.1, w.y])
    plt.arrow(0, 0, vonw.x, vonw.y, length_includes_head=True)
    plt.annotate(u"(v•w)w", vonw, xytext=[vonw.x - 0.1, vonw.y + 0.1])
    plt.arrow(vector.x, vector.y, vonw.x - vector.x, vonw.y - vector.y,
              linestyle='dotted', length_includes_head=True)
    plt.scatter(*zip(vector.get_list(),w.get_list(),o),marker='.')
    plt.axis('equal')
    plt.show()



if __name__ == "__main__":

    make_graph_dot_product_as_vector_projection(plt)