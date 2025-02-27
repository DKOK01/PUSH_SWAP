/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysadeq <aysadeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:12:29 by aysadeq           #+#    #+#             */
/*   Updated: 2025/02/27 14:26:46 by aysadeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

void	print_error_and_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	print_stack(t_node *stack)
{
	while (stack)
	{
		printf("|    [%d]    |\n", stack->value);
		stack = stack->next;
	}
}
