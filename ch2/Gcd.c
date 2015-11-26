#include <stdio.h>

unsigned int Gcd(unsigned int M, unsigned int N)
{
	unsigned int Rem;

	while(N > 0)
	{
		Rem = M % N;
		M = N;
		N = Rem;
	}
	return M;
}

int main()
{
	unsigned int result;
	result = Gcd(1989,1590);
	printf("The result is %d\n",result);

	return 0;
}