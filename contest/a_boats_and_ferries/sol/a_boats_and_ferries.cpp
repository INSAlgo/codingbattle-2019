#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <random>
using namespace std;

int main(int argc, char* argv[])
{
   int p, b, f, r;
   cin >> p >> b >> f;

   r = p  - (4 * b + 500 * f);
   if(r < 0)
   	r = 0;

   cout  << r << endl;

   return 0;
}
