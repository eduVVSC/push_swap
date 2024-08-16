/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 09:23:31 by edvieira          #+#    #+#             */
/*   Updated: 2024/08/16 12:18:37 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_atol(long num)
{
	if (num > 2147483647 || num < -2147483648)
		return (1);
	return (0);
}

void	free_stack(t_stack *x)
{
	t_stack	*temp;

	while (x->next != NULL)
	{
		temp = x;
		x = x->next;
		free(temp);
	}
	free(x);
}

int	free_to_end(char **nums, t_stack *temp)
{
	int	i;

	i = -1;
	while (nums[++i] != NULL)
		free (nums[i]);
	free (nums);
	free (temp);
	ft_printf("Erro\n");
	return (1);
}

int	free_to_end2(t_stack *a)
{
	free_stack(a);
	ft_printf("Erro\n");
	return (1);
}
