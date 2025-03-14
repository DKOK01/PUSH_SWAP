/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_Swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysadeq <aysadeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:06:51 by aysadeq           #+#    #+#             */
/*   Updated: 2025/03/12 22:03:18 by aysadeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}		t_node;

typedef struct s_range
{
	int	*sorted_array;
	int	offset;
	int	size;
	int	start;
	int	end;
}				t_range;

void	print_error_and_exit(t_node **stack);
void	print_stack(t_node *stack);
int		stack_size(t_node *stack);
void	free_stack(t_node **stack);
int		is_sorted(t_node *stack);

t_node	*parse_input(int ac, char **av);
int		is_valid_input(char *str);
int		ft_atoi(const char *str, int *valid);
t_node	*add_to_stack(t_node *head, int num);
char	**ft_split(const char *s, char c);
char	*ft_strchr(const char *s, int c);
t_node	*handle_split_args(char *arg, t_node *stack);
t_node	*handle_normal_args(char *arg, t_node *stack);
void	free_split(char **split_args);

void	swap(t_node **stack);
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);

void	push(t_node **src, t_node **dst);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);

void	rotate(t_node **stack);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);

void	reverse_rotate(t_node **stack);
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);

void	sort_two(t_node **stack_a);
void	sort_three(t_node **stack_a);
void	sort_four_or_five(t_node **stack_a, t_node **stack_b, int size);
int		find_min_index(t_node *stack);
void	move_to_top(t_node **stack, int min_index);

void	large_sort(t_node **a, t_node **b, int size);
void	push_elements_to_a(t_node **a, t_node **b);
void	push_element_to_b(t_node **a, t_node **b, t_range *range);

#endif
