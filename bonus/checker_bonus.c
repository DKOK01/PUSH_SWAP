/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysadeq <aysadeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:16:54 by aysadeq           #+#    #+#             */
/*   Updated: 2025/03/11 21:31:45 by aysadeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	apply_moves(t_node **a, t_node **b, char *move)
{
	if (!ft_strcmp(move, "sa\n"))
		return (sa(a), 1);
	else if (!ft_strcmp(move, "sb\n"))
		return (sb(b), 1);
	else if (!ft_strcmp(move, "ss\n"))
		return (ss(a, b), 1);
	else if (!ft_strcmp(move, "pa\n"))
		return (pa(a, b), 1);
	else if (!ft_strcmp(move, "pb\n"))
		return (pb(a, b), 1);
	else if (!ft_strcmp(move, "ra\n"))
		return (ra(a), 1);
	else if (!ft_strcmp(move, "rb\n"))
		return (rb(b), 1);
	else if (!ft_strcmp(move, "rr\n"))
		return (rr(a, b), 1);
	else if (!ft_strcmp(move, "rra\n"))
		return (rra(a), 1);
	else if (!ft_strcmp(move, "rrb\n"))
		return (rrb(b), 1);
	else if (!ft_strcmp(move, "rrr\n"))
		return (rrr(a, b), 1);
	else
		return (0);
}

void	read_moves(t_node **a, t_node **b)
{
	char	*move;

	move = get_next_line(0);
	while (move)
	{
		if (!apply_moves(a, b, move))
		{
			free(move);
			get_next_line(-1);
			print_error_and_exit(a);
		}
		free(move);
		move = get_next_line(0);
	}
}

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;

	if (ac < 2)
		return (0);
	stack_a = parse_input(ac, av);
	stack_b = NULL;
	read_moves(&stack_a, &stack_b);
	if (is_sorted(stack_a) && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
