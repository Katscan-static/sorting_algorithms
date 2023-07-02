#include "sort.h"

/**
 * swap - swap two ints in an array
 * @fir: first int
 * @sec: second value
 */
void swap(int *fir, int *sec)
{
	int temp;

	temp = *fir;
	*fir = *sec;
	*sec = temp;
}
/**
 * bitonicmerge - Merges the array
 * @array: Array to sort
 * @size: size of the array
 * @low: Starting index
 * @count: Size of sequence to sort
 * @dir: Dicetion to sort
 */
void bitonicmerge(int *array, size_t size, size_t low, size_t count, char dir)
{
	size_t i, j = count / 2;

	if (count > 1)
	{
		for (i = low; i < low + j; i++)
		{
			if ((dir == UP && array[i] > array[i + j]) ||
					(dir == DOWN && array[i] < array[i + j]))
				swap(array + i, array + i + j);
		}
		bitonicmerge(array, size, low, j, dir);
		bitonicmerge(array, size, low + j, j, dir);
	}
}

/**
 * bitonicsort - Sorts the array
 * @array: Array to sort
 * @size: size of the array
 * @low: Starting index
 * @count: Size of sequence to sort
 * @dir: Dicetion to sort
 */
void bitonicsort(int *array, size_t size, size_t low, size_t count, char dir)
{
	size_t k = count / 2;
	char *str = (dir == UP) ? "UP" : "DOWN";

	if (count > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", count, size, str);
		print_array(array + low, count);

		bitonicsort(array, size, low, k, UP);
		bitonicsort(array, size, low + k, k, DOWN);
		bitonicmerge(array, size, low, count, dir);

		printf("Result [%lu/%lu] (%s):\n", count, size, str);
		print_array(array + low, count);
	}
}

/**
 * bitonic_sort - Sorts the array
 * @array: Array to sort
 * @size: size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	bitonicsort(array, size, 0, size, UP);
}
