#include "testlib.h"
#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <random>
using namespace std;

int main(int argc, char* argv[])
{
    int N, a  = 0, b = 0, c = 0, mini = -1;
    vector<int> tab;
    bool first = true;

    cin >> N;
    for(int i = 0; i < N; i++){
    	int tmp;
    	cin >> tmp;
    	tab.push_back(tmp);
    }

    sort(tab.begin(), tab.end());

    for(int i = 0; i < N - 2; i++){
    	if(first or tab[i+2]-tab[i] < mini){
	        first = false;
	        a = tab[i];
	        b = tab[i+1];
	        c = tab[i+2];
	        mini = tab[i+2]-tab[i];
	    }
    }

    cout << a << " " << b << " " << c;
}
