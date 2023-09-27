/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:33:52 by junglee           #+#    #+#             */
/*   Updated: 2023/09/27 19:58:00 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#define ONE_DAY_MILESEC 86400000

int	arg_range_check(t_arg *arg, int argc)
{
	if (arg->dying_time > ONE_DAY_MILESEC || arg->eating_time > ONE_DAY_MILESEC \
	|| arg->sleeping_time > ONE_DAY_MILESEC)
	{
		printf("philosophers action time over!\n");
		return (0);
	}
	if (arg->number == 0)
	{
		printf("philosophers number zero!\n");
		return (0);
	}
	if (arg->must_eat == 0 && argc == 6)
		return (0);
	return (1);
}
