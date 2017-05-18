#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_MAX 100


int Num[NUM_MAX];

void QuickSort(int _top, int _end)
{

	// printf("Sort %d ~ %d Started\n", _top, _end);

	if (_top >= _end)
	{
		// printf("%d >= %d Don't start\n", _top, _end);
		return;
	}

	bool leftArrowStop = false;
	bool rightArrowStop = false;

	int Pivot = Num[_top];
	int ArrowDetectPoint = 0;
	for (int i = _top, j = _end; (i != j)&& (i<j);)
	{
		if (Pivot <= Num[i])	leftArrowStop = true;

		if (Pivot > Num[j]) rightArrowStop = true;

		if (leftArrowStop&&rightArrowStop)
		{
			if (Num[i] > Num[j])
			{
				int tmp;
				tmp = Num[i];
				Num[i] = Num[j];
				Num[j] = tmp;
			}
			leftArrowStop = false;
			rightArrowStop = false;
		}
		else
		{
			if (!leftArrowStop)
			{
				i++;
				if (i == j)
				{
					if (_top < i)
					{
						ArrowDetectPoint = i;
						break;
					}
					else
					{
						ArrowDetectPoint = i + 1;
						break;
					}
					
				}
			}
			else if (!rightArrowStop)
			{
				j--;
				if (i == j)
				{
					if (_top < i)
					{
						ArrowDetectPoint = i;
						break;
					}
					else
					{
						ArrowDetectPoint = i + 1;
						break;
					}
				}
			}
		}
		// printf("Next Loop\n");

		
	}

	// printf("Sort %d ~ %d Finished\n", _top, _end);

	if (_top < ArrowDetectPoint - 1) QuickSort(_top, ArrowDetectPoint - 1);
	if (ArrowDetectPoint < _end)	QuickSort(ArrowDetectPoint, _end);

}

int main()
{
	srand((unsigned)time(NULL));

	for (int i = 0; i < NUM_MAX; i++)
	{
		Num[i] = rand()%101;
	}

	 printf("Before Sort  = \n");
	for (int i = 0; i < NUM_MAX; i++)
	{
		 printf("%d,", Num[i]);
	}

	QuickSort(0, NUM_MAX-1);

	printf("\nHello World\n");

	 printf("Sort Result = \n");
	for (int i = 0; i < NUM_MAX; i++)
	{
		 printf("%d,", Num[i]);
	}

	getchar();
	return 0;
}

