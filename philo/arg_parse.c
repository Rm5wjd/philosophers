/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:33:52 by junglee           #+#    #+#             */
/*   Updated: 2023/09/09 19:22:09 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	arg_range_check(t_arg *arg)
{
	if (arg->dying_time > 86400000 || arg->eating_time > 86400000 \
	|| arg->sleeping_time > 86400000)
	{
		printf("philosophers action time over!\n");
		return (0);
	}
	if (arg->number == 0)
	{
		printf("philosophers number zero!\n");
		return (0);
	}
	return (1);
}
