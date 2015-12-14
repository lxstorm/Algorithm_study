/*Queue implementation is a dynamically allocated array*/
#define MinQueueSize(S)

struct QueueRecord
{
	int Capacity;
	int Front;
	int Rear;
	int Size;
	ElementType *Array;
};

int IsEmpty(Queue Q)
{
	return Q->Size == 0;
}

void MakeEmpty(Queue Q)
{
	Q->Size = 0;
	Q->Rear = 0;
	Q->Front = 1;
}

struct int Succ(int Value, Queue Q)
{
	if(++Value == Capacity)
		Value = 0;
	return Value;
}

void Enqueue(ElementType X, Queue Q)
{
	if(IsFull(Q))
		Error("Full Queue");
	else
	{
		Q->Size++;
		Q->Rear = Succ(Q->Rear,Q);//用于对Rear进行操作包括+1和循环操作
		Q->Arrary[Q->Rear] = X;
	}
}