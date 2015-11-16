#include <stdio.h>
#include <math.h>

void PrintDigit(unsigned);
void PrintOut(unsigned int N);
void PrintReal(double N);
int IntPart(double N);
double DecPart(double N);

void PrintDigit(unsigned N)
{
	printf("%d",N);
}

void PrintOut(unsigned int N)
{
	if(N>=10)
		PrintOut(N / 10);
	PrintDigit(N % 10);
}

int IntPart(double N)
{
	int tmp;
	tmp = (int)N;
	return tmp;
}

double DecPart(double N)
{
	double tmp;
	tmp = N - IntPart(N);
	return tmp;
}

void PrintReal(double N, int DecPlaces)
{
	int IntegerPart;
	double FractionPart;

	if (N < 0){
		putchar('-');
		N = -N;
	}
	IntegerPart = IntPart(N);
	FractionPart = DecPart(N);

	PrintOut(IntegerPart);
	if (DecPlaces > 0){
		putchar('.');
	}
	PrintOut(FractionPart *pow(10,DecPlaces));
}

int main()
{
	PrintReal(-123.456,3);
	return 0;
}