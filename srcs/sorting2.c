/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:32:13 by edvieira          #+#    #+#             */
/*   Updated: 2024/08/16 11:21:39 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted_b(t_stack *b)
{
	t_stack	*temp1;
	t_stack	*temp2;

	temp2 = b;
	while (temp2 != NULL)
	{
		temp1 = temp2;
		while (temp1 != NULL)
		{
			if (temp1->num > temp2->num)
				return (1);
			temp1 = temp1->next;
		}
		temp2 = temp2->next;
	}
	return (0);
}

int	check_sorted_a(t_stack *a)
{
	t_stack	*temp1;
	t_stack	*temp2;

	while (a->next != NULL)
		a = a->next;
	temp2 = a;
	while (temp2 != NULL)
	{
		temp1 = temp2;
		while (temp1 != NULL)
		{
			if (temp2->num < temp1->num)
				return (1);
			temp1 = temp1->last;
		}
		temp2 = temp2->last;
	}
	return (0);
}

int	in_the_middle(t_stack *a_i, t_stack *b, int i)
{
	t_stack	*closest;

	closest = NULL;
	while (b != NULL)
	{
		b->where_to = i;
		if (a_i->num < last_num(b) && a_i->num > b->num && i == 0)
			closest = b;
		if (b->next != NULL)
		{
			if (b->num > a_i->num && a_i->num > b->next->num)
			{
				if (closest == NULL)
					closest = b->next;
				if ((a_i->num - b->num) < (a_i->num - closest->num))
				{
					b->where_to++;
					closest = b;
				}
			}
		}
		i++;
		b = b->next;
	}
	return (closest->where_to);
}

int	is_larger(t_stack *a_i, t_stack *b)
{
	t_stack	*larger;
	int		i;

	i = 0;
	larger = b;
	while (b != NULL)
	{
		b->where_to = i;
		if (b->num > larger->num)
			larger = b;
		b = b->next;
		i++;
	}
	if (larger->num < a_i->num)
		return (larger->where_to);
	return (-1);
}

int	is_shorter(t_stack *a_i, t_stack *b)
{
	t_stack	*shorter;
	int		i;

	i = 0;
	shorter = b;
	while (b != NULL)
	{
		b->where_to = i;
		if (b->num < shorter->num)
			shorter = b;
		b = b->next;
		i++;
	}
	if (shorter->num > a_i->num)
	{
		shorter->where_to++;
		return (shorter->where_to);
	}
	return (-1);
}
