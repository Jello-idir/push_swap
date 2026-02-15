/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-idi <aait-idi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 23:35:20 by aait-idi          #+#    #+#             */
/*   Updated: 2026/02/08 22:21:26 by aait-idi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *stack)
{
	int	i;

	if (!stack)
		return (0);
	i = 1;
	while (stack->next)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

t_stack	*stack_new(void)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->next = NULL;
	return (new);
}

t_stack	*stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	stack_add_front(t_stack **stack, t_stack *new)
{
	if (!stack || !new)
		return ;
	new->next = *stack;
	*stack = new;
}

void	stack_clear(t_stack **stack)
{
	t_stack	*iter;
	t_stack	*next;

	if (!stack || !*stack)
		return ;
	iter = *stack;
	while (iter)
	{
		next = iter->next;
		free(iter);
		iter = next;
	}
	*stack = NULL;
}
