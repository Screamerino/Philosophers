/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoreen <lcoreen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:49:10 by lcoreen           #+#    #+#             */
/*   Updated: 2021/12/20 17:31:53 by lcoreen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_message(t_philo *philo, char *msg, unsigned long t)
{
	pthread_mutex_lock(&philo->info->printer);
	printf("%lu %d %s\n", t - philo->time_start, philo->id + 1, msg);
	pthread_mutex_unlock(&philo->info->printer);
}
