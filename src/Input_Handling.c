/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Input_Handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysadeq <aysadeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:17:35 by aysadeq           #+#    #+#             */
/*   Updated: 2025/03/09 21:42:43 by aysadeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

t_node	*add_to_stack(t_node *head, int num)
{
	t_node	*new_node;
	t_node	*temp;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = num;
	new_node->next = NULL;
	if (!head)
		return (new_node);
	temp = head;
	while (temp->next)
		temp = temp->next;
	temp->next = new_node;
	return (head);
}

int	is_valid_input(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(const char *str, int *valid)
{
	long	num;
	int		sign;
	int		i;

	num = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		if (num * sign > 2147483647 || num * sign < -2147483648)
		{
			*valid = 0;
			return (0);
		}
		i++;
	}
	return ((int)num * sign);
}

int	has_dublicate(t_node *stack)
{
	t_node	*current;
	t_node	*checker;

	current = stack;
	while (current)
	{
		checker = current->next;
		while (checker)
		{
			if (current->value == checker->value)
				return (1);
			checker = checker->next;
		}
		current = current->next;
	}
	return (0);
}

t_node	*parse_input(int ac, char **av)
{
	t_node	*stack_a;
	int		num;
	int		valid;
	int		i;
	int		j;
	char	**split_args;

	stack_a = NULL;
	i = 1;
	while (i < ac)
	{
		if (ft_strchr(av[i], ' '))
		{
			split_args = ft_split(av[i], ' ');
			if (!split_args)
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
				stack_a = add_to_stack(stack_a, num);
				free(split_args[j]);
				j++;
			}
			free(split_args);
		}
		else
		{
			if (!is_valid_input(av[i]))
				print_error_and_exit();
			valid = 1;
			num = ft_atoi(av[i], &valid);
			if (!valid)
				print_error_and_exit();
			stack_a = add_to_stack(stack_a, num);
		}
		i++;
	}

	if (has_dublicate(stack_a))
		print_error_and_exit();
	return (stack_a);
}
