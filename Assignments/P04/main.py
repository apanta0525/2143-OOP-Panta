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
#main.py

from Dice import Die
from Dice import Dice

def dieTester(die, runs=10, testType="sum"):
    if isinstance(die, Die):
      print(f"Testing {die.sides} sided die for {runs} rolls:")
      print("    [ ", end="")
      for i in range(runs):
        print(die.roll(), end=" ")
      print("]")
    else:
      print(f"Rolling {len(die.dice)} {die.dice[0].sides} sided die {runs} times to get the {testType} value:")
      print("    [ ", end="")
      for i in range(runs):
        if testType == "avg":
          print(die.avg(), end=" ")
        elif testType == "min":
         print(die.min(), end=" ")
        elif testType == "max":
         print(die.max(), end=" ")
        else:
         print(die.roll(), end=" ")
      print("]")


if __name__ == '__main__':
  d1 = Die()
  d2 = Dice("2.d.20")

  dieTester(d1, 5)
  dieTester(d2, 20)
  # dieTester(d3, 10, "min")
  # dieTester(d3, 10, "avg")
  # dieTester(d2, 20, "max")
