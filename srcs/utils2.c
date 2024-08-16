/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 08:59:15 by edvieira          #+#    #+#             */
/*   Updated: 2024/08/16 12:18:36 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	last_num(t_stack *node)
{
	while (node->next != NULL)
		node = node->next;
	return (node->num);
}

long	ft_atol(char *str, int flag, t_stack *a)
{
	long	num;
	int		signal;
	int		i;

	i = 0;
	num = 0;
	signal = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signal = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	if (flag == 0)
		free(str);
	if (check_atol(num * signal) == 1 && flag == 0)
		exit (free_to_end2(a));
	return (num * signal);
}

int	count_nums(t_stack *a)
{
	t_stack	*temp;
	int		i;

	temp = a;
	i = 0;
	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

void	rrr(t_stack *a, t_stack *b)
{
	if (a->next != NULL)
		rra(a, 1);
	if (b->next != NULL)
		rrb(b, 1);
	ft_printf("rrr\n");
}
