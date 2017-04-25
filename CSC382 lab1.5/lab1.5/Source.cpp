#include <iostream>
#include <stdio.h>
#include <time.h>
#include <cmath>
using namespace std;


void main() {
	srand(time(NULL));
	int n[] = {1e2, 1e3, 1e4, 1e5, 1e6, 1e7, 1e8};
	printf("%s%15s%15s\n", "Total num", "Num Hit", "Pi");
	for (int i = 0; i < 7; i++) {
		int hit = 0;
		for (int j = 0; j < n[i]; j++) {
			float distance = 0;
			float x = (float)rand() / RAND_MAX;
			float y = (float)rand() / RAND_MAX;
			distance = sqrt(pow(x, 2) + pow(y, 2));
			if (distance < 1)
				hit++;
		}
		printf("%9d%15d%15f\n", n[i], hit, (float)hit / n[i] * 4);
	}
	system("pause");
}
