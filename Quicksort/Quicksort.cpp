// Quicksort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// Split the array into two parts
int split(int *a, int low, int high);
void quicksort(int *a, int low, int high);
int main()
{

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
		a[low++] = a[high];

		while (low < high && part_element >= a[low])
			low++;
		if (low >= high)
			break;
		a[high--] = a[low];
	}
	a[high] = part_element;
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
