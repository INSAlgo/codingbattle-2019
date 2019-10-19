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
   string M;
   string MSorted;
   int N;
   int size;
   vector<string> listValidWord;

   cin >> M;
   MSorted = M;
   sort(MSorted.begin(), MSorted.end());
   cin >> N;

   for(int i = 0; i < N; i++){
   		string m;
   		string mSorted;
   		cin >> m;
   		mSorted = m;
   		if(m[0] == M[0] && m[m.size() - 1] == M[M.size() - 1]) {
   		   sort(mSorted.begin(), mSorted.end());
            if(mSorted == MSorted){
   			   listValidWord.push_back(m);
   		    }
         }
   }

   sort(listValidWord.begin(), listValidWord.end());

   for(unsigned int i = 0; i < listValidWord.size(); i++){
      cout << listValidWord[i] << endl;
   }

}
