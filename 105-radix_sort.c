#include "sort.h"

/**
 * radixsort - Radix counting sort
 * @array: Array to sort
 * @size: size of the array
 * @dig: digit to be sorted 1(lsb), 10(mid), 100(first)
 * @buf: Dynamic buffer to store consecutively soeted elements
 *
 * Description: This Algorithm consecutively applies counting sort
 * to sort the array. It's mostly used to sort arrays with numbers with
 * large digits or letters
 */
void radixsort(int *array, size_t size, int dig, int *buf)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t j;

	for (j = 0; j < size; j++)
		count[(array[j] / dig) % 10] += 1;
	/* Cumualtive count, used to determine the correct */
	/* position of each element in the output array. */
	for (j = 0; j < 10; j++)
		if (j > 0)
			count[j] += count[j - 1];
	for (j = size - 1; (int)j >= 0; j--)
	{
		buf[count[(array[j] / dig) % 10] - 1] = array[j];
		count[(array[j] / dig) % 10] -= 1;
	}

	for (j = 0; j < size; j++)
		array[j] = buf[j];
}

/**
 * radix_sort - Radix sorting algorithm
 * @array: Array to sort
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max, dig, *buf;
	size_t i;

	if (!array || size < 2)
		return;

	buf = malloc(sizeof(int) * size);
	if (!buf)
		return;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	for (dig = 1; max / dig > 0; dig *= 10)
	{
		radixsort(array, size, dig, buf);
		print_array(array, size);
	}

	free(buf);
}
