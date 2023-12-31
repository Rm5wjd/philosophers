/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 22:14:47 by junglee           #+#    #+#             */
/*   Updated: 2023/10/02 14:54:58 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_philosopher	*philo;
	t_arg			arg;
	t_shared		*shared;
	pthread_t		*p;

	if (argc != 5 && argc != 6)
		return (EXIT_FAILURE);
	if (philo_init_arg(&arg, argv, argc) == 0)
		return (0);
	philo = (t_philosopher *)malloc(sizeof(t_philosopher) * (arg.number));
	p = (pthread_t *)malloc(sizeof(pthread_t) * (arg.number));
	if (!philo || !p)
		return (EXIT_FAILURE);
	if (philo_init_shared(&shared, arg.number) == 0 \
	|| philo_init_sopher(philo, arg, shared) == 0)
		return (EXIT_FAILURE);
	if (create_thread(arg, p, philo) == 0)
		return (EXIT_FAILURE);
	monitor_func(philo, arg);
	free_thread(p, arg, shared, philo);
}

int	create_thread(t_arg arg, pthread_t *p, t_philosopher *philo)
{
	int	i;

	i = 0;
	while (i < arg.number)
	{
		if (pthread_create(&(p[i]), NULL, philo_start, &(philo[i])) != 0)
			return (0);
		i++;
	}
	return (1);
}

void	*philo_start(void *data)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)data;
	while (1)
	{
		philo_action_eat(philo);
		if (philo->arg.number == 1)
			return (0);
		philo_action_sleep(philo);
		philo_action_thinking(philo);
		pthread_mutex_lock(&(philo->shared->end_check));
		if (philo->shared->end_flag)
		{
			pthread_mutex_unlock(&(philo->shared->end_check));
			return (0);
		}
		pthread_mutex_unlock(&(philo->shared->end_check));
	}
}

void	free_thread(pthread_t *p, t_arg arg, \
t_shared *shared, t_philosopher *philo)
{
	int	i;
	int	status;

	i = 0;
	while (i < arg.number)
	{
		pthread_join(p[i], (void **)&status);
		pthread_mutex_destroy(&(shared->fork_mutex[i]));
		pthread_mutex_destroy(&(philo[i].last_eat_check));
		i++;
	}
	pthread_mutex_destroy(&(shared->end_check));
	pthread_mutex_destroy(&(shared->std_out));
	pthread_mutex_destroy(&(shared->eat_cnt_check));
	free(shared->fork_mutex);
	free(shared->fork);
	free(shared);
	free(p);
	free(philo);
}

unsigned long long	get_time(void)
{
	unsigned long long	sec;
	struct timeval		time;

	gettimeofday(&time, NULL);
	sec = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (sec);
}
