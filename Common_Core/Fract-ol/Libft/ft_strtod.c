/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:09:08 by csturm            #+#    #+#             */
/*   Updated: 2024/01/31 16:24:31 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double  convert_to_double(char *str, int i, double result, double decimal)
{
    while (str[i] && ((str[i] >= '0' && str[i] <= '9') || str[i] == '.')) 
    {
        if (str[i] == '.')
        {
            i++;
            while (str[i] && str[i] >= '0' && str[i] <= '9')
            {
                decimal /= 10.0;
                result += (str[i] - '0') * decimal;
                i++;
            }
            break ;
        }
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return (result);    
}

double  ft_strtod(char *str)
{
    double  result;
    double  decimal;
    int     i;
    int     sign;

    if (!str || !*str)
        return (0.0);
    result = 0.0;
    decimal = 1.0;
    i = 0;
    sign = 1;
    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    result = convert_to_double(str, i, result, decimal);
    return (result * sign);
}
