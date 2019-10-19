#include <iostream>
#include <math.h>  
using namespace std;

int main()
{
	unsigned int nb_person;
	unsigned int nb_seats;

	cin >> nb_person;
	cin >> nb_seats;

	cout << ceil(nb_person / (float) nb_seats);
}
