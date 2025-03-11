/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysadeq <aysadeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:51:12 by aysadeq           #+#    #+#             */
/*   Updated: 2025/03/11 20:01:11 by aysadeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}		t_node;

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);

t_node	*parse_input(int ac, char **av);
t_node	*handle_split_args(char *arg, t_node *stack);
t_node	*handle_normal_args(char *arg, t_node *stack);
t_node	*add_to_stack(t_node *head, int num);
int		is_valid_input(char *str);
int		ft_atoi(const char *str, int *valid);
char	**ft_split(char const *s, char c);
void	free_split(char **split_args);

void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);

void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);

void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);

void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);

int		is_sorted(t_node *stack);
void	free_stack(t_node **stack);
void	print_error_and_exit(t_node **stack);
int		ft_strcmp(const char *s1, const char *s2);

#endif