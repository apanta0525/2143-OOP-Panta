""""            
 Author:           Ashish Panta
 Email:            apanta0525@gmail.com
 Label:            P04
 Title:            Roll Them Bones!
 Course:           CMPS 2143
 Semester:         Spring 2023
 
 Description:
      This program implements Die and Dice classes.

 Usage:
      N/A
 
 Files:  
       main.py
       dice.py

"""
#dice.py

import random

"""
 Class Die

Description:
   Implementation of the Die class.

Methods:
     __init__(self, sides)
     roll(self,rolls)
     __repr__(self)
   
"""
class Die:
  """
     __init__
     Description:
         This is a constructor for class Die.
     Returns:
         N/A
    """
    def __init__(self, sides=6):
        self.sides = sides

  """
     roll
     Description:
         Shuffles the values of the rolls and adds all rolled values.
     Returns:
         the sum of the values after rolling.
  """
    def roll(self, rolls=1):
        sum = 0
        while rolls :
            sum += random.randint(1, self.sides)
            rolls -= 1
        return sum
     
      """
     __repr__
     Description:
         This is similar to ostream overloading in c++. Formats how we want to print.
     Returns:
         Die as a string
  """
    def __repr__(self):
        return f"[{self.sides}]"

"""
 Class Dice

Description:
    Implementation of Dice class.

Methods:
     __init__(self, n, s)
     __init__(self, d)
     roll(self, rolls=1)
     avg(self,rolls = 1):
     max(self,rolls = 1)
     __repr__(self)
   
"""
class Dice:
   """
     __init__
     Description:
         This is a constructor for class Dice.
     Returns:
         N/A
  """
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

  """
     roll
     Description:
            Adds all the numbers from each rolls.
     Returns:
         The sum of values of rolls.
  """
    def roll(self, rolls=1):
        total = 0
        while rolls:
            for die in self.dice:
                total += die.roll()
            rolls -= 1
        return total

"""
     avg
     Description:
            Rolls the dice and returns the average among them.
     Returns:
         The average of values roll.
"""
def avg(self,rolls = 1):
    sum = 0
    for i in range(len(dice)):
        value = dice[i].roll()
        sum += value
    avg = sum // len(dice)
    return avg

"""
     max
     Description:
            Rolls the dice and returns the max among them.
     Returns:
         The maximum of value rolls.
  """
def max(self,rolls = 1):
    max = 0
    for i in range(len(dice)):
        value = dice[i].roll()
        if value >= max:
            max = value
    return max

    """
     __repr__
     Description:
         This is similar to ostream overloading in c++. Formats how we want to print.
     Returns:
         Dice as a string
  """
    def __repr__(self):
        return "".join([str(die) for die in self.dice])
