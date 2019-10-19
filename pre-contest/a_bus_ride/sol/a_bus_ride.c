#include <stdio.h>
#include <math.h>

int main(void){
	unsigned int nbPerson, nbSeats;
	scanf("%d", &nbPerson);
	scanf("%d", &nbSeats);

	unsigned int res = nbPerson / nbSeats;
	if(nbPerson % nbSeats != 0)
		res++;

	printf("%d\n", res);
}
