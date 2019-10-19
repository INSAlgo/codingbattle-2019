#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include<string.h>

int compare( const void* a, const void* b){
	char int_a = * ( (char*) a );
	char int_b = * ( (char*) b );

	if ( int_a == int_b ) return 0;
	else if ( int_a < int_b ) return -1;
	else return 1;
}

//https://www.geeksforgeeks.org/c-program-sort-array-names-strings/
int compareArrayString(const void* a, const void* b) { 
    return strcmp(*(const char**)a, *(const char**)b); 
} 

int main(void){
	char M[100];
	char MSorted[100];
	int N, size, indice = 0;
	char** listWord = (char**) malloc(0);

	scanf("%s", M);
	size = strlen(M);
	strcpy(MSorted, M);
	qsort(MSorted, size, sizeof(char), compare);
	scanf("%d", &N);

	for(int i = 0; i < N; i++){
		char m[100];
		scanf("%s", m);

		if(m[0] == M[0] && m[size - 1] == M[size - 1]){
			char mSorted[100];
			strcpy(mSorted, m);
			qsort(mSorted, size, sizeof(char), compare);
			if(strcmp(mSorted, MSorted) == 0){
				if(indice % 5 == 0){
					listWord = (char**) realloc(listWord, (indice + 5)  * sizeof(char*));
				}
				listWord[indice] = malloc(sizeof(char) * 1000000);
				strcpy(listWord[indice], m);
				indice++;
			}
		}
	}

	qsort(listWord, indice, sizeof(const char*), compareArrayString);

	for(int i = 0; i < indice; i++){
		printf("%s\n", listWord[i]);
	}
}
