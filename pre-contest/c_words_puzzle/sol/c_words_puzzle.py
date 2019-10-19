M = input()
Msorted = ''.join(sorted(M))
N = int(input())

listValidWord = []
for i in range(N) :
	m = input()
	if(m[0] == M[0] and m[len(m) - 1] == M[len(M) - 1] and ''.join(sorted(m)) == Msorted) :
		listValidWord.append(m)

listValidWord.sort()
print(*listValidWord, sep="\n")
