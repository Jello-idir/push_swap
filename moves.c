/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-idi <aait-idi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:52:32 by aait-idi          #+#    #+#             */
/*   Updated: 2026/02/14 13:23:28 by aait-idi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack **stack, t_data *data)
{
	t_stack	*tmp;

	if (!*stack || !(*stack)->next || !(data->mvlen < data->mvmax))
		return (0);
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
	if (data->mvlen && !((data->moves[data->mvlen - 1]) >> 1 ^ 0)
		&& data->moves[data->mvlen - 1] != data->tmp)
		data->moves[data->mvlen - 1] = SS;
	else
		data->moves[data->mvlen++] = data->tmp;
	return (1);
}

int	push(t_stack **src, t_stack **dest, t_data *data)
{
	t_stack	*tmp;

	if (!(data->mvlen < data->mvmax))
		return (0);
	if (!*src)
		return (0);
	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
	data->moves[data->mvlen++] = data->tmp;
	return (1);
}

int	rotate(t_stack **stack, t_data *data)
{
	t_stack	*tmp;

	if (!*stack || !(*stack)->next || !(data->mvlen < data->mvmax))
		return (0);
	tmp = *stack;
	stack_last(*stack)->next = tmp;
	*stack = tmp->next;
	tmp->next = NULL;
	data->moves[data->mvlen++] = data->tmp;
	return (1);
}

int	reverse(t_stack **stack, t_data *data)
{
	t_stack	*tmp;

	if (!*stack || !(*stack)->next || !(data->mvlen < data->mvmax))
		return (0);
	tmp = *stack;
	while (tmp->next && tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = *stack;
	*stack = tmp->next;
	tmp->next = NULL;
	data->moves[data->mvlen++] = data->tmp;
	return (1);
}

int	do_move(t_stack **stack, t_data *data, t_byte idc)
{
	int	res;

	data->tmp = idc;
	res = 0;
	if (!(idc >> 1 ^ 2))
		res = (rotate(stack + (idc & 1), data));
	else if (!(idc >> 1 ^ 3))
		res = (reverse(stack + (idc & 1), data));
	else if (!(idc >> 1 ^ 1))
		res = (push(stack + !(idc & 1), stack + (idc & 1), data));
	else if (!(idc ^ 16))
		res = (rotate(stack, data) && rotate(stack + 1, data));
	else if (!(idc ^ 32))
		res = (reverse(stack, data) && reverse(stack + 1, data));
	else if (!(idc >> 1 ^ 0))
		res = (swap(stack + (idc & 1), data));
	else if (!(idc ^ 8))
		res = (swap(stack, data) && swap(stack + 1, data));
	data->tmp = 0;
	return (res);
}
