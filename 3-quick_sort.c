#include <stddef.h>
#include "sort.h"

/**
 * swap - swap two numbers
 *
 * @a: first number
 * @b: second number
 *
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - finds the partition
 * @array: array
 * @low: low position in array
 * @high: highest posistion of array
 * @size: size of array
 *
 * Return: index of partition
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high], i = low - 1, j = low;

	for (; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if ((i + 1) != high)
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);

}

/**
 * quicksort - sort using recursive partition
 *
 * @array: array
 * @low: lowest position of array
 * @high: highest position of array
 * @size: size of array
 *
 */
void quicksort(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivotIndex = partition(array, low, high, size);

		quicksort(array, low, pivotIndex - 1, size);
		quicksort(array, pivotIndex + 1, high, size);
	}
}

/**
 * quick_sort - quicksort
 * @array: array
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}

