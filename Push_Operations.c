/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_Operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysadeq <aysadeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:57:14 by aysadeq           #+#    #+#             */
/*   Updated: 2025/02/27 13:42:23 by aysadeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

void	push(t_node **src, t_node **dst)
{
	t_node	*top;

	if (!(*src))
		return ;
	top = *src;
	*src = top->next;
	top->next = *dst;
	*dst = top;
}

void	pa(t_node **stack_a, t_node **stack_b)
{
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
}
