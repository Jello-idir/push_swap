/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-idi <aait-idi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 08:08:11 by aait-idi          #+#    #+#             */
/*   Updated: 2026/02/14 22:33:53 by aait-idi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	parse_stack(t_stack **stack, t_data *data)
{
	int		i;
	t_stack	*iter;

	while (stack[B])
		do_move(stack, PA);
	iter = stack[A];
	i = 0;
	while (iter && i < data->klen)
	{
		iter->key = data->keys[i++];
		iter = iter->next;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
