#include "sort.h"

/**
 * shell_sort - Sorts the given array using the shell sort alg
 * @array: Array to sort
 * @size: Size of array
 * Description: This is an optimized form of insertion sort, aimed to reduce
 * the num of computations/comparisons in insertion, by using gap. When
 * gap == 0 shell_sort becomes completely an nsertion sort algorithm
 */
void shell_sort(int *array, size_t size)
{
	size_t interval, i, j;
	int temp;

	if (!array || size < 2)
		return;

	/*using knuth's sequence*/
	interval = 1;
	while (interval < size / 3)
		interval = (interval * 3) + 1;

	while (interval > 0)
	{
		for (i = interval; i < size; i++)
		{
			temp = array[i];
			j = i;
			while (j >= interval && array[j - interval] > temp)
			{
				array[j] = array[j - interval];
				j -= interval;
			}
			array[j] = temp;
		}
		interval = (interval - 1) / 3;

		print_array(array, size);
	}
}
