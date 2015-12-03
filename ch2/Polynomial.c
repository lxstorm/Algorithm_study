typedef struct
{
	int CoeffArray[MaxDegree + 1];
	int HighPower;
}*Polynomial;

void ZeroPolynomial(Polynomial Poly)
{
	int i;

	for(i = 0; i <= MaxDegree; i++)
			Poly->CoeffArray[i] = 0;
	
	Poly->HighPower = 0;
}

void AddPolynomial(const Polynomial Poly1,
					const Polynomial Poly2,Polynomial PolySum)
{
	int i;

	ZeroPolynomial(PolySum);

	PolySum->HighPower = Max(Poly1->HighPower,Poly2->HighPower);
	for(i = 0; i <= PolySum->HighPower; i++)
	{
		PolySum->CoeffArray[i] = Poly1->CoeffArray[i] + Poly2->CoeffArray[i];		
	}
}

void MultPolynomial(const Polynomial Poly1, const Polynomial Poly2, 
					Polynomial PolyProd)
{
	int i,j;

	PolyProd->HighPower = Poly1->HighPower * Poly2->HighPower;
	ZeroPolynomial(PolyProd);
	if(PolyProd->HighPower > MaxDegree)
		Error("Exceed array size");
	else
		for(i = Poly1->HighPower; i >= 0; i--)
			for(j = Poly2 ->HighPower; i >= 0; i--)
				PolyProd->CoeffArray[i + j] += Poly1->CoeffArray[i] *
											   Poly2->CoeffArray[j]
}

/*******************singly linked list**********************/
struct Node;
typedef struct Node *PtrToNode;
struct Node{
	int Coefficient;
	int Exponet;
	PtrToNode Next;
};
typedef PtrToNode Polynomial;