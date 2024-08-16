/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:01:53 by edvieira          #+#    #+#             */
/*   Updated: 2024/08/16 12:18:28 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*updating_less_moves(int *less_moves, t_stack *a_i)
{
	*less_moves = a_i->moves_needed;
	return (a_i);
}

void	moving_stack(t_stack **a, t_stack **b, int many_nums, int index)
{
	t_stack	*a_i;
	t_stack	*to_move;
	int		less_moves;

	while (--many_nums > 3)
	{
		a_i = *a;
		index = 1;
		less_moves = 2147483647;
		while (a_i != NULL)
		{
			a_i->moves_needed = counting_moves(a_i, *b, many_nums, index);
			a_i->where = index;
			if (a_i->moves_needed < less_moves)
				to_move = updating_less_moves(&less_moves, a_i);
			if (less_moves == 1 || less_moves == 2 || a_i->next == NULL)
			{
				doing_one_move(a, b, to_move, many_nums);
				break ;
			}
			a_i = a_i->next;
			index++;
		}
	}
}

void	sorting_b(t_stack *b, int many_nums)
{
	t_stack	*b_i;
	t_stack	*save;
	int		i;

	i = 0;
	b_i = b;
	save = b;
	if (check_sorted_b(b) == 0)
		return ;
	while (b_i != NULL)
	{
		if (b_i->num > save->num)
		{
			save = b_i;
			save->moves_needed = i;
		}
		i++;
		b_i = b_i->next;
	}
	if (save->moves_needed >= (many_nums / 2))
		while (++save->moves_needed <= many_nums)
			rrb(b, 0);
	else
		while (--save->moves_needed >= 0)
			rb(b, 0);
}

void	moving_back(t_stack **a, t_stack **b, int many_b)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < many_b)
	{
		if (last_num(*a) > (*b)->num && j < 3)
		{
			rra(*a, 0);
			j++;
		}
		else
		{
			pa(a, b);
			i++;
		}
	}
	if (last_num(*a) < (*a)->num)
		rra(*a, 0);
	while (check_sorted_a(*a) == 1)
		rra(*a, 0);
}

void	doing_one_move(t_stack **a, t_stack **b, t_stack *to_send, int many_a)
{
	int	many_b;

	many_b = count_nums(*b);
	if (to_send->where_to >= ((many_b / 2) + 1))
		while (++to_send->where_to < (many_b + 1))
			rrb(*b, 0);
	else
		while (--to_send->where_to >= 0)
			rb(*b, 0);
	if (to_send->where > ((many_a / 2) + 1))
	{
		while (++to_send->where <= (many_a + 1))
			rra(*a, 0);
		pb(a, b);
	}
	else
	{
		while (--to_send->where >= 1)
			ra(*a, 0);
		pb(a, b);
	}
}
