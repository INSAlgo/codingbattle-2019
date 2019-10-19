#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <random>
#include <math.h>

using namespace std;

double distance(double x1, double y1, double x2, double y2){
		return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	}

int main(int argc, char* argv[])
{
   int vitesseMax = 100, N, T;
   double Xb, Yb, lastX = 0, lastY = 0;
   vector<string> coupables;

   cin >> Xb >> Yb >> N >> T;

   for(int i = 0; i < N; i++){
		string suspect;
		cin >> suspect;
		bool criminel = false;
		for(int j = 0; j < T; j++){
			double X;
			double Y;
			cin >> X >> Y;

			if(j > 0 && distance(lastX, lastY, Xb, Yb) + distance(Xb, Yb, X, Y) <= vitesseMax)
				criminel = true;
			lastX = X;
			lastY = Y;
		}
		if(criminel)
			coupables.push_back(suspect);
	}
	vector<string>::iterator iter;
	for (iter = coupables.begin(); iter != coupables.end(); iter++) {
		if (iter != coupables.begin()) cout << " ";
			cout << *iter;
	}

   return 0;
}
