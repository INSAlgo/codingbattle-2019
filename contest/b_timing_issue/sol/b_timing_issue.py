from math import floor

localH, localM = map(int, input().split(":"))
ETMinsInEarthMin = int(input())
ETMinsInETHour = int(input())

resMins = floor(((localH * ETMinsInETHour) + localM) / ETMinsInEarthMin)
resHours = (resMins // 60) % 24
resMins = resMins % 60
print("{}:{}".format(resHours, resMins))
