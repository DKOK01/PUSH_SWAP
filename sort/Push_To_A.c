/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_To_A.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysadeq <aysadeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 17:30:18 by aysadeq           #+#    #+#             */
/*   Updated: 2025/03/14 13:42:09 by aysadeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/Push_Swap.h"

int	find_max_value(t_node *stack)
{
	int	max_value;

	max_value = stack->value;
	while (stack)
	{
		if (stack->value > max_value)
			max_value = stack->value;
		stack = stack->next;
	}
	return (max_value);
}

int	get_position(t_node *stack, int max_value)
{
	int	position;

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

void	push_elements_to_a(t_node **a, t_node **b)
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
