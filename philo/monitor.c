/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 20:35:31 by junglee           #+#    #+#             */
/*   Updated: 2023/09/03 16:58:03 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	dying_for_time(t_philosopher *philo, int i);
static void	dying_for_eat(t_philosopher *philo, int i);

void	monitor_func(t_philosopher *philo, t_arg arg)
{
	int					i;
	unsigned long long	now;

	i = 0;
	while (1)
	{
		if (i >= arg.number)
			i = 0;
		now = get_time();
		pthread_mutex_lock(&(philo[i].last_eat_check));
		if (now >= (unsigned long long)arg.dying_time + philo[i].last_eat)
		{
			printf("%lld %lld %lld\n", now, philo[i].last_eat, philo[i].shared->init_time);
			printf("%lld %lld %lld\n", now, philo[i+1].last_eat, philo[i].shared->init_time);
			return (dying_for_time(philo, i));
		}
		pthread_mutex_unlock(&(philo[i].last_eat_check));
		pthread_mutex_lock(&(philo->shared->eat_cnt_check));
		if (philo->shared->done_philo == arg.number)
			return (dying_for_eat(philo, i));
		pthread_mutex_unlock(&(philo->shared->eat_cnt_check));
		i++;
	}
}

static void	dying_for_time(t_philosopher *philo, int i)
{
	pthread_mutex_lock(&(philo->shared->end_check));
	philo[i].shared->end_flag = 1;
	pthread_mutex_unlock(&(philo->shared->end_check));
	philo_print_dying(&(philo[i]));
	pthread_mutex_unlock(&(philo[i].last_eat_check));
	return ;
}

static void	dying_for_eat(t_philosopher *philo, int i)
{
	pthread_mutex_unlock(&(philo->shared->eat_cnt_check));
	pthread_mutex_lock(&(philo->shared->end_check));
	philo[i].shared->end_flag = 1;
	pthread_mutex_unlock(&(philo->shared->end_check));
	return ;
}