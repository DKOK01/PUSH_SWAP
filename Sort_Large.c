/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sort_Large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysadeq <aysadeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:59:54 by aysadeq           #+#    #+#             */
/*   Updated: 2025/03/04 17:25:47 by aysadeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

int	get_max_bets(t_node *stack)
{
	int		max;
	int		bets;

	max = stack->value;
	bets = 0;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	while ((max >> bets) != 0)
		bets++;
	return (bets);
}

void	radix_sort(t_node **stack_a, t_node **stack_b, int size)
{
	int		max_bets;
	int		i;
	int		j;
	int		num;

	max_bets = get_max_bets(*stack_a);
	i = 0;
	while (i < max_bets)
	{
		j = 0;
		while (j < size)
		{
			num = (*stack_a)->value;
			if (!((num >> i) & 1))
				pb(stack_a, stack_b);
			else
				ra(stack_a);
			j++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		i++;
	}
}
