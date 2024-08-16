/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:13:38 by edvieira          #+#    #+#             */
/*   Updated: 2024/08/15 15:19:30 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a, int flag)
{
	int	n;

	if (a->next != NULL)
	{
		n = a->num;
		while (a->next != NULL)
		{
			a->num = a->next->num;
			a = a->next;
		}
		a->num = n;
	}
	if (flag == 0)
		ft_printf("ra\n");
}

void	rb(t_stack *b, int flag)
{
	int	n;

	if (b->next != NULL)
	{
		n = b->num;
		while (b->next != NULL)
		{
			b->num = b->next->num;
			b = b->next;
		}
		b->num = n;
	}
	if (flag == 0)
		ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	if (a->next != NULL)
		ra(a, 1);
	if (b->next != NULL)
		rb(b, 1);
	ft_printf("rr\n");
}

void	rra(t_stack *a, int flag)
{
	t_stack	*temp;
	int		change;
	int		save;

	if (a->next != NULL)
	{
		temp = a;
		save = temp->num;
		while (temp->next != NULL)
		{
			change = save;
			save = temp->next->num;
			temp->next->num = change;
			temp = temp->next;
		}
		a->num = save;
	}
	if (flag == 0)
		ft_printf("rra\n");
}

void	rrb(t_stack *b, int flag)
{
	t_stack	*temp;
	int		change;
	int		save;

	if (b->next != NULL)
	{
		temp = b;
		save = temp->num;
		while (temp->next != NULL)
		{
			change = save;
			save = temp->next->num;
			temp->next->num = change;
			temp = temp->next;
		}
		b->num = save;
	}
	if (flag == 0)
		ft_printf("rrb\n");
}
