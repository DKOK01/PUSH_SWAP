/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sort_Large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysadeq <aysadeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:03:59 by aysadeq           #+#    #+#             */
/*   Updated: 2025/03/09 17:36:26 by aysadeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/Push_Swap.h"

int	*stack_to_array(t_node *stack, int size)
{
	int	*array;
	int	i;

	array = (int *)malloc(sizeof(int) * size);
	if (!array)
		return (NULL);
	i = 0;
	while (i < size)
	{
		array[i] = stack->value;
		stack = stack->next;
		i++;
	}
	return (array);
}

void	sorted_array(int *array, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] > array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	find_offset(int size)
{
	if (size <= 100)
		return (size / 6);
	else if (size <= 500)
		return (size / 12);
	else
		return (size / (size / 2));
}

void	init_range(t_node **a, t_range *range, int size)
{
	int	*array;

	array = stack_to_array(*a, size);
	if (!array)
		return ;
	sorted_array(array, size);
	range->offset = find_offset(size);
	range->sorted_array = array;
	range->size = size;
	range->start = 0;
	range->end = range->offset;
}

void	large_sort(t_node **a, t_node **b, int size)
{
	t_range	*range;

	range = (t_range *)malloc(sizeof(t_range));
	if (!range)
		return ;
	init_range(a, range, size);
	push_element_to_b(a, b, range);
	push_elements_to_a(a, b);
	free(range->sorted_array);
	free(range);
}
