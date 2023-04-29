#include "sort.h"


void swap(int *z, int *j);
int lomuto_partition(int *array, size_t size, int lower, int upper);
void lomuto_sort(int *array, size_t size, int lower, int upper);
void quick_sort(int *array, size_t size);


/**
 * swap - two ints swap
 * @z: first int
 * @j: second int
 */
void swap(int *z, int *j)
{
	int temp = *z;
	*z = *j;
	*j = temp;
}


/**
 * lomuto_partition - subset of int array
 * @array: array being sorted
 * @size:  array size
 * @lower: starting ind
 * @upper: ending ind
 * Return: final partition ind (success)
 */


int lomuto_partition(int *array, size_t size, int lower, int upper)
{
	int *pivot, first, last;

	pivot = array + upper;
	for (last = first = lower; first < upper; first++)
	{
		if (array[first] < *pivot)
		{
			if (last < first)
			{
				swap(array + first, array + last);
				print_array(array, size);
			}
			last++;
		}
	}

	if (array[last] > *pivot)
	{
		swap(array + last, pivot);
		print_array(array, size);
	}

	return (last);
}


/**
 * lomuto_sort - implements the quicksort algorithm through recursion
 * @array: needs sorting(to be)
 * @size: array size
 * @lower: starting ind 
 * @upper: ending ind
 */


void lomuto_sort(int *array, size_t size, int lower, int upper)
{
	int port;

	if (upper - lower > 0)
	{
		port = lomuto_partition(array, size, lower, upper);
		lomuto_sort(array, size, lower, port - 1);
		lomuto_sort(array, size, port + 1, upper);
	}
}


/**
 * quick_sort - ascending order integers sorting
 * @array: to be sorted
 * @size: array size
 */


void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
