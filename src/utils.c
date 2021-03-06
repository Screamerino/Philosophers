/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoreen <lcoreen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 15:10:24 by lcoreen           #+#    #+#             */
/*   Updated: 2021/12/18 18:29:35 by lcoreen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdio.h>

unsigned long	get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	res;

	sign = 1;
	res = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v'\
		|| *str == '\f' || *str == ' ' || *str == '\r')
		++str;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		++str;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		++str;
	}
	return (res * sign);
}

void	*ft_error(char *msg)
{
	printf("%s\n", msg);
	return (NULL);
}
