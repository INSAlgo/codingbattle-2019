#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

double distance(double x1, double y1, double x2, double y2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main(void){

	int vitesseMax = 100, N, T, indice = 0;
	double Xb, Yb, lastX = 0, lastY = 0;
	char** coupables = (char**) malloc(0);

	scanf("%lf %lf", &Xb, &Yb);
	scanf("%d %d", &N, &T);

	for(int i = 0; i < N; i++){
		char suspect[100];
		scanf("%s", suspect);
		int criminel = 0;
		for(int j = 0; j < T; j++){
			double X;
			double Y;
			scanf("%lf %lf", &X, &Y);

			if(j > 0 && distance(lastX, lastY, Xb, Yb) + distance(Xb, Yb, X, Y) <= vitesseMax)
				criminel = 1;
			lastX = X;
			lastY = Y;
		}
		if(criminel){
			if(indice % 5 == 0){
				coupables = (char**) realloc(coupables, (indice + 5)  * sizeof(char*));
			}
			coupables[indice] = malloc(sizeof(char) * 1000);
			strcpy(coupables[indice], suspect);
			indice++;
		}
	}

	for(int i = 0; i < indice; i++){
		if(i != indice && i != 0)
			printf(" ");
		printf("%s", coupables[i]);
	}

	return 0;
}
