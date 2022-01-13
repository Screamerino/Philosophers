/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoreen <lcoreen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 18:02:55 by lcoreen           #+#    #+#             */
/*   Updated: 2022/01/13 13:25:51 by lcoreen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_sleep(t_philo *philo)
{
	unsigned long	i;

	i = get_time();
	print_message(philo, "is sleeping", i);
	while (get_time() - i < philo->info->time_to_sleep)
		usleep(330);
	print_message(philo, "is thinking", get_time());
}

void	eat(t_philo *philo)
{
	unsigned long	i;

	i = get_time();
	philo->start_eating = i;
	print_message(philo, "is eating", i);
	while (get_time() - i < philo->info->time_to_eat)
		usleep(330);
	philo->count_eat += 1;
}

void	try_take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->forks[philo->lfork]);
	print_message(philo, "has taken a fork", get_time());
	pthread_mutex_lock(&philo->info->forks[philo->rfork]);
	print_message(philo, "has taken a fork", get_time());
}

void	put_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->info->forks[philo->rfork]);
	pthread_mutex_unlock(&philo->info->forks[philo->lfork]);
} 