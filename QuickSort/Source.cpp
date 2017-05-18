#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_MAX 100




void Swap(int *a, int *b) { int n = *a; *a = *b; *b = n; }

void QuickSort(int *_top, int *_end)
{
	if (_top == _end) return;
	
	bool leftArrowStop = false;
	bool rightArrowStop = false;

	int Pivot = *_top;
	int *leftArrow = _top;
	int *rightArrow = _end;
	while(true){
		if (Pivot <= *leftArrow)	leftArrowStop = true;
		if (Pivot > *rightArrow)	rightArrowStop = true;

		if (leftArrowStop&&rightArrowStop)
		{
			if (*leftArrow > *rightArrow) Swap(leftArrow, rightArrow);
			leftArrowStop = false;
			rightArrowStop = false;
		}
		else
		{
			if (!leftArrowStop)
			{
				leftArrow++;
				if (leftArrow == rightArrow)
				{
					break;
				}
			}
			if (!rightArrowStop)
			{
				rightArrow--;
				if (leftArrow == rightArrow)
				{
					break;
				}
			}
		}
	}

	if (leftArrow != _top && *leftArrow >= Pivot) leftArrow--;
	else if (rightArrow != _end) rightArrow++;

	QuickSort(_top, leftArrow);
	QuickSort(rightArrow, _end);

}

int main()
{
	int Num[NUM_MAX];
	srand((unsigned)time(NULL));

	for (int i = 0; i < NUM_MAX; i++)
	{
		Num[i] = rand() % 101;
	}

	printf("Before Sort  = \n");
	for (int i = 0; i < NUM_MAX; i++)
	{
		printf("%d,", Num[i]);
	}

	QuickSort(&Num[0],&Num[NUM_MAX-1]);

	printf("\nHello World\n");

	printf("Sort Result = \n");
	for (int i = 0; i < NUM_MAX; i++)
	{
		printf("%d,", Num[i]);
	}

	getchar();
	return 0;
}

