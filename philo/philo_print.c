/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 20:07:16 by junglee           #+#    #+#             */
/*   Updated: 2023/08/22 16:56:36 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_print_take_fork(t_philosopher *philo)
{
	struct timeval		time_stamp;
	unsigned long long	ull_time;

	gettimeofday(&time_stamp, NULL);
	ull_time = (time_stamp.tv_usec - philo->shared->init_time.tv_usec);
	pthread_mutex_lock(&(philo->shared->std_out));
	printf("%llu %d has taken a fork\n", ull_time, philo->self);
	pthread_mutex_unlock(&(philo->shared->std_out));
}

void	philo_print_eating(t_philosopher *philo)
{
	struct timeval		time_stamp;
	unsigned long long	ull_time;

	gettimeofday(&time_stamp, NULL);
	ull_time = (time_stamp.tv_usec - philo->shared->init_time.tv_usec);
	pthread_mutex_lock(&(philo->shared->std_out));
	printf("%llu %d is eating\n", ull_time, philo->self);
	pthread_mutex_unlock(&(philo->shared->std_out));
}

void	philo_print_sleeping(t_philosopher *philo)
{
	struct timeval		time_stamp;
	unsigned long long	ull_time;

	gettimeofday(&time_stamp, NULL);
	ull_time = (time_stamp.tv_usec - philo->shared->init_time.tv_usec);
	pthread_mutex_lock(&(philo->shared->std_out));
	printf("%llu %d is sleeping\n", ull_time, philo->self);
	pthread_mutex_unlock(&(philo->shared->std_out));
}

void	philo_print_thinking(t_philosopher *philo)
{
	struct timeval		time_stamp;
	unsigned long long	ull_time;

	gettimeofday(&time_stamp, NULL);
	ull_time = (time_stamp.tv_usec - philo->shared->init_time.tv_usec);
	pthread_mutex_lock(&(philo->shared->std_out));
	printf("%llu %d is thinking\n", ull_time, philo->self);
	pthread_mutex_unlock(&(philo->shared->std_out));
}

void	philo_print_dying(t_philosopher *philo)
{
	struct timeval		time_stamp;
	unsigned long long	ull_time;

	gettimeofday(&time_stamp, NULL);
	ull_time = (time_stamp.tv_usec - philo->shared->init_time.tv_usec);
	pthread_mutex_lock(&(philo->shared->std_out));
	printf("%llu %d died\n", ull_time, philo->self);
	pthread_mutex_unlock(&(philo->shared->std_out));
}