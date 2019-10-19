import sys

M = sys.stdin.readline()
M = M.replace('\n', '')
Msorted = ''.join(sorted(M))
N = int(input())

listValidWord = []
for i in range(N) :
	m = sys.stdin.readline()
	m = m.replace('\n', '')
	if m[0] == M[0] and m[len(m) - 1] == M[len(M) - 1] and ''.join(sorted(m)) == Msorted :
		listValidWord.append(m)

listValidWord.sort()

for i in range(len(listValidWord)): 
    print(listValidWord[i])
