#include <stdlib.h>
#include <stdio.h>
#include <time.h>

struct List1 {
	int Info;
	struct List1 *Next;
};
class List_One { 
protected:
	struct List1 *Start;
	int Amount;
	static int counter;
	int ID = 0;
public:
		List_One(void);
		List_One(int N);
		List_One(int N, int Diapazon,int Shift);
		~List_One();
		void Print(void);
		void Append(int N);
		void Insert(int N, int Before);
		void Erase(int Out);
		void Replace(int N1, int N2);
		int GetValue(int N);
		int Empty(void);
		int ListLength(void);
		struct List1 *GetAddress(int N);	
};

int List_One::counter = 0;

List_One::List_One(void) 
{
	ID = counter;
	printf("Конструктор списка %d !!!\n",ID);
	Start = new struct List1;
	Start -> Next = NULL;
	Amount = 0;
	counter++;
}
List_One::List_One(int N, int Diapazon, int Shift)
{ 
	ID = counter;
	printf("Конструктор списка %d со случайной последовательностью размера %d, диапазоном %d и сдвигом %d !!!\n", ID, N, Diapazon, Shift);
	Start = new struct List1;
	Start -> Next = NULL;
	Amount = 0;
	srand(time(NULL));
	for(int Count = 0; Count < N; Count++){
		Append(rand() % Diapazon-Shift);
	}
	counter++;

}

int List_One::Empty(void)
{
	if(Amount) return 0;
	return 1;
}

int List_One::ListLength(void)
{
	return Amount;
}
struct List1 * List_One::GetAddress(int N)
{
	struct List1 *tmp;
	int Count;
	if(N < 0 || N> ListLength()) return NULL;
	tmp = Start;
	for(Count = 0;Count<N;Count++) tmp = tmp -> Next;
	return tmp;	
}

void List_One::Append(int N)
{ 
	struct List1 *Fresh, *Last;
	Fresh = new (struct List1);
	Last = GetAddress(ListLength());
	Last -> Next=Fresh;Fresh->Next=NULL;
	Fresh -> Info=N;Amount++;
}

void List_One::Insert(int N,int Before)
{	
	struct List1 *Last, *Fresh;
	Fresh=new(struct List1);
	Last=GetAddress(Before-1);
	Fresh -> Next=Last -> Next; Last -> Next = Fresh;
	Fresh -> Info=N;Amount++;
}

void List_One::Erase(int Out)
{ 
	struct List1 *Before, *Erased;
	Before = GetAddress(Out - 1);
	Erased = Before -> Next;
	Before -> Next = Erased -> Next;
	delete (Erased);
	Amount--;
}

int List_One::GetValue(int N)
{
	struct List1 *tmp;
	tmp=GetAddress(N);
	return tmp -> Info;
}

void List_One::Print(void)
{
	int Count;
	struct List1 *tmp;
	if(Empty()){
		printf("List %d is EMPTY !!!\n", ID); return;}
	for(Count = 1; Count <= Amount; Count++)
	{
		tmp=GetAddress(Count);
		printf("%d->%p ", tmp -> Info, tmp -> Next);
	}
	printf("\n");
}

List_One::~List_One()
{
	printf("Деструктор списка %d !!!\n", ID);
	counter--;
	while(!Empty()) Erase(1);
	delete Start;
}



	

