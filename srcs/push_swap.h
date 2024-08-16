/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:39:34 by edvieira          #+#    #+#             */
/*   Updated: 2024/08/16 12:19:56 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <stdlib.h>
# include "libs/ft_printf/ft_printf.h"
# include "libs/libft/libft.h"
# include "libs/gnl/get_next_line.h"

typedef struct s_stack
{
	int				num;
	int				moves_needed;
	int				where;
	int				where_to;
	struct s_stack	*last;
	struct s_stack	*next;
}		t_stack;

t_stack	*ft_new_node(int num);
t_stack	*updating_less_moves(int *less_moves, t_stack *a_i);

void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	sa(t_stack *a, int flag);
void	sb(t_stack *b, int flag);
void	ss(t_stack *a, t_stack *b);
void	ra(t_stack *a, int flag);
void	rb(t_stack *b, int flag);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a, int flag);
void	rrb(t_stack *b, int flag);
void	rrr(t_stack *a, t_stack *b);

void	sorting_b(t_stack *b, int many_nums);
void	moving_back(t_stack **a, t_stack **b, int many_b);
void	moving_stack(t_stack **a, t_stack **b, int many_nums, int index);
void	doing_one_move(t_stack **a, t_stack **b, t_stack *to_send, int many_a);

void	order3(t_stack *a);
void	check_dup(t_stack *a);
void	order_more(t_stack *a);
void	free_stack(t_stack *x);
void	organize_nums(t_stack *a);
void	order4(t_stack *a);
void	separating_nums(char *str, t_stack **a);
void	multiple_entrence(int ac, char **av, t_stack **a);

long	ft_atol(char *str, int flag, t_stack *a);
int		check_atol(long num);
int		count_nums(t_stack *a);
int		last_num(t_stack *node);
int		free_to_end2(t_stack *a);
int		check_entrence(char *str);
int		check_sorted_b(t_stack *b);
int		check_sorted_a(t_stack *a);
int		is_larger(t_stack *a_i, t_stack *b);
int		is_shorter(t_stack *a_i, t_stack *b);
int		free_to_end(char **nums, t_stack *temp);
int		in_the_middle(t_stack *a_i, t_stack *b, int i);
int		check_entrence_repeat(char **nums, t_stack *a);
int		counting_moves(t_stack *a_i, t_stack *b, int many_a, int index);

char	*to_transform(char *str);

#endif
