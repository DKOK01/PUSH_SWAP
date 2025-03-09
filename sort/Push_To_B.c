/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_To_B.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysadeq <aysadeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 17:31:52 by aysadeq           #+#    #+#             */
/*   Updated: 2025/03/09 17:33:37 by aysadeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/Push_Swap.h"

void	next_chunk(t_range *range)
{
	if (range->start < range->end - 1)
		range->start += 1;
	if (range->end < range->size - 1)
		range->end += 1;
}

void	push_in_range(t_node **a, t_node **b, t_range *range)
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

void	push_element_to_b(t_node **a, t_node **b, t_range *range)
{
	if (!a || !b || !range)
		return ;
	push_in_range(a, b, range);
}
