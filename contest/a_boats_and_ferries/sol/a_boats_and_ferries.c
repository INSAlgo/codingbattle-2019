#include <stdio.h>

int main(int argc, char** argv){

    int p, b, f, r;

    // read and store input numbers as integers
    scanf("%d",&p);
	scanf("%d",&b);
	scanf("%d",&f);

    // compute the number of people who won't fit in the boats or ferries
    r = p - (4 * b + 500 * f);

    // if this number is negative, make it 0 instead
    if (r < 0){
        r = 0;
    }

    // then print the expected result
    printf("%d", r);

    return 0;
}
