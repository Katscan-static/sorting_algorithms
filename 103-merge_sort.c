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
	int i = lb, j = mid + 1, k = lb, x;

	printf("Merging...\n[left]: ");
	for (x = lb; x <= mid; x++)
		printf("%d ", array[x]);
	printf("\n");
	printf("[right]: ");
	for (x = j; x <= ub; x++)
		printf("%d ", array[x]);
	printf("\n");
	while (i <= mid && j <= ub)
	{
		if (array[i] <= array[j])
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
	while (i <= mid)
	{
		merged[k] = array[i];
		i++, k++;
	}
	while (j <= ub)
	{
		merged[k] = array[j];
		j++, k++;
	}
	printf("[Done]: ");
	for (x = lb; x <= ub; x++)
		printf("%d ", merged[x]);
	printf("\n");
	for (k = lb; k <= ub; k++)
		array[k] = merged[k];
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
	if (lb < ub)
	{
		mergesort(array, lb, mid, merged);
		mergesort(array, mid + 1, ub, merged);
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

	mergesort(array, 0, size - 1, merged);

	free(merged);
}
