import sys
from math import floor

localH, localM = map(int, sys.stdin.readline().replace('\n', '').split(":"))
ETMinsInEarthMin = int(sys.stdin.readline().replace('\n', ''))
ETMinsInETHour = int(sys.stdin.readline().replace('\n', ''))

resMins = floor(((localH * ETMinsInETHour) + localM) / ETMinsInEarthMin)
resHours = (resMins // 60) % 24
resMins = resMins % 60
print "{}:{}".format(int(resHours), int(resMins))
