/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 20:35:31 by junglee           #+#    #+#             */
/*   Updated: 2023/10/01 17:22:02 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	dying_for_time(t_philosopher *philo, int i);
static void	dying_for_eat(t_philosopher *philo, int i);

void	monitor_func(t_philosopher *philo, t_arg arg)
{
	int					i;
	unsigned long long	now;

	i = -1;
	while (1)
	{
		if (++i >= arg.number)
			usleep (200);
		i %= arg.number;
		now = get_time();
		pthread_mutex_lock(&(philo[i].last_eat_check));
		if (now >= (unsigned long long)arg.dying_time + philo[i].last_eat)
		{
			pthread_mutex_unlock(&(philo[i].last_eat_check));
			return (dying_for_time(philo, i));
		}
		pthread_mutex_unlock(&(philo[i].last_eat_check));
		pthread_mutex_lock(&(philo->shared->eat_cnt_check));
		if (philo->shared->done_philo == arg.number)
		{
			pthread_mutex_unlock(&(philo->shared->eat_cnt_check));
			return (dying_for_eat(philo, i));
		}
		pthread_mutex_unlock(&(philo->shared->eat_cnt_check));
	}
}

static void	dying_for_time(t_philosopher *philo, int i)
{
	pthread_mutex_lock(&(philo->shared->end_check));
	philo[i].shared->end_flag = 1;
	pthread_mutex_unlock(&(philo->shared->end_check));
	//usleep(8);
	philo_print_dying(&(philo[i]));
	return ;
}

static void	dying_for_eat(t_philosopher *philo, int i)
{
	pthread_mutex_lock(&(philo->shared->end_check));
	philo[i].shared->end_flag = 1;
	pthread_mutex_unlock(&(philo->shared->end_check));
	return ;
}
