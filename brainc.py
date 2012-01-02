###########################################################################
#                                                                         #
#   Do calculation problems to sharpen the noggin                         #
#   This is a python version                                              #
#                                                                         #
#   Copyright (C) 2012 by Vernon Swanepoel                                #
#   vernon@sandcurves.com                                                 #
#                                                                         #
#   This program is free software; you can redistribute it and/or modify  #
#   it under the terms of the GNU General Public License as published by  #
#   the Free Software Foundation; either version 2 of the License, or     #
#   (at your option) any later version.                                   #
#                                                                         #
#   This program is distributed in the hope that it will be useful,       #
#   but WITHOUT ANY WARRANTY; without even the implied warranty of        #
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         #
#   GNU General Public License for more details.                          #
#                                                                         #
#   You should have received a copy of the GNU General Public License     #
#   along with this program; if not, write to the                         #
#   Free Software Foundation, Inc.,                                       #
#   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             #
#                                                                         #
###########################################################################

import random

def problems(num1, num2, hard):
    "give the problems"
    hardness = 2
    if hard:
        hardness = 4
    operator = random.randint(1, hardness)
    print "hardness of %d" % hardness
    if operator == 1:
        print "%d + %d = " % (num1, num2),
        answer = input("")
        correct = num1 + num2
    elif operator == 2:
        if num1 > num2:
            n1 = num1
            n2 = num2
        else:
            n1 = num2
            n2 = num1
        print "%d - %d = " % (n1, n2),
        answer = input("")
        correct = n1 - n2
    elif operator == 3:
        print "%d * %d = " % (num1, num2),
        answer = input("")
        correct = num1 * num2
    else:
        if num1 > num2:
            n1 = num1
            n2 = num2
        else:
            n1 = num2
            n2 = num1
        print "%d / %d = " % (n1, n2),
        answer = input("")
        correct = n1 / n2
    if answer == correct:
        print "You got it right!"
        result = 1
    else:
        print "Wrong, it was %d" % correct
        result = 0
    return result

def calcprobs(dign, turns):
    "generate the numbers, and dispatch for problems"
    right_answers = 0
    print "Would you like:"
    print "1. only addition and stubtraction"
    print "2. addition, subtraction, multiplication and division"
    how_hard = input("Choose 1 or 2 >>> ")
    how_hard = 1 and (how_hard == 2)
    for i in range(0, turns):
        # Generate two digits of length dign
        c = 0 # counter
        start = 1
        end = 9
        dig1 = dig2 = 0
        for n in range(0, dign):
            if c > 0:
                start = 0
            dig2 = (dig2 * 10) + random.randint(start, end)
            dig1 = (dig1 * 10) + random.randint(start, end)
        right_answers += problems(dig1, dig2, how_hard)
    return right_answers

if __name__ == "__main__":
    dignum = rounds = c = 0
    while dignum > 3 or dignum < 1:
        if c > 0:
            print "Your digits must be between 1 and 3"
        print "How many digets do you want to work with, 1 - 3?"
        dignum = input("\n>>> ")
        c += 1
    print "How many rounds would you like to do?"
    rounds = input("\n>>> ")    
    print "\n\nYou got %d out of %d right\n\n." % (calcprobs(dignum, rounds), rounds)  
