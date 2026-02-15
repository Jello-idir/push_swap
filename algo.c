/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-idi <aait-idi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 00:50:51 by aait-idi          #+#    #+#             */
/*   Updated: 2026/02/14 13:20:01 by aait-idi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_stack(t_stack **stack, t_data *data)
{
	int		i;
	int		tmp;
	t_stack	*iter;

	tmp = data->mvmax;
	data->mvmax = INT_MAX;
	data->mvlen = 0;
	while (stack[B])
		do_move(stack, data, PA);
	iter = stack[A];
	i = 0;
	while (iter && i < data->klen)
	{
		iter->key = data->keys[i++];
		iter = iter->next;
	}
	data->mvlen = 0;
	data->mvmax = tmp;
}

static int	find_closest(t_stack *stack, int key)
{
	int	closest;

	if (!stack)
		return (0);
	closest = INT_MAX;
	while (stack)
	{
		if (stack->key < closest && stack->key > key)
			closest = stack->key;
		stack = stack->next;
	}
	if (closest == INT_MAX)
		return (0);
	return (closest);
}

static int	calculate_steps(t_stack **stack, int key_a, int key_b)
{
	int	steps[2];
	int	len[2];

	steps[A] = 0;
	steps[B] = 0;
	if (key_a && stack[A])
	{
		len[A] = stack_size(stack[A]);
		steps[A] = key_position(stack[A], key_a) - 1;
		if (steps[A] > len[A] / 2)
			steps[A] = len[A] - steps[A];
	}
	if (key_b && stack[B])
	{
		len[B] = stack_size(stack[B]);
		steps[B] = key_position(stack[B], key_b) - 1;
		if (steps[B] > len[B] / 2)
			steps[B] = len[B] - steps[B];
	}
	if (((steps[B] > len[B] / 2) == (steps[A] > len[A] / 2)))
		return (steps[A] * (steps[A] >= steps[B]) + steps[B]
			* (steps[B] > steps[A]));
	return (steps[A] + steps[B]);
}

static int	seek_easiest(t_stack **stack, t_data *data)
{
	int		steps;
	int		min;
	int		key[3];
	t_stack	*iter;

	min = INT_MAX;
	iter = stack[B];
	while (iter)
	{
		key[T] = find_closest(stack[A], iter->key);
		if (key[T])
		{
			steps = calculate_steps(stack, key[T], iter->key);
			if (steps < min)
			{
				min = steps;
				key[A] = key[T];
				key[B] = iter->key;
			}
		}
		iter = iter->next;
	}
	data->tmp = key[A];
	return (key[B]);
}

void	execute_sort(t_stack **stack, t_data *data)
{
	int	min;
	int	easiest;

	min = data->klen;
	parse_stack(stack, data);
	while (stack[A])
	{
		min = min / data->ratio;
		if (!threshold(stack, data, -(data->klen - min)))
			return ;
	}
	if (stack[B]->key == stack[B]->next->key - 1)
		if (!do_move(stack, data, SB))
			return ;
	if (!do_move(stack, data, PA))
		return ;
	while (stack[B] && data->mvlen < data->mvmax)
	{
		easiest = seek_easiest(stack, data);
		if (!keys_to_top(stack, data, data->tmp, easiest))
			return ;
		if (!do_move(stack, data, PA))
			return ;
	}
	keys_to_top(stack, data, 1, 0);
}
