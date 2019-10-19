#include <stdio.h>

int main() {
	int localH, localM, ETMinsInEarthMin, ETMinsInETHour;
	scanf("%d:%d", &localH, &localM);
	scanf("%d", &ETMinsInEarthMin);
	scanf("%d", &ETMinsInETHour);
	int resMins = ((localH * ETMinsInETHour) + localM) / ETMinsInEarthMin;
	int resHours = (resMins / 60) % 24;
	resMins = resMins % 60;
	printf("%d:%d\n", resHours, resMins);
	return 0;
}
