#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <random>
using namespace std;

int main(int argc, char* argv[])
{
   int localH, localM, ETMinsInEarthMin, ETMinsInETHour, resMins, resHours;
   char trash;

   cin >> localH >> trash >> localM >> ETMinsInEarthMin >> ETMinsInETHour;
   resMins = ((localH * ETMinsInETHour) + localM) / ETMinsInEarthMin;

   resHours = (resMins / 60) % 24;
   resMins = resMins % 60;

   cout << resHours << ":" << resMins;

   return 0;
}
