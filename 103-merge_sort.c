#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * TDMerge - sorts and merges the sub arrays in source
 * @start: starting index (inclusive) for the left sub array
 * @middle: end index (exclusive) for the left sub array and
 * starting index (inclusive) for the right sub array
 * @end: end index (exclusive) for the right sub array
 * @dest: data destination
 * @source: data src
 *
 * Return: void
 */

void TDMerge(size_t start, size_t center, size_t end, int *dest, int *source)
{
	size_t m, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(source + start, center - start);
	printf("[right]: ");
	print_array(source + center, end - center);
	m = start;
	j = center;
	for (k = start; k < end; k++)
	{
		if (m < center && (j >= end || source[m] <= source[j]))
		{
			dest[k] = source[m];
			m++;
		}
		else
		{
			dest[k] = source[j];
			j++;
		}
	}
	printf("[Done]: ");
	print_array(dest + start, end - start);
}

/**
 * TDSplitMerge - recursively splits the array and merges the sorted arrays
 * @start: starting index (inclusive)
 * @end: end index (exclusive)
 * @array: the array to sort
 * @copy: a copy of the array
 *
 * Return: void
 */

void TDSplitMerge(size_t start, size_t end, int *array, int *copy)
{
	size_t center;

	if (end - start < 2)
		return;
	center = (start + end) / 2;
	TDSplitMerge(start, center, array, copy);
	TDSplitMerge(center, end, array, copy);
	TDMerge(start, center, end, array, copy);
	for (center = start; center < end; center++)
		copy[center] = array[center];
}

/**
 * merge_sort - sorts array of ints in ascending order using
 * Merge sort algorithm
 * @array: array to sort
 * @size: array size
 *
 * Return: void
 */

void merge_sort(int *array, size_t size)
{
	size_t j;
	int *copy;

	if (array == NULL || size < 2)
		return;
	copy = malloc(sizeof(int) * size);
	if (copy == NULL)
		return;
	for (j = 0; j < size; j++)
		copy[j] = array[j];
	TDSplitMerge(0, size, array, copy);
	free(copy);
}
