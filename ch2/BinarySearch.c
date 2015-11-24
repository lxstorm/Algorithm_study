#include <stdio.h>

#define NotFound -1

int BinarySearch(const int A[], int X, int N)
{
	int Low, Mid, High;

	Low = 0;
	High = N - 1;
	while(Low <= High)
	{
		Mid = (Low + High) / 2;
		if( X < A[Mid])
			High = Mid - 1;
		else if(X > A[Mid])
			Low = Mid + 1;
		else
			return Mid;
	}
	return NotFound;
}

int main()
{
	int A[] = {1,2,3,4,5,6,7,8,9,10};
	int index;
	int TargetNum = 89;

	index = BinarySearch(A, TargetNum, 10);
	if(index != -1)
		printf("The index of the target is %d\n",index);
	else
		printf("The target number is not in the array!\n");
	return 0;
}