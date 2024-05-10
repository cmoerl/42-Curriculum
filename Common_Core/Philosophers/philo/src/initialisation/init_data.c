/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:42:36 by csturm            #+#    #+#             */
/*   Updated: 2024/05/10 14:16:28 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

static int check_overflow(const char *str)
{
    size_t len;

    len = ft_strlen(str);
    if (len > 10)
        return (1);
    if (len == 10 && ft_strncmp(str, "2147483647", 10) > 0)
        return (1);
    return (0);
}

static char *extract_number(char **argv, t_data *data)
{
    char    *start;
    char    *end;
    char    *num;
    size_t  len;

    while (**argv && ft_iswhitespace(**argv))
        (*argv)++;
    if (**argv == '+')
        (*argv)++;
    start = *argv;
    while (**argv && ft_isdigit(**argv))
        (*argv)++;
    end = *argv;
    len = end - start;
    num = malloc(len + 1);
    if (!num)
        error(ERR_MALLOC, data);
    ft_memcpy(num, start, len);
    num[len] = '\0';
    return (num);
}

static void check_args(char **argv, t_data *data)
{
    char    *num;
    char    *tmp;

    argv++;
    while (*argv)
    {
        tmp = *argv;
        num = extract_number(&tmp, data);
        if (!*num)
            error(ERR_DIG, data);
        if (check_overflow(num))
            error(ERR_NUM_OF, data);
        free(num);
        argv++;
    }
}

void    init_data(t_data *data, int argc, char **argv)
{
    check_args(argv, data);
    data->philo_count = ft_atoi_long(argv[1]);
    data->time_to_die = ft_atoi_long(argv[2]) * 1000;
    data->time_to_eat = ft_atoi_long(argv[3]) * 1000;
    data->time_to_sleep = ft_atoi_long(argv[4]) * 1000;
    if (!data->philo_count || !data->time_to_die || !data->time_to_eat || !data->time_to_sleep)
        error(ERR_DIG, data);
    if (argc == 6)
        data->max_meals = ft_atoi_long(argv[5]);
    else
        data->max_meals = -1;
    data->philos = NULL;
    data->forks = NULL;
    data->philos = malloc(sizeof(t_philo) * data->philo_count);
    if (!data->philos)
        error(ERR_MALLOC, data);
    data->forks = malloc(sizeof(t_fork) * data->philo_count);
    if (!data->forks)
    {
        free(data->philos);
        error(ERR_MALLOC, data);
    }
    data->start_time = get_time();
    if (data->start_time == -1)
    {
        free(data->philos);
        free(data->forks);
        error(ERR_TIME, data);
    }
    data->end = 0;
}
