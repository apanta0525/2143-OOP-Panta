
import random

class Die:
    def __init__(self, sides=6):
        self.sides = sides

    def roll(self, rolls=1):
        sum = 0
        while rolls :
            sum += random.randint(1, self.sides)
            rolls -= 1
        return sum

    def __repr__(self):
        return f"[{self.sides}]"

class Dice:
    def __init__(self, n=1, s=6):
        self.average = False
        self.best = False
        self.constant = False
        self.dice = [Die(s) for i in range(n)]

    def __init__(self, d):
        parts = d.split('.')
        n = int(parts[0])
        s = int(parts[2])
        self.average = False
        self.best = False
        self.constant = False
        self.dice = [Die(s) for i in range(n)]

    def roll(self, rolls=1):
        total = 0
        while rolls:
            for die in self.dice:
                total += die.roll()
            rolls -= 1
        return total

    def __repr__(self):
        return "".join([str(die) for die in self.dice])
