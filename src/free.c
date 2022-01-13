/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoreen <lcoreen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 18:01:17 by lcoreen           #+#    #+#             */
/*   Updated: 2021/12/18 18:08:50 by lcoreen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_memory(t_info **info)
{
	free((*info)->philos);
	free((*info)->forks);
	free(*info);
	*info = NULL;
}

void	destroy_forks(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->n_philo)
	{
		pthread_mutex_destroy(&info->forks[i]);
		++i;
	}
	pthread_mutex_destroy(&info->printer);
}
