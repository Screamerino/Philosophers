/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoreen <lcoreen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:37:16 by lcoreen           #+#    #+#             */
/*   Updated: 2021/12/20 14:16:28 by lcoreen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static pthread_mutex_t	*init_forks(t_info *info)
{
	pthread_mutex_t	*forks;
	int				i;

	i = 0;
	forks = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t) * info->n_philo);
	if (!forks)
	{
		free(info->philos);
		free(info);
		return (ft_error("malloc error"));
	}
	while (i < info->n_philo)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	return (forks);
}

static t_philo	*init_philos(t_info *info)
{
	t_philo	*philos;
	int		i;

	i = 0;
	philos = (t_philo *) malloc(sizeof(t_philo) * info->n_philo);
	if (!philos)
		return (NULL);
	while (i < info->n_philo)
	{
		philos[i].state = creating;
		philos[i].id = i;
		philos[i].info = info;
		philos[i].count_eat = 0;
		philos[i].lfork = i;
		philos[i].rfork = (i + 1) % info->n_philo;
		++i;
	}
	return (philos);
}

static int	fill_and_check_info(t_info *info, char **argv, int argc)
{
	info->n_philo = ft_atoi(argv[0]);
	info->time_to_die = ft_atoi(argv[1]);
	info->time_to_eat = ft_atoi(argv[2]);
	info->time_to_sleep = ft_atoi(argv[3]);
	info->max_eat = -1;
	if (argc == 5)
		info->max_eat = ft_atoi(argv[4]);
	if (info->n_philo < 1 || info->n_philo > 200
		|| info->time_to_die < 60 || info->time_to_eat < 60
		|| info->time_to_sleep < 60)
		return (1);
	return (0);
}

t_info	*init_info(char **argv, int argc)
{
	t_info	*info;
	int		i;

	i = 0;
	info = (t_info *) malloc(sizeof(t_info));
	if (!info)
		return (ft_error("malloc error"));
	if (fill_and_check_info(info, argv, argc))
		return (ft_error("invalid arguments"));
	info->philos = init_philos(info);
	if (!info->philos)
	{
		free(info);
		return (ft_error("malloc error"));
	}
	pthread_mutex_init(&info->printer, NULL);
	info->forks = init_forks(info);
	if (!info->forks)
		return (NULL);
	return (info);
}
