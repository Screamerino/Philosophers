/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoreen <lcoreen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:33:53 by lcoreen           #+#    #+#             */
/*   Updated: 2021/12/20 14:32:19 by lcoreen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_info			*info;
	pthread_t		monitor;
	int				i;

	if (argc != 5 && argc != 6)
	{
		printf("enter smtg like this \"./philo number_philo time_to_die"
			" time_to_sleep [max_eat]\"\n");
		return (1);
	}
	info = init_info(argv + 1, argc - 1);
	if (!info)
		return (1);
	i = 0;
	while (i < info->n_philo)
	{
		pthread_create(&info->philos[i].philo, NULL, start,
			(void *) &info->philos[i]);
		++i;
	}
	pthread_create(&monitor, NULL, monitor_routine, (void *) info);
	pthread_join(monitor, NULL);
	destroy_forks(info);
	free_memory(&info);
	return (0);
}
