/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 20:07:16 by junglee           #+#    #+#             */
/*   Updated: 2023/10/01 20:20:14 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_print(t_philosopher *philo, const char *str)
{
	unsigned long long	ull_time;

	pthread_mutex_lock(&(philo->shared->std_out));
	pthread_mutex_lock(&(philo->shared->end_check));
	if (philo->shared->end_flag)
	{
		pthread_mutex_unlock(&(philo->shared->end_check));
		pthread_mutex_unlock(&(philo->shared->std_out));
		return ;
	}
	pthread_mutex_unlock(&(philo->shared->end_check));
	ull_time = get_time() - philo->shared->init_time;
	printf("%llu %d %s\n", ull_time, philo->self + 1, str);
	pthread_mutex_unlock(&(philo->shared->std_out));
}

void	philo_print_dying(t_philosopher *philo)
{
	unsigned long long	ull_time;

	pthread_mutex_lock(&(philo->shared->std_out));
	ull_time = get_time() - philo->shared->init_time;
	printf("%llu %d died\n", ull_time, philo->self + 1);
	pthread_mutex_unlock(&(philo->shared->std_out));
}
