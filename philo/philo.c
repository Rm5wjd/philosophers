/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 22:14:47 by junglee           #+#    #+#             */
/*   Updated: 2023/08/23 16:50:52 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_philosopher	*philo;
	t_arg			arg;
	t_shared		*shared;
	int				i;
	pthread_t		*p;

	if (argc != 5 && argc != 6)
		return (1);
	i = 1;
	philo_init_arg(&arg, argv, argc);
	philo = (t_philosopher *)malloc(sizeof(t_philosopher) * (arg.number + 1));
	p = (pthread_t *)malloc(sizeof(pthread_t) * (arg.number + 1));
	philo_init_shared(&shared, arg.number);
	philo_init_sopher(philo, arg, shared);
	while (i <= arg.number)
	{
		pthread_create(&(p[i]), NULL, philo_start, &(philo[i]));
		i++;
	}
	monitor_func(philo, arg);
	printf("end\n");
}

void	*philo_start(void *data)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)data;
	while (1)
	{
		philo_action_eat(philo);
		philo_action_sleep(philo);
		philo_action_thinking(philo);
		if (philo->shared->end_flag)
			return (0);
	}
}

void	monitor_func(t_philosopher *philo, t_arg arg)
{
	int					i;
	unsigned long long	now;

	i = 1;
	while (1)
	{
		if (i > arg.number)
			i = 1;
		now = get_time();
		if (now - philo[i].last_eat >= arg.dying_time)
		{
			philo_print_dying(&(philo[i]));
			philo[i].shared->end_flag = 1;
			return ;
		}
		i++;
	}
}

unsigned long long	get_time(void)
{
	unsigned long long	sec;
	struct timeval		time;

	gettimeofday(&time, NULL);
	sec = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (sec);
}
