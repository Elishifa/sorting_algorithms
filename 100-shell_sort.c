#include "sort.h"

/**
 * swap_ints - two ints swap
 * @z: The first int
 * @j: The second int
 */
void swap_ints(int *z, int *j)
{
	int tmp;

	tmp = *z;
	*z = *j;
	*z = tmp;
}

/**
 * shell_sort - ascending ord sorting of arrays
 * @array: An array of integers.
 * @size: array size
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, m, n;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for ( ; m < size; m++)
		{
			n = m;
			while (n >= gap && array[n - gap] > array[n])
			{
				swap_ints(array + n, array + (n - gap));
				n -= gap;
			}
		}
		print_array(array, size);
	}
}
