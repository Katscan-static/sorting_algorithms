#include "sort.h"

/**
 * merge - merge the two sub arrays
 * @array: array to merge
 * @lb: lower bound
 * @ub: upper bound
 * @mid: mid value
 * @merged: sorted array
 */
void merge(int *array, int lb, int mid, int ub, int *merged)
{
	int i = lb, j = mid, k = 0;

	printf("Merging...\n[left]: ");
	print_array(array + lb, mid - lb);
	printf("[right]: ");
	print_array(array + mid, ub - mid);
	while (i < mid && j < ub)
	{
		if (array[i] < array[j])
		{
			merged[k] = array[i];
			i++;
		}
		else
		{
			merged[k] = array[j];
			j++;
		}
		k++;
	}
	while (i < mid)
	{
		merged[k] = array[i];
		i++, k++;
	}
	while (j < ub)
	{
		merged[k] = array[j];
		j++, k++;
	}
	for (i = lb, k = 0; i < ub; i++)
		array[i] = merged[k++];
	printf("[Done]: ");
	print_array(array + lb, ub - lb);
}

/**
 * mergesort - divides the array into sub arrays
 * @array: array to merge
 * @lb: lower bound
 * @ub: upper bound
 * @merged: sorted array
 */
void mergesort(int *array, int lb, int ub, int *merged)
{
	int mid;

	mid = (lb + ub) / 2;
	if (ub - lb > 1)
	{
		mergesort(array, lb, mid, merged);
		mergesort(array, mid, ub, merged);
		merge(array, lb, mid, ub, merged);
	}
}

/**
 * merge_sort - Merge sort algorithm
 * @array: array to merge
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *merged;

	if (!array || size < 2)
		return;

	merged = malloc(sizeof(int) * size);
	if (!merged)
		return;

	mergesort(array, 0, size, merged);

	free(merged);
}
