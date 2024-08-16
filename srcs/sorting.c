/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:16:22 by edvieira          #+#    #+#             */
/*   Updated: 2024/08/16 11:54:30 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	counting_moves(t_stack *a_i, t_stack *b, int many_a, int index)
{
	int	many_b;
	int	where_to_move;

	many_b = count_nums(b);
	if (is_larger(a_i, b) != -1)
		where_to_move = is_larger(a_i, b);
	else if (is_shorter(a_i, b) != -1)
		where_to_move = is_shorter(a_i, b);
	else
		where_to_move = in_the_middle(a_i, b, 0);
	a_i->where_to = where_to_move;
	if (where_to_move > (many_b / 2))
		where_to_move = many_b - where_to_move;
	if (index > ((many_a / 2) + 1))
		index = many_a - index + 2;
	return (index + where_to_move);
}

void	order_more(t_stack *a)
{
	t_stack	*b;

	b = NULL;
	if (check_sorted_a(a) == 0)
	{
		free_stack(a);
		exit(EXIT_SUCCESS);
	}
	pb(&a, &b);
	pb(&a, &b);
	moving_stack(&a, &b, (count_nums(a) + 1), 0);
	sorting_b(b, count_nums(b));
	order3(a);
	moving_back(&a, &b, count_nums(b));
	free_stack(a);
	exit(EXIT_SUCCESS);
}

void	order4(t_stack *a)
{
	t_stack	*b;

	b = NULL;
	if (check_sorted_a(a) == 0)
	{
		free_stack(a);
		exit(EXIT_SUCCESS);
	}
	pb(&a, &b);
	order3(a);
	moving_back(&a, &b, count_nums(b));
}

void	order3(t_stack *a)
{
	t_stack	*t;

	t = a->next;
	if (t->num < t->last->num && t->next->num < t->last->num)
		ra(a, 0);
	if (t->last->num < t->num && t->next->num < t->num)
		rra(a, 0);
	if (t->num < t->last->num && t->last->num < t->next->num)
		sa(a, 0);
}

void	organize_nums(t_stack *a)
{
	int	many_nums;

	many_nums = count_nums(a);
	if (many_nums == 1)
		return ;
	else if (many_nums == 2)
	{
		if (a->next->num < a->num)
			sa(a, 0);
	}
	else if (many_nums == 3)
		order3(a);
	else if (many_nums == 4)
		order4(a);
	else
		order_more(a);
}
