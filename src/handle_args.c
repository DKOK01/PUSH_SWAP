/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysadeq <aysadeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:47:05 by aysadeq           #+#    #+#             */
/*   Updated: 2025/03/11 14:16:55 by aysadeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

void	free_split(char **split_args)
{
	int	i;

	if (!split_args)
		return ;
	i = 0;
	while (split_args[i])
	{
		free(split_args[i]);
		split_args[i] = NULL;
		i++;
	}
	free(split_args);
	split_args = NULL;
}

void	handle_split_error(char **split_args, t_node **stack)
{
	free_split(split_args);
	print_error_and_exit(stack);
}

t_node	*handle_split_args(char *arg, t_node *stack)
{
	char	**split_args;
	int		num;
	int		valid;
	int		j;

	split_args = ft_split(arg, ' ');
	if (!split_args || !split_args[0])
		handle_split_error(split_args, &stack);
	j = 0;
	while (split_args[j])
	{
		if (!is_valid_input(split_args[j]))
			handle_split_error(split_args, &stack);
		valid = 1;
		num = ft_atoi(split_args[j], &valid);
		if (!valid)
			handle_split_error(split_args, &stack);
		stack = add_to_stack(stack, num);
		j++;
	}
	free_split(split_args);
	return (stack);
}

t_node	*handle_normal_args(char *arg, t_node *stack)
{
	int	num;
	int	valid;

	if (!is_valid_input(arg))
		print_error_and_exit(&stack);
	valid = 1;
	num = ft_atoi(arg, &valid);
	if (!valid)
		print_error_and_exit(&stack);
	return (add_to_stack(stack, num));
}
