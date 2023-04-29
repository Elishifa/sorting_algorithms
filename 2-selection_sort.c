#include "sort.h"


/**
 * swap - two integer swap
 * @i: first integer
 * @j: second integer
 */

void swap(int *i, int *j)
{
	int temp;

	temp = *i;
	*i = *j;
	*j = temp;
}


/**
* selection_sort - sorts an in ascending order using
* Selection sort algorithm
* @array: to be sorted
* @size: array size
* Return: Nothing (void)
*/


void selection_sort(int *array, size_t size)
{
	size_t m, n, min_idx;

	if (array == NULL || size < 2)
		return;

	for (m = 0; m < size - 1; m++)
	{
		min_idx = m;
		for (n = m + 1; n < size; n++)
			if (array[n] < array[min_idx])
				min_idx = n;

		if (min_idx != m)
		{
			swap(&array[min_idx], &array[m]);
			print_array(array, size);
		}
	}
}
