#include "sort.h"

/**
 * swap - swap values of an array
 * @first: First value
 * @sec: Second value
 */
void swap(int *first, int *sec)
{
	int temp = *first;
	*first = *sec;
	*sec = temp;
}

/**
 * heapify - This builds ups the max heap
 * @array: array of v
 * @n: Size of the array
 * @i: Node/index of particular of the array
 *
 * Description: This builds the heap, and follows the rules of max heap
 * whenever it adds or removes a value, ie the parent values must
 * be greater or equal to the child but not less than
 */
void heapify(int *array, int n, int i)
{
	int largest = i;
	int left = (2 * i) + 1;
	int right = (2 * i) + 2;

	while (left < n && array[left] > array[largest])
		largest = left;
	while (right < n && array[right] > array[largest])
		largest = right;
	if (largest != i)
	{
		swap(&array[i], &array[largest]);
		print_array(array, n);
		heapify(array, n, largest);
	}
}

/**
 * heap_sort - sorts an array of integer using heap sort algorithm
 * @array: Array to sort
 * @size: size of the array
 *
 * Description: array is sorted when elements are are been deleted
 * from a heap. So first you build the heap then you started deleting
 * the elements one by one
 */
void heap_sort(int *array, size_t size)
{
	int first = 0, i;
	int siz = size - 1;

	if (!array || size < 2)
		return;
	/* Building the max heap */
	for (i = (size / 2) - 1 ; i >= 0; i--)
		heapify(array, size, i);
	/* Deleting elements from max heap */
	for (i = siz; i > 0; i--)
	{
		swap(&array[first], &array[i]);
		print_array(array, size);
		heapify(array, i, first);
	}
}
