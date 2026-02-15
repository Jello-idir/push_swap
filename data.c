/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-idi <aait-idi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 12:15:38 by aait-idi          #+#    #+#             */
/*   Updated: 2026/02/14 22:21:49 by aait-idi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	indexify_and_dups_check(t_data *data)
{
	int	i;
	int	j;
	int	rank;
	int	ranked[500];

	i = 0;
	while (i < data->klen)
	{
		rank = 1;
		j = 0;
		while (j < data->klen)
		{
			if (data->keys[i] > data->keys[j])
				rank++;
			else if (i != j && data->keys[i] == data->keys[j])
				purge_and_exit(NULL, data, 2);
			j++;
		}
		ranked[i] = rank;
		i++;
	}
	i = -1;
	while (++i < data->klen)
		data->keys[i] = ranked[i];
}

static int	*parse_args(int ac, const char **av, t_data *data)
{
	long	tmp;
	int		buffer[500];

	data->keys = NULL;
	data->klen = 0;
	while (--ac && ++av)
	{
		if (!(**av))
			purge_and_exit(NULL, data, 2);
		while (**av)
		{
			tmp = advanced_atoi(av);
			if (tmp == ERROR || data->klen >= 500)
				purge_and_exit(NULL, data, 2);
			buffer[(data->klen)++] = tmp;
		}
	}
	data->keys = malloc(sizeof(int) * data->klen);
	if (!data->klen || !data->keys)
		purge_and_exit(NULL, data, !!data->klen);
	tmp = data->klen;
	while (tmp--)
		data->keys[tmp] = buffer[tmp];
	return (data->keys);
}

static void	is_already_sorted(t_data *data)
{
	int	i;

	i = 1;
	while (i < data->klen)
	{
		if (data->keys[i] < data->keys[i - 1])
			return ;
		i++;
	}
	purge_and_exit(NULL, data, 0);
}

static t_stack	**allocate_stack(t_data *data)
{
	int		i;
	t_stack	**stack;
	t_stack	*new;

	stack = malloc(sizeof(t_stack *) * 2);
	if (!stack)
		purge_and_exit(NULL, data, 1);
	stack[A] = NULL;
	stack[B] = NULL;
	i = 0;
	while (i < data->klen)
	{
		new = stack_new();
		if (!new)
			purge_and_exit(stack, data, 1);
		stack_add_front(stack, new);
		i++;
	}
	return (stack);
}

t_data	*initialize(int ac, const char **av, t_stack ***stack)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		exit(1);
	data->moves = NULL;
	data->keys = parse_args(ac, av, data);
	data->mvmax = 700 * (data->klen <= 100) + 5500 * (data->klen > 100);
	data->moves = malloc(sizeof(t_byte) * data->mvmax);
	if (!data->moves)
		purge_and_exit(NULL, data, 1);
	data->mvlen = 0;
	indexify_and_dups_check(data);
	is_already_sorted(data);
	data->tmp = 0;
	data->best_ratio = 1.55;
	data->ratio = 1.3;
	*stack = allocate_stack(data);
	return (data);
}
