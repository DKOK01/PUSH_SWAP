/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_Swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysadeq <aysadeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:17:04 by aysadeq           #+#    #+#             */
/*   Updated: 2025/02/26 15:56:31 by aysadeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

int	main(int ac, char **av)
{
	t_node	*stack_a;

	if (ac < 2)
		return (0);
	stack_a = parse_input(ac, av);
	printf("Stack A:\n");
	print_stack(stack_a);
	return (0);
}
