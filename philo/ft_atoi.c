/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junglee <junglee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 17:19:54 by junglee           #+#    #+#             */
/*   Updated: 2023/08/20 17:20:09 by junglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

static int	ft_checksign(const char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
		{
			if (!(str[i + 1] >= '0' && str[i + 1] <= '9'))
				return (0);
			if (str[i] == '-')
				return (-1);
			else
				return (1);
		}
		else if (str[i] >= '0' && str[i] <= '9')
			return (1);
		else
			return (0);
		i++;
	}
	return (0);
}

int	ft_under_over_check(unsigned long long sum, int sign)
{
	if (sum - 1 > LLONG_MAX && sign == -1)
		return (0);
	if (sum > LLONG_MAX && sign == 1)
		return (-1);
	return ((int)(sum * sign));
}

int	ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long long	sum;
	int					output;

	i = 0;
	sign = ft_checksign(str);
	sum = 0;
	if (sign == 0)
		return (0);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			sum *= 10;
			sum += (int)str[i] - 48;
		}
		else if (i > 0 && (str[i - 1] >= '0' && str[i - 1] <= '9')
			&& !(str[i] >= '0' && str[i] <= '0'))
			break ;
		i++;
	}
	output = ft_under_over_check(sum, sign);
	return (output);
}
