#include "sort.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

/**
 * get_max - gets the maximum value from the array
 * @array: the array
 * @size: size of array
 *
 * Return: maximum value or -1 on fail
 */
int get_max(int *array, size_t size)
{
	int max;
	size_t i = 0;

	if (!array)
		return (-1);

	max = array[0];

	for (; i < size; i++)
	{
		if (max < array[i])
			max = array[i];
	}

	return (max);
}

/**
 * counting_sort - implements counting sort algorithm
 * @array: array
 * @size: size of array
 *
 */
void counting_sort(int *array, size_t size)
{
	int *count_arr, i = 0, hold = 0, temp = 0, k = 0;
	size_t j = 0;
	int max = get_max(array, size);

	if (max < 0 || size < 2)
		return;

	count_arr = malloc(sizeof(int) * (max + 1));

	if (!count_arr)
		return;

	for (; i < max; i++)
		count_arr[i] = 0;

	for (j = 0; j < size; j++)
		count_arr[array[j]]++;

	for (i = 0; i <= max; i++)
	{
		if (count_arr[i])
		{
			temp = hold;
			hold += count_arr[i];
			for (; temp < hold; temp++)
			{
				array[k] = i;
				k++;
			}
			count_arr[i] = hold;

		}
		else
			count_arr[i] = hold;

	}

	print_array(count_arr, (size_t) (max + 1));
	free(count_arr);
}

