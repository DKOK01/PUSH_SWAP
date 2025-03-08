/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_Swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysadeq <aysadeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:17:04 by aysadeq           #+#    #+#             */
/*   Updated: 2025/03/08 23:12:49 by aysadeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"


void	push_swap(t_node **stack_a, t_node **stack_b)
{
	int	size;


	size = stack_size(*stack_a);
	if (is_sorted(*stack_a))
		return ;
	else if (size == 1)
		return ;
	else if (size == 2)
		sort_two(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4 || size == 5)
		sort_four_or_five(stack_a, stack_b, size);
	else
		large_sort(stack_a, stack_b, size);
}

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;

	if (ac < 2)
		return (1);
	stack_a = parse_input(ac, av);
	stack_b = NULL;
	// printf("---stack A---\n");
	// print_stack(stack_a);
	// printf("---stack B---\n");
	// print_stack(stack_b);
	push_swap(&stack_a, &stack_b);
	// printf("---stack A---\n");
	// print_stack(stack_a);
	free_stack(&stack_a);
	return (0);
}
