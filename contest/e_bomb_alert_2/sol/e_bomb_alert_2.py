# ==> PYTHON 3 <==
import sys
import heapq

taille = -1
departFeuRouge=0

def calculerPoids(oldY, oldX, y, x, current_distance, carte):
	if carte[oldY][oldX] == 0:
		#Si on part d'une case vide
		if carte[y][x] == 2 and (current_distance+departFeuRouge) % 2 == 1:
			#Et que le feu est rouge
			return 2
		else:
			#Et que le feu est vert
			return 1
			
	elif carte[oldY][oldX] == 2 and (current_distance+departFeuRouge) % 2 == 0:
		#Si on part d'un feu vert
		return 1
	else:
		#Si on part d'un feu rouge
		return 2

def maj_distances(oldY, oldX, y, x, distances, precedence, current_distance, carte, pq):
	if carte[y][x] != 1:
		distance = current_distance + calculerPoids(oldY, oldX, y, x, current_distance, carte)
		if distance < distances[y][x]:
			distances[y][x] = distance
			precedence[y][x] = (oldY, oldX)
			heapq.heappush(pq, (distance, (y, x)))

#https://bradfieldcs.com/algos/graphs/dijkstras-algorithm/
def dijkstra2(carte, distances, precedence, Yb, Xb):
	for i in range(taille):
		ligne = []
		lignePred = []
		for j in range(taille):
			ligne.append(sys.maxsize)
			lignePred.append(None)
		distances.append(ligne)
		precedence.append(lignePred)
	distances[Yb][Xb] = 0;
	#dans la matrice precedence, on stoche le predecesseur de chaque noeud au sein du chemin optimal
	#dans la matrice distances, on stocke la durée minimale pour aller de la bombe au point
	#(étant donné les points actuellement découverts par l'algorithme)

	pq = [(0, (Yb, Xb))];
	#On part de la bombe et on évalue la durée minimale pour se rendre à tous les points
	#dans un rayon de 61
	while len(pq) > 0:
		current_distance, current_vertex = heapq.heappop(pq)
		current_y = current_vertex[0]
		current_x = current_vertex[1];
		if current_distance > distances[current_y][current_x] or current_distance >= 61:
			continue
		#Je peut aller en haut
		if current_y > 0:
			maj_distances(current_y,current_x,current_y - 1, current_x, distances, precedence, current_distance, carte, pq)
		#Je peut aller en bas
		if current_y < taille - 1:
			maj_distances(current_y,current_x,current_y + 1, current_x, distances, precedence, current_distance, carte, pq)
		#Je peut aller à gauche
		if current_x > 0:
			maj_distances(current_y,current_x,current_y, current_x - 1, distances, precedence, current_distance, carte, pq)
		#Je peut aller à droites
		if current_x < taille - 1:
			maj_distances(current_y,current_x,current_y, current_x + 1, distances, precedence, current_distance, carte, pq)
	return distances

def retroParcours(carte, precedence,current_distance,y,x):
	#On execute uniquement 2 dijkstras à partir de la bombe
	#or, la durée n'est pas la même selon le sens où on parcours un chemin
	#plus précisement, elle diffère au plus de 1
	#C'EST POURQUOI on reparcourt le trajet à l'envers
	#grâce à la matrice de précedence
	#pour obtenir la durée du trajet position -> bombe
	if precedence[y][x] == None:
		#On a atteint la bombe:
		return current_distance
	else:
		newY,newX  = precedence[y][x]
		poids = calculerPoids(y, x, newY, newX, current_distance, carte)
		current_distance += poids
		return retroParcours(carte, precedence,current_distance,newY,newX)

#=========================================================================================
N, P = map(int, input().split())
criminelsNames = []
listeCriminelsPositions = []
for i in range(N):
	criminelsNames.append(input())
	listePositions = []
	for j in range(P):
		Y, X = map(int, input().split())
		listePositions.append([Y - 1, X - 1])
	listeCriminelsPositions.append(listePositions)

M = int(input())
taille = M

carte = []
for i in range (M):
	ligne = []
	vals = map(int, input().split())
	for val in vals:
		ligne.append(val)
	carte.append(ligne)

Yb, Xb = map(int, input().split())

#On part de la bombe avec un feu vert
#On calcule la durée pour aller à tous les points proches
distancesVert = []
precedenceVert = []
carteCoutMinimumVert = dijkstra2(carte, distancesVert, precedenceVert, Yb - 1, Xb - 1)
#On part de la bombe avec un feu rouge
#On calcule la durée pour aller à tous les points proches
departFeuRouge=1
distancesRouge = []
precedenceRouge = []
carteCoutMinimumRouge = dijkstra2(carte, distancesRouge, precedenceRouge, Yb - 1, Xb - 1)

#On remet le feu initial à vert
departFeuRouge=0

coupables = []

#Pour tous les criminels
for indiceCriminel, criminelPositions in enumerate(listeCriminelsPositions):
	#Pour tous ces positions sauf la dernière, on prend la n et la n+1
	for position, positionSuivante in zip(criminelPositions, criminelPositions[1:]):
		trajetVersBombe = 0
		trajetDepuisBombe = 0
		depY, depX = position[0], position[1]
		arrY, arrX = positionSuivante[0], positionSuivante[1]
		
		#On connait la durée du trajet bombe -> p1
		#Mais on doit faire un retro parcours sur les trajets partant feu vert/rouge de la bombe
		#pour trouver la durée optimale du trajet p1 -> bombe
		if carteCoutMinimumVert[depY][depX] <= 61:
			trajetVersBombe = retroParcours(carte, precedenceVert,0,depY,depX)
			if carteCoutMinimumRouge[depY][depX] <= 61:
				trajetVersBombe = min(trajetVersBombe,retroParcours(carte, precedenceRouge,0,depY,depX))
		elif carteCoutMinimumRouge[depY][depX] <= 61:
			trajetVersBombe = retroParcours(carte, precedenceRouge,0,depY,depX)
		else:
			#On ne peut pas atteindre la bombe depuis cette position de départ
			continue
		
		if trajetVersBombe % 2 == 0:
			trajetDepuisBombe = carteCoutMinimumVert[arrY][arrX]
		else:
			trajetDepuisBombe = carteCoutMinimumRouge[arrY][arrX]
			
		if trajetVersBombe + trajetDepuisBombe <= 60:
			#Le suspect a eu le temps d'atteindre la bombe
			coupables.append(criminelsNames[indiceCriminel])
			break 

if not coupables:
	print("NONE")
else:
    coupables.sort()
    print(*coupables, sep = " ") 