/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 22:14:47 by junglee           #+#    #+#             */
/*   Updated: 2023/08/20 22:04:05 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_philosopher	*philo;
	t_arg			arg;
	t_shared		*shared;
	int				i;

	if (argc != 5 && argc != 6)
		return (1);
	i = 1;
	philo_init_arg(&arg, argc, argc);
	philo = (t_philosopher *)malloc(sizeof(t_philosopher) * (arg.number + 1));
	philo_init_shared(&shared, arg.number);
	philo_init_sopher(philo, arg, shared);
	while (i <= arg.number)
	{
		
	}
}
