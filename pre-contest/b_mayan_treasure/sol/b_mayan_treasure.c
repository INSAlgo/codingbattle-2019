#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int compare( const void* a, const void* b){
	int int_a = * ( (int*) a );
	int int_b = * ( (int*) b );

	if ( int_a == int_b ) return 0;
	else if ( int_a < int_b ) return -1;
	else return 1;
}

int main(void){
	unsigned int tab[10000];
	unsigned int N;
	scanf("%d", &N);

	int i;
	for(i = 0; i < N; i++){
		scanf("%u", &tab[i]);
	}

	qsort(tab, N, sizeof(int), compare);

	int a = 0, b = 0, c = 0, mini = - 1, first = 1;
	for(i  = 0; i < N - 2; i++){
		if(first || tab[i + 2] - tab[i] < mini){
			first = 0;
			a = tab[i];
			b = tab[i + 1];
			c = tab[i + 2];
		    mini = tab[i + 2] - tab[i];
		}
	}
	printf("%d %d %d\n", a, b, c);
}
