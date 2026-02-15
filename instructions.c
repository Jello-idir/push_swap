/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-idi <aait-idi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 21:56:52 by aait-idi          #+#    #+#             */
/*   Updated: 2026/02/14 13:20:01 by aait-idi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_exceeded(t_stack **stack, t_data *data, int threshold,
		int idx)
{
	int		count;
	int		option;
	t_stack	*selected;

	if (!stack)
		return (0);
	option = (threshold >= 0);
	if (threshold < 0)
		threshold = ~threshold + 1;
	if (!data->tmp)
		data->tmp = INT_MAX;
	selected = stack[idx];
	count = 0;
	while (selected && data->tmp)
	{
		if ((option && selected->key > threshold)
			|| (!option && selected->key <= threshold))
			count++;
		selected = selected->next;
		data->tmp--;
	}
	return (count);
}

int	threshold(t_stack **stack, t_data *data, int threshold)
{
	int	n;
	int	option;

	if (!stack || !stack[A])
		return (0);
	n = count_exceeded(stack, data, threshold, A);
	option = (threshold >= 0);
	if (threshold < 0)
		threshold = ~threshold + 1;
	while (n)
	{
		if ((option && stack[A]->key > threshold)
			|| (!option && stack[A]->key <= threshold))
		{
			if (!do_move(stack, data, PB))
				return (0);
			n--;
		}
		else if (!do_move(stack, data, RA))
			return (0);
	}
	data->tmp = 0;
	return (1);
}

static int	moves_and_direction(t_stack *stack, int key)
{
	int	len;
	int	position;
	int	moves;

	moves = 0;
	if (key)
	{
		len = stack_size(stack);
		position = key_position(stack, key);
		moves = -(len - position + 1);
		if (position - 1 <= len / 2)
			moves = position - 1;
	}
	return (moves);
}

int	keys_to_top(t_stack **stk, t_data *dt, int key_a, int key_b)
{
	int	moves[2];

	moves[A] = moves_and_direction(stk[A], key_a);
	moves[B] = moves_and_direction(stk[B], key_b);
	while (moves[A] && moves[B] && ((moves[A] > 0) == (moves[B] > 0)))
	{
		if (!do_move(stk, dt, RR * (moves[A] > 0) + RRR * (moves[A] < 0)))
			return (0);
		dt->mvlen--;
		moves[A] += (-1 * (moves[A] > 0)) + (1 * (moves[A] < 0));
		moves[B] += (-1 * (moves[B] > 0)) + (1 * (moves[B] < 0));
	}
	while (moves[A])
	{
		if (!do_move(stk, dt, (RA * (moves[A] > 0)) + (RRA * (moves[A] < 0))))
			return (0);
		moves[A] += (-1 * (moves[A] > 0)) + (1 * (moves[A] < 0));
	}
	while (moves[B])
	{
		if (!do_move(stk, dt, (RB * (moves[B] > 0)) + (RRB * (moves[B] < 0))))
			return (0);
		moves[B] += (-1 * (moves[B] > 0)) + (1 * (moves[B] < 0));
	}
	return (1);
}
