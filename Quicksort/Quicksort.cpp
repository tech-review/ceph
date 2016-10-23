// Quicksort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// Split the array into two parts
int split(int *a, int low, int high);
// Quicksort
void quicksort(int *a, int low, int high);
int main()
{
	int *array;
	int Size = 0;
	srand((unsigned)time(NULL));

	printf("Enter the size of array: ");
	scanf_s("%d", &Size);

	array = (int*)malloc(Size * sizeof(int));

	// Generate element for array
	printf("***Original array***\n");
	for (int i = 0; i < Size; ++i)
	{
		array[i] = rand() % Size + 1;
		printf("%d ", array[i]);
	}
	printf("\n");

	quicksort(array, 0, Size - 1);
	printf("***Ordered Array***\n");
	for (int i = 0; i < Size; ++i)
	{
		printf("%d ", array[i]);
	}		
	printf("\n");

    return 0;
}

int split(int * a, int low, int high)
{
	int part_element = a[low];

	while (true)
	{
		while (low < high && part_element <= a[high])
			high--;
		if (low >= high)
			break;
		a[low++] = a[high];	// Swap operation

		while (low < high && part_element >= a[low])
			low++;
		if (low >= high)
			break;
		a[high--] = a[low];
	}
	a[high] = part_element;		// Swap operation
	return high;
}

void quicksort(int * a, int low, int high)
{
	int middle;
	
	if (low >= high)
		return;
	middle = split(a, low, high);
	quicksort(a, low, middle - 1);
	quicksort(a, middle + 1, high);
}
