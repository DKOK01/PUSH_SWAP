/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sort_Small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysadeq <aysadeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 15:11:56 by aysadeq           #+#    #+#             */
/*   Updated: 2025/03/04 20:51:32 by aysadeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

void	sort_two(t_node **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
}

void	sort_three(t_node **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->value;
	second = (*stack_a)->next->value;
	third = (*stack_a)->next->next->value;
	if (first > second && second < third && first < third)
		sa(stack_a);
	else if (first > second && second > third)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (first > second && second < third && first > third)
		ra(stack_a);
	else if (first < second && second > third && first < third)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (first < second && second > third && first > third)
		rra(stack_a);
}

void	sort_four_or_five(t_node **stack_a, t_node **stack_b, int size)
{
	int	min_index;

	while (size > 3)
	{
		min_index = find_min_index(*stack_a);
		move_to_top(stack_a, min_index);
		pb(stack_a, stack_b);
		size--;
	}
	sort_three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}

int	find_min_index(t_node *stack)
{
	int	min;
	int	index;
	int	i;

	min = stack->value;
	index = 0;
	i = 0;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			index = i;
		}
		stack = stack->next;
		i++;
	}
	return (index);
}

void	move_to_top(t_node **stack_a, int index)
{
	int	size;

	size = stack_size(*stack_a);
	if (index <= size / 2)
	{
		while (index--)
			ra(stack_a);
	}
	else
	{
		while (index++ < size)
			rra(stack_a);
	}
}
