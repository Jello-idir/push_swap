/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-idi <aait-idi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 08:08:11 by aait-idi          #+#    #+#             */
/*   Updated: 2026/02/14 22:34:29 by aait-idi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	parse_number(const char **str, char sign)
{
	long	number;

	number = 0;
	while (**str >= '0' && **str <= '9')
	{
		number = number * 10 - (*(*str)++ - 48);
		if (number < INT_MIN || (number == INT_MIN && sign != '-'))
			return (ERROR);
	}
	if (**str && !(**str == ' '))
		return (ERROR);
	while (**str == ' ')
		(*str)++;
	if (sign == '-')
		return (number);
	return (~number + 1);
}

long	advanced_atoi(const char **str)
{
	char	sign;

	while ((**str == ' '))
		(*str)++;
	sign = **str;
	if (**str == '-' || **str == '+')
	{
		(*str)++;
		if (!(**str >= '0' && **str <= '9'))
			return (ERROR);
	}
	if (!**str)
		return (ERROR);
	return (parse_number(str, sign));
}

int	key_position(t_stack *stack, int key)
{
	int	i;

	i = 1;
	while (stack)
	{
		if (stack->key == key)
			return (i);
		i++;
		stack = stack->next;
	}
	return (0);
}

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->key > stack->next->key)
			return (0);
		stack = stack->next;
	}
	return (1);
}
