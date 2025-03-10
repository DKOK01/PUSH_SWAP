/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysadeq <aysadeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:47:05 by aysadeq           #+#    #+#             */
/*   Updated: 2025/03/10 15:57:48 by aysadeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

t_node	*handle_split_args(char *arg, t_node *stack)
{
	char	**split_args;
	int		num;
	int		valid;
	int		j;

	split_args = ft_split(arg, ' ');
	if (!split_args || !split_args[0])
		print_error_and_exit();
	j = 0;
	while (split_args[j])
	{
		if (!is_valid_input(split_args[j]))
			print_error_and_exit();
		valid = 1;
		num = ft_atoi(split_args[j], &valid);
		if (!valid)
			print_error_and_exit();
		stack = add_to_stack(stack, num);
		free(split_args[j]);
		j++;
	}
	free(split_args);
	return (stack);
}

t_node	*handle_normal_args(char *arg, t_node *stack)
{
	int	num;
	int	valid;

	if (!is_valid_input(arg))
		print_error_and_exit();
	valid = 1;
	num = ft_atoi(arg, &valid);
	if (!valid)
		print_error_and_exit();
	return (add_to_stack(stack, num));
}
