#include "sort.h"

/**
 * knuth_sequence - find the number greater and less than @size
 * using the knuth sequence
 * @n: limit number
 *
 * Return: the max number find in the sequence
*/
size_t knuth_sequence(size_t n)
{
	size_t i = 1;

	while (i < n)
	{
		i = i * 3 + 1;
	}
	i = i / 3;
	if (i == 0)
		return (1);
	return (i);
}

/**
 * if_swap - if not swap a number this function change the interval
 * @array: the array to sort
 * @size: the size of the array
 * @inter: pointer to interval
 * @no_swap: indicates if there was an swap
 *
 * Return: 1 if is sorted
*/
int if_swap(int *array, size_t size, size_t *inter, int no_swap)
{
	if (no_swap)
	{
		if (*inter <= 1)
		{
			print_array(array, size);
			return (1);
		}
		*inter = knuth_sequence(*inter);
	}

	return (0);
}

/**
 * shell_sort - sorts a list using the shell sort algorithm
 * @array: the array to sort
 * @size: the size of the array
 *
 * Return: na
*/
void shell_sort(int *array, size_t size)
{
	size_t i_low = 0, i_max = 0, inter = 0;
	size_t temp = 0, inter_change = 0;
	int no_sort = 1, no_swap = 1;

	if (!array || size < 2)
		return;

	inter = knuth_sequence(size - 1);
	i_max += inter;
	inter_change = inter;

	while (no_sort)
	{
		no_swap = 1;
		while (i_max < size)
		{
			if (array[i_low] > array[i_max])
			{
				temp = array[i_low];
				array[i_low] = array[i_max];
				array[i_max] = temp;
				no_swap = 0;
			}
			i_low++;
			i_max++;
		}

		if (if_swap(array, size, &inter, no_swap))
			return;

		i_low = 0;
		i_max = 0 + inter;
		if (inter != inter_change)
		{
			print_array(array, size);
			inter_change = inter;
		}
	}
}
