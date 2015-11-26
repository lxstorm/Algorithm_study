#include <stdio.h>

long int Pow(long int X, unsigned int N);
bool IsEven(long int X);

long int Pow(long int X, unsigned int N)
{
	if(N == 0)
		return 1;
	if(IsEven(N))
		return Pow(X * X,N / 2);
	else
		return Pow(X * X, (N - 1) / 2) * X;
}

bool IsEven(long int X)
{
	if(X % 2 == 0)
		return 1;
	else
		return 0;
}

int main()
{
	int result_1;
	int result_2;

	result_1 = Pow(2,9);
	result_2 = Pow(2,10);
	printf("The first result is %d\n",result_1);
	printf("The second result is %d\n",result_2);

	return 0;
}