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

    def sum(self, *args):

        return reduce(self.__add__, args)

    def scala_multiply(self, value):

        self.x = self.x * value
        self.y = self.y * value

    