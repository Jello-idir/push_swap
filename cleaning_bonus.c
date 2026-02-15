/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-idi <aait-idi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 21:41:02 by aait-idi          #+#    #+#             */
/*   Updated: 2026/02/12 21:17:07 by aait-idi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	purge_and_exit(t_stack **stack, t_data *data, int code)
{
	if (code == 2)
	{
		write(2, "Error\n", 6);
		code = 1;
	}
	if (data)
	{
		free(data->keys);
		free(data);
	}
	if (stack)
	{
		stack_clear(&stack[A]);
		stack_clear(&stack[B]);
		free(stack);
	}
	exit(code);
}
