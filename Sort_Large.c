/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sort_Large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysadeq <aysadeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:03:59 by aysadeq           #+#    #+#             */
/*   Updated: 2025/03/08 23:14:25 by aysadeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

void	next_chunk(t_range *range)
{
	if (range->start < range->end - 1)
		range->start += 1;
	if (range->end < range->size - 1)
		range->end += 1;
}

void push_in_range(t_node **a, t_node **b, t_range *range)
{
	if (!a || !b || !range)
		return ;
	while (*a)
	{
		if ((*a)->value <= range->sorted_array[range->start])
		{
			pb(a, b);
			rb(b);
			next_chunk(range);
		}
		else if ((*a)->value <= range->sorted_array[range->end])
		{
			pb(a, b);
			if (stack_size(*b) > 2 && (*b)->value < (*b)->next->value)
				sb(b);
			next_chunk(range);
		}
		else
			ra(a);
	}
}

void push_element_to_b(t_node **a, t_node **b, t_range *range)
{
	if (!a || !b || !range)
		return ;
	push_in_range(a, b, range);
}

int find_max_value(t_node *stack)
{
	int max_value;

	max_value = stack->value;
	while (stack)
	{
		if (stack->value > max_value)
			max_value = stack->value;
		stack = stack->next;
	}
	return (max_value);
}

int get_position(t_node *stack, int max_value)
{
	int position;

	position = 0;
	while (stack)
	{
		if (stack->value == max_value)
			return (position);
		position++;
		stack = stack->next;
	}
	return (position);
}

void push_elements_to_a(t_node **a, t_node **b)
{
	int	max_value;
	int	pos;
	int	size;

	if (!a || !b)
		return ;
	while (*b)
	{
		max_value = find_max_value(*b);
		pos = get_position(*b, max_value);
		size = stack_size(*b);
		if (pos <= size / 2)
		{
			while ((*b)->value != max_value)
				rb(b);
		}
		else
		{
			while ((*b)->value != max_value)
				rrb(b);
		}
		pa(a, b);
		if (*b && (*b)->value > (*a)->value)
			ra(a);
	}
}
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
