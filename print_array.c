#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Prints integer arrays
 * @array: printed
 * @size: No of elements in @array
 */
void print_array(const int *array, size_t size)
{
	size_t t = 0;

	while (array && t < size)
	{
		if (t > 0)
			printf(", ");
		printf("%d", array[t]);
		++t;
	}
	printf("\n");
}
