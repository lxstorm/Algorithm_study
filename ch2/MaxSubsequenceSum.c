#include <stdio.h>

int MaxSubsequenceSum_V1(const int A[], int N);
int MaxSubsequenceSum_V2(const int A[], int N);
int MaxSubsequenceSum_V3(const int A[], int N);
static int MaxSubSum(const int A[], int left, int right);
int Max3(int a, int b, int c);

int
MaxSubsequenceSum_V1(const int A[], int N)
{
	int MaxSum = 0;
	int ThisSum;
	int i,j,k;

	for(i = 0; i < N; i++){
		for(j=i; j < N; j++){
			ThisSum = 0;
			for(k=i; k <= j; k++){
				ThisSum += A[k];
			}
			if (ThisSum > MaxSum)
				MaxSum = ThisSum;
		}
	}
	return MaxSum;
}

int
MaxSubsequenceSum_V2(const int A[], int N)
{
	int MaxSum = 0;
	int ThisSum;
	int i,j,k;

	for(i = 0; i < N; i++){
		ThisSum = 0;
		for(j=i; j < N; j++){
			ThisSum += A[j];
			if (ThisSum > MaxSum)
				MaxSum = ThisSum;
		}
	}
	return MaxSum;
}

static int
MaxSubSum(const int A[], int Left, int Right)
{
	int MaxLeftSum, MaxRightSum;
	int MaxLeftBorderSum, MaxRightBorderSum;
	int LeftBorderSum, RightBorderSum;
	int Center, i;

	if(Left == Right){
		if(A[Left] > 0)
			return A[Left];
		else
			return 0;
	}

	Center = (Left + Right) / 2;
	MaxLeftSum = MaxSubSum(A, Left, Center);
	MaxRightSum = MaxSubSum(A, Center + 1, Right);

	MaxLeftBorderSum = 0;
	LeftBorderSum = 0;
	for(i = Center; i >= Left; i--){
		LeftBorderSum += A[i];
		if(LeftBorderSum > MaxLeftBorderSum)
			MaxLeftBorderSum = LeftBorderSum;
	}

	MaxRightBorderSum = 0;
	RightBorderSum = 0;
	for(i = Center + 1; i <= Right; i++){
		RightBorderSum += A[i];
		if(RightBorderSum > MaxRightBorderSum)
			MaxRightBorderSum = RightBorderSum;
	}

	return Max3(MaxLeftSum, MaxRightSum,
                MaxLeftBorderSum + MaxRightBorderSum);
}

int MaxSubsequenceSum_V3(const int A[], int N)
{
	return MaxSubSum(A, 0, N - 1);
}

int Max3(int a, int b, int c)
{
	int max;

	if (a > b)
		max = a;
	else
		max = b;

	if (max < c)
		max =c;
}

int MaxSubsequenceSum_V4(const int A[], int N)
{
     int ThisSum, MaxSum, j;

     ThisSum = MaxSum = 0;
     for(j = 0; j < N; j++){
         ThisSum += A[j];

         if(ThisSum > MaxSum)
             MaxSum = ThisSum;
         else if(ThisSum < 0)
             ThisSum = 0;
     }
     return MaxSum;
}

int main()
{
	const int A[] = {3, 5, -6, 7, 9};
	int MaxSum;

	MaxSum = MaxSubsequenceSum_V4(A, 5);
	printf("%d\n",MaxSum);
}
