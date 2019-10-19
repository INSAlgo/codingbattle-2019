import sys
from math import sqrt

#Distance entre 2 points
def distance(x1,y1,x2,y2):
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))

#Position de la bombe:
Xb, Yb = [float(i) for i in sys.stdin.readline().replace('\n', '').split()]
#Nombre de suspects et de positions par suspect:
N, T = [int(i) for i in sys.stdin.readline().replace('\n', '').split()]

#vitesse maximale (Cf enonce)
vitesseMax = 100
coupables = []
lastX,lastY = 0,0

for i in range(N):
    #Nom du suspect
    suspect = sys.stdin.readline().replace('\n', '')
    criminel = False
    for j in range(T):
        X,Y = [float(k) for k in sys.stdin.readline().replace('\n', '').split()]
        #Si entre 2 positions successives, le suspect a le temps d'atteindre
        #la position de la bombe sans depasser la vitesse maximale,
        #alors il est potentiellement coupable
        if j>0 and (distance(lastX,lastY,Xb,Yb)+distance(Xb,Yb,X,Y)) <= vitesseMax:
            criminel = True
        lastX,lastY = X,Y
    if(criminel):
        coupables.append(suspect)

#On affiche en sortie la liste des suspects potentiellement coupables
#(Il y en a au moins un)        
print " ".join(coupables)
