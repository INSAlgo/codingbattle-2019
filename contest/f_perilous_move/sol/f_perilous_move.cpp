#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include<bits/stdc++.h> 

using namespace std;

//Edmonds-Karp algorithm found on:
//https://cp-algorithms.com/graph/edmonds_karp.html
//--> Modified for better spatial performance
//(the matrix has been replaced by a map basically)

map<pair<int, int>, int> capacity;
vector<vector<int>> adj;

int bfs(int s, int t, vector<int>& parent) {
	fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INT_MAX});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[{cur,next}]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[{cur,next}]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int maxflow(int n, int s, int t) {
	int flow = 0;
    vector<int> parent(n);
    int new_flow;

    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[{prev,cur}] -= new_flow;
            capacity[{cur,prev}] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

int main(int argc, char* argv[])
{
	int A,M,B;
	cin >> A >> M >> B;
	
	adj = vector<vector<int>>(2+A+B+2*M);
	
	//Global source is node 0
	//People A are nodes from 2 to 2+A-1
	//We connect all people A to the global source:
	adj[0] = vector<int>(A);
	for(int i=2;i<2+A;++i)
	{
		adj[0][i-2] = i;
		adj[i].push_back(0);
		capacity[{0,i}] = 1;
		capacity[{i,0}] = 0;
	}
	//Global sink is node 1
	//People B are nodes from 2+A to 2+A+B-1
	//We connect all people B to the global sink:
	adj[1] = vector<int>(B);
	for(int i=2+A;i<2+A+B;++i)
	{
		adj[i].push_back(1);
		adj[1][i-(2+A)] = i;
		capacity[{i,1}] = 1;
		capacity[{1,i}] = 0;
	}
	
	int P, SA,SB;
	int nodeA, nodeB;
	//Mediators are nodes from 2+A+B to 2+A+B+2*M-1 
	for(int i=0;i<M;++i)
	{
		//the mediator nodes are duplicated so that they are used a fix amount of times
		cin >> P;
		adj[2+A+B+2*i].push_back(2+A+B+2*i +1);
		adj[2+A+B+2*i +1].push_back(2+A+B+2*i);
		capacity[{2+A+B+2*i,2+A+B+2*i +1}] = (P-1)/2;
		capacity[{2+A+B+2*i +1,2+A+B+2*i}] = 0;
		
		cin >> SA >> SB;
		//we create the edges between people A and the mediator:
		for(int j=0;j<SA;++j)
		{
			cin >> nodeA;
			nodeA += 2 -1;
			adj[nodeA].push_back(2+A+B+2*i);
			adj[2+A+B+2*i].push_back(nodeA);
			capacity[{nodeA,2+A+B+2*i}] = 1;
			capacity[{2+A+B+2*i,nodeA}] = 0;
		}
		//we create the edges between the mediator (his copy) and people B:
		for(int j=0;j<SB;++j)
		{
			cin >> nodeB;
			nodeB += 2+A -1;
			adj[2+A+B+2*i +1].push_back(nodeB);
			adj[nodeB].push_back(2+A+B+2*i +1);
			capacity[{2+A+B+2*i +1,nodeB}] = 1;
			capacity[{nodeB,2+A+B+2*i +1}] = 0;
		}
	}
	
	cout << maxflow(2+A+B+2*M,0,1)*2 << endl;
	
	return 0;
}
