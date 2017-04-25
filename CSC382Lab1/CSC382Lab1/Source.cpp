#include <iostream>
#include <stdio.h>
#include <time.h>
#include <iomanip>
using namespace std;

long long FiboR(int n) // array of size n
{
	if (n == 0 || n == 1)
		return (n);
	else return (FiboR(n - 1) + FiboR(n - 2));
}

long long FiboNR(int n) // array of size n
{
	long long *F = new long long[n];
	F[0] = 0; F[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		F[i] = F[i - 1] + F[i - 2];
	}
	return (F[n]);
}


int main() {

	bool repeat = true;
	char rep = 'y';
	printf("%s%*s%*s%*s%*s\n", "Integer", 10, "FiboR", 10, "FiboNR", 20, "FiboR Value",20, "FiboNR Value");
	//long long a = 12586269025;
	//printf("%lld", a);
	for (int i = 0; i <= 50; i += 5) {
		long long y;
		long long z;
		time_t start1, start2, end1, end2;
		time(&start1);
		y = FiboR(i);
		time(&end1);
		time(&start2);
		z = FiboNR(i);
		time(&end2);
		printf("%7d%10d%10d%20lld%20lld\n", i, (int) difftime(end1,start1),(int) difftime(end2, start2), y , z);
	}	
	system("pause");
}