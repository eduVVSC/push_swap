/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvieira <edvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:39:26 by edvieira          #+#    #+#             */
/*   Updated: 2024/08/16 11:54:20 by edvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	multiple_entrence(int ac, char **av, t_stack **a)
{
	t_stack	*temp;
	int		i;

	i = 1;
	temp = *a;
	if (check_entrence(av[i]) == 1)
		exit (free_to_end2(*a));
	temp->num = ft_atol(ft_strtrim(av[i], " "), 0, *a);
	temp->last = NULL;
	while (++i <= (ac - 1))
	{
		if (check_entrence(av[i]) == 1)
			exit (free_to_end2(*a));
		temp->next = ft_new_node(ft_atol(ft_strtrim(av[i], " "), 0, *a));
		temp->next->last = temp;
		temp = temp->next;
	}
	temp->next = NULL;
	check_dup(*a);
}

void	separating_nums(char *str, t_stack **a)
{
	t_stack	*temp;
	char	**nums;
	int		i;

	i = 0;
	temp = *a;
	nums = ft_split(str, ' ');
	if (nums[0] == NULL)
		exit (free_to_end(nums, temp));
	if (check_entrence_repeat(nums, *a) == 1)
		exit (free_to_end(nums, temp));
	temp->num = ft_atol(nums[i], 0, *a);
	temp->last = NULL;
	while (nums[++i] != NULL)
	{
		temp->next = ft_new_node(ft_atol(nums[i], 0, *a));
		temp->next->last = temp;
		temp = temp->next;
	}
	temp->next = NULL;
	free(nums);
	check_dup(*a);
}

int	main(int ac, char **av)
{
	t_stack	*a;

	a = malloc(sizeof(t_stack));
	a->next = NULL;
	if (ac == 1)
		free (a);
	else
	{
		if (ac == 2)
			separating_nums(av[1], &a);
		else
			multiple_entrence(ac, av, &a);
		organize_nums(a);
		free_stack(a);
	}
	return (0);
}
