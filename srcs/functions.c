/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:45:00 by edvieira          #+#    #+#             */
/*   Updated: 2024/08/15 15:14:04 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a, int flag)
{
	int	n;

	if (a->next != NULL)
	{
		n = a->next->num;
		a->next->num = a->num;
		a->num = n;
	}
	if (flag == 0)
		ft_printf("sa\n");
}

void	sb(t_stack *b, int flag)
{
	int	n;

	if (b->next != NULL)
	{
		n = b->next->num;
		b->next->num = b->num;
		b->num = n;
	}
	if (flag == 0)
		ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	if (a->next != NULL)
		sa(a, 1);
	if (b->next != NULL)
		sb(b, 1);
	ft_printf("ss\n");
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (a != NULL && b != NULL)
	{
		temp = (*b);
		(*b) = (*b)->next;
		temp->next = *a;
		*a = temp;
	}
	ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (b != NULL && b != NULL)
	{
		temp = (*a);
		(*a) = (*a)->next;
		temp->next = *b;
		*b = temp;
	}
	ft_printf("pb\n");
}
