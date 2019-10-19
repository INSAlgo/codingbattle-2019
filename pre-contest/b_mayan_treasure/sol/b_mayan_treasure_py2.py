import sys
#Taille de la liste
N = int(input())

#On recupere la liste
tab = [int(i) for i in sys.stdin.readline().split()]
#On trie la liste par ordre croissant
tab.sort()

#triplet de solutions a<=b<=c
a,b,c = 0,0,0
mini = -1
first = True
for i in range(N-2):
    if first or tab[i+2]-tab[i] < mini:
        first = False
        a,b,c = tab[i],tab[i+1],tab[i+2]
        mini = tab[i+2]-tab[i]
        
print str(a)+" "+str(b)+" "+str(c)
