#include "sort.h"

/**
* counting_sort - counting sort algorithm
* @array: array with numbers to sort
* @size: size of the array
**/
void counting_sort(int *array, size_t size)
{
	int max, position, *count = NULL, *order = NULL;
	size_t i;

	if (size < 2 || array == NULL)
		return;
	/*Find the maximun value in the array*/
	max = array[0];
	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];
	/*Use malloc(size of the max value) to create a new array for the count*/
	count = malloc(sizeof(int) * (max + 1));
	for (i = 0; i <= (size_t)max; i++)
		count[i] = 0;
	/*Save the counter values of every number in the count array*/
	for (i = 0; i < size; i++)
		count[array[i]] = count[array[i]] + 1;
	/*Sum values in the count array*/
	for (i = 1; i <= (size_t)max; i++)
		count[i] = count[i] + count[i - 1];
	print_array(count, (size_t)max + 1);
	/*use malloc(same size of array) to create array to sort the numbers*/
	order = malloc(sizeof(int) * size);
	for (i = 0; i < size; i++)
	{
		count[array[i]] = count[array[i]] - 1;
		position = count[array[i]];
		order[position] = array[i];
	}
	/*Order the array by the order array*/
	for (i = 0; i < size; i++)
		array[i] = order[i];
	free(count);
	free(order);
}