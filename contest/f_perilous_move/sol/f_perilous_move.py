from collections import deque

#Edmonds-Karp algorithm found on:
#https:#cp-algorithms.com/graph/edmonds_karp.html
#--> Translated in Python and modified for better 
#	spatial performance
#	(the matrix has been replaced by a map basically)

INT_MAX = 9223372036854775807
capacity = {}
adj = []

def bfs(s,t,parent):
	for k in range(len(parent)):
		parent[k] = -1
	parent[s] = -2
	q = deque()
	q.append((s, INT_MAX))

	while len(q) > 0:
		front = q.popleft()
		cur = front[0]
		flow = front[1]

		for nextNode in adj[cur]:
			if parent[nextNode] == -1 and capacity[(cur,nextNode)] > 0:
				parent[nextNode] = cur
				new_flow = min(flow, capacity[(cur,nextNode)])
				if nextNode == t:
					return new_flow
				q.append((nextNode, new_flow))
	return 0

def maxflow(n,s,t):
	flow = 0
	parent = [0]*n
	
	new_flow = bfs(s, t, parent)
	while new_flow > 0:
		flow += new_flow
		cur = t
		while cur != s:
			prev = parent[cur]
			capacity[(prev,cur)] -= new_flow
			capacity[(cur,prev)] += new_flow
			cur = prev
		new_flow = bfs(s, t, parent)

	return flow

A,M,B = [int(k) for k in input().split()]
	
adj = [[] for i in range(2+A+B+2*M)]
	
#Global source is node 0
#People A are nodes from 2 to 2+A-1
#We connect all people A to the global source:
adj[0] = [0]*A
for i in range(2,2+A):
	adj[0][i-2] = i
	adj[i].append(0)
	capacity[(0,i)] = 1
	capacity[(i,0)] = 0
#Global sink is node 1
#People B are nodes from 2+A to 2+A+B-1
#We connect all people B to the global sink:
adj[1] = [0]*B
for i in range(2+A,2+A+B):
	adj[i].append(1)
	adj[1][i-(2+A)] = i
	capacity[(i,1)] = 1
	capacity[(1,i)] = 0
	
SA,SB = 0,0
nodeA, nodeB = 0,0
#Mediators are nodes from 2+A+B to 2+A+B+2*M-1 
for i in range(0,M):
	#the mediator nodes are duplicated so that they are used a fixed amount of times
	P = int(input())
	adj[2+A+B+2*i].append(2+A+B+2*i +1)
	adj[2+A+B+2*i +1].append(2+A+B+2*i)
	capacity[(2+A+B+2*i,2+A+B+2*i +1)] = P//2
	capacity[(2+A+B+2*i +1,2+A+B+2*i)] = 0
		
	SA,SB = [int(k) for k in input().split()]
	#we create the edges between people A and the mediator:
	inputA = [int(k) for k in input().split()]
	for nodeA in inputA:
		nodeA += 2 -1
		adj[nodeA].append(2+A+B+2*i)
		adj[2+A+B+2*i].append(nodeA)
		capacity[(nodeA,2+A+B+2*i)] = 1
		capacity[(2+A+B+2*i,nodeA)] = 0
		
	#we create the edges between the mediator (his copy) and people B:
	inputB = [int(k) for k in input().split()]
	for nodeB in inputB:
		nodeB += 2+A -1
		adj[2+A+B+2*i +1].append(nodeB)
		adj[nodeB].append(2+A+B+2*i +1)
		capacity[(2+A+B+2*i +1,nodeB)] = 1
		capacity[(nodeB,2+A+B+2*i +1)] = 0
	
print(maxflow(2+A+B+2*M,0,1)*2)
