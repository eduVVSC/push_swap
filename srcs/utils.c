/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 08:59:17 by edvieira          #+#    #+#             */
/*   Updated: 2024/08/16 11:55:39 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_new_node(int num)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		exit (EXIT_FAILURE);
	new_node->num = num;
	new_node->next = NULL;
	return (new_node);
}

char	*to_transform(char *str)
{
	char	*to_return;
	int		i;

	i = 0;
	while ((str[i] >= '0' && str[i] <= '9') || str[i] == '-' || str[i] == '+')
		i++;
	to_return = (char *)malloc(sizeof(char) * (i + 1));
	i = -1;
	while ((str[++i] >= '0' && str[i] <= '9') || str[i] == '-' || str[i] == '+')
		to_return[i] = str[i];
	to_return[i] = '\0';
	return (to_return);
}

int	check_entrence(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (!((str[i] >= '0' && str[i] <= '9')
				|| str[i] == '-' || str[i] == '+'))
			return (1);
		if (str[i] == '+' || str[i] == '-')
		{
			if (!(str[i + 1] >= '0' && str[i + 1] <= '9'))
				return (1);
			if (i > 0 && (!(str[i - 1] == ' ' || str[i -1] == 0)))
				return (1);
		}
	}
	return (0);
}

int	check_entrence_repeat(char **nums, t_stack *a)
{
	int			i;
	long		num_now;

	i = -1;
	while (nums[++i] != NULL)
	{
		if (check_entrence(nums[i]) == 1)
			return (1);
		num_now = ft_atol(nums[i], 1, a);
		if (num_now > 2147483647 || num_now < -2147483648)
			return (1);
	}
	return (0);
}

void	check_dup(t_stack *a)
{
	t_stack	*temp1;
	t_stack	*temp2;

	temp1 = a;
	while (temp1 != NULL)
	{
		temp2 = a;
		while (temp2 != NULL)
		{
			if (temp1->num == temp2->num && temp1 != temp2)
			{
				free_stack(a);
				ft_printf("Erro\n");
				exit(EXIT_FAILURE);
			}
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
}
