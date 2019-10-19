import math

nbPerson = int(input())
nbSeat = int(input())

print int(math.ceil(nbPerson / float(nbSeat)))
