#include "sort.h"

/**
 * swap_ints - Swapping integers
 * @j: first int
 * @k: second int
 */
void swap_ints(int *j, int *k)
{
	int tmp = *j;

	*j = *k;
	*k = tmp;
}

/**
 * bubble_sort - ascending array of ints
 * @array: ints to sort
 * @size: size
 * Description: Prints an array with every swap
 */

void bubble_sort(int *array, size_t size)
{
	size_t t = 0, len;
	bool bubbley;

	len = size;
	bubbley = false;


	if (array == NULL || size < 2)
		return;

	while (bubbley == false)
	{
		bubbley = true;
		for ( ; t < len - 1; t++)
		{
			if (array[t] > array[t + 1])
			{
				swap_ints(array + t, array + t + 1);
				print_array(array, size);
				bubbley = false;
			}
		}
		len--;
	}
}
