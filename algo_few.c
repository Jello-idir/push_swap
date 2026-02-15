/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_few.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-idi <aait-idi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 22:44:05 by aait-idi          #+#    #+#             */
/*   Updated: 2026/02/14 22:31:07 by aait-idi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max(t_stack *stack)
{
	int	max;

	max = 0;
	while (stack)
	{
		if (stack->key > max)
			max = stack->key;
		stack = stack->next;
	}
	return (max);
}

static int	sort_three(t_stack **stack, t_data *data)
{
	int	max;

	max = find_max(stack[A]);
	if (!max)
		return (0);
	if (data->klen > 1 && stack[A]->key == max)
		if (!do_move(stack, data, RA))
			return (0);
	if (data->klen > 2 && stack[A]->next->key == max)
		if (!do_move(stack, data, RRA))
			return (0);
	if (stack[A]->key > stack[A]->next->key)
		if (!do_move(stack, data, SA))
			return (0);
	return (1);
}

void	sort_few(t_stack **stack, t_data *data)
{
	int	i;

	parse_stack(stack, data);
	if (data->klen <= 3)
		sort_three(stack, data);
	if (data->klen <= 3)
		return ;
	i = 0;
	while (1)
	{
		if (stack[A]->key > 2)
			do_move(stack, data, RA);
		else
		{
			do_move(stack, data, PB);
			i++;
		}
		if (i == 2)
			break ;
	}
	sort_three(stack, data);
	while (stack[B])
		do_move(stack, data, PA);
	if (stack[A]->key > stack[A]->next->key)
		do_move(stack, data, SA);
}
