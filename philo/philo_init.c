/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:55:46 by junglee           #+#    #+#             */
/*   Updated: 2023/09/11 16:38:33 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	num_check(const char *str);

int	philo_init_arg(t_arg *arg, char *argv[], int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!num_check(argv[i]))
			return (0);
		i++;
	}
	arg->number = ft_atoi(argv[1]);
	arg->dying_time = ft_atoi(argv[2]);
	arg->eating_time = ft_atoi(argv[3]);
	arg->sleeping_time = ft_atoi(argv[4]);
	if (argc == 6)
		arg->must_eat = ft_atoi(argv[5]);
	else
		arg->must_eat = 0;
	if (!arg_range_check(arg))
		return (0);
	return (1);
}

void	philo_init_shared(t_shared **shared, int number)
{
	int	i;

	i = 0;
	(*shared) = (t_shared *)malloc(sizeof(t_shared));
	(*shared)->fork = (pthread_mutex_t *) \
	malloc(sizeof(pthread_mutex_t) * (number));
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
			philo[i].right = (i + 1) % (arg.number);
		philo[i].last_eat = shared->init_time;
		philo[i].arg = arg;
		philo[i].shared = shared;
		pthread_mutex_init(&(philo[i].last_eat_check), NULL);
		i++;
	}
}

static int	num_check(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			printf("philosophers arg not number!");
			return (0);
		}
		i++;
	}
	return (1);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
