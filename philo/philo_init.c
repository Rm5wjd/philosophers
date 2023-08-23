/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:55:46 by junglee           #+#    #+#             */
/*   Updated: 2023/08/22 17:07:27 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	philo_init_arg(t_arg *arg, char *argv[], int argc)
{
	arg->number = ft_atoi(argv[1]);
	arg->dying_time = ft_atoi(argv[2]);
	arg->eating_time = ft_atoi(argv[3]);
	arg->sleeping_time = ft_atoi(argv[4]);
	if (argc == 6)
		arg->must_eat = ft_atoi(argv[5]);
}

void	philo_init_shared(t_shared **shared, int number)
{
	int	i;

	i = 1;
	(*shared) = (t_shared *)malloc(sizeof(t_shared));
	(*shared)->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * (number + 1));
	while (i <= number)
	{
		pthread_mutex_init(&((*shared)->fork[i]), NULL);
		i++;
	}
	pthread_mutex_init(&((*shared)->std_out), NULL);
	gettimeofday(&((*shared)->init_time), NULL);
	(*shared)->end_flag = 0;
}

void	philo_init_sopher(t_philosopher *philo, t_arg arg, t_shared *shared)
{
	int	i;

	i = 1;
	while (i <= arg.number)
	{
		philo[i].self = i;
		philo[i].left = i;
		philo[i].right = (i + 1) % arg.number;
		gettimeofday(&(philo[i].last_eat), NULL);
		philo[i].arg = arg;
		philo[i].shared = shared;
		i++;
	}
}
