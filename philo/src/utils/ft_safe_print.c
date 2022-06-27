/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 13:27:20 by bregneau          #+#    #+#             */
/*   Updated: 2022/06/27 15:00:49 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	ft_putstr_mutex(char *str, pthread_mutex_t *mutex)
// {
// 	int	size;

// 	size = ft_strlen(str);
// 	pthread_mutex_lock(mutex);
// 	write(1, str, size);
// 	pthread_mutex_unlock(mutex);
// }

// int	ft_safe_print(int x, char *str, pthread_mutex_t *mutex)
// {
// 	char	buffer[64];
// 	char	*tmp;

// 	memset(buffer, 0, sizeof(buffer));
// 	tmp = ft_itoa(ft_get_time(0));
// 	if (tmp == NULL)
// 		return (1);
// 	ft_strcpy(buffer, tmp);
// 	free(tmp);
// 	tmp = ft_itoa(x);
// 	if (tmp == NULL)
// 		return (1);
// 	ft_strlcat(buffer, " ", sizeof(buffer));
// 	ft_strlcat(buffer, tmp, sizeof(buffer));
// 	free(tmp);
// 	ft_strlcat(buffer, " ", sizeof(buffer));
// 	ft_strlcat(buffer, str, sizeof(buffer));
// 	ft_putstr_mutex(buffer, mutex);
// 	return (0);
// }

void	ft_end_of_sim(t_philo *p, int value)
{
	pthread_mutex_lock(p->print_mutex);
	*p->is_end = value;
	pthread_mutex_unlock(p->print_mutex);
}

int	ft_safe_print(t_philo *p, char *str)
{
	int	time;

	time = ft_get_time(0);
	pthread_mutex_lock(p->print_mutex);
	if (*p->is_end == 0)
		printf("%05d %d %s\n", time, p->id, str);
	pthread_mutex_unlock(p->print_mutex);
	return (time);
}
