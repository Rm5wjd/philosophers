/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:55:46 by junglee           #+#    #+#             */
/*   Updated: 2023/08/31 20:53:03 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_init_arg(t_arg *arg, char *argv[], int argc)
{
	arg->number = ft_atoi(argv[1]);
	arg->dying_time = ft_atoi(argv[2]);
	arg->eating_time = ft_atoi(argv[3]);
	arg->sleeping_time = ft_atoi(argv[4]);
	if (argc == 6)
		arg->must_eat = ft_atoi(argv[5]);
	else
		arg->must_eat = 0;
}

void	philo_init_shared(t_shared **shared, int number)
{
	int	i;

	i = 0;
	(*shared) = (t_shared *)malloc_s(sizeof(t_shared));
	(*shared)->fork = (pthread_mutex_t *) \
	malloc_s(sizeof(pthread_mutex_t) * (number));
	while (i < number)
	{
		pthread_mutex_init(&((*shared)->fork[i]), NULL);
		i++;
	}
	pthread_mutex_init(&((*shared)->std_out), NULL);
	pthread_mutex_init(&((*shared)->end_check), NULL);
	pthread_mutex_init(&((*shared)->eat_cnt_check), NULL);
	(*shared)->init_time = get_time();
	(*shared)->end_flag = 0;
	(*shared)->done_philo = 0;
}

void	philo_init_sopher(t_philosopher *philo, t_arg arg, t_shared *shared)
{
	int	i;

	i = 0;
	while (i < arg.number)
	{
		philo[i].self = i;
		philo[i].left = i;
		if (arg.number == 1)
			philo[i].right = 0;
		else
			philo[i].right = (i + 1) % arg.number;
		philo[i].last_eat = shared->init_time;
		philo[i].arg = arg;
		philo[i].shared = shared;
		pthread_mutex_init(&(philo[i].last_eat_check), NULL);
		i++;
	}
}
