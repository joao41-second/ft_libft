/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:11:35 by rerodrig          #+#    #+#             */
/*   Updated: 2025/03/20 11:27:23 by rerodrig         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "./libft.h"

double ft_atof(const char *str, char **endptr)
{
    double result = 0.0;
    double fraction = 0.1;
    int sign = 1;
    int i = 0;

    while (ft_isspace(str[i]))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (ft_isdigit(str[i]))
    {
        result = result * 10.0 + (str[i] - '0');
        i++;
    }
    if (str[i] == '.')
    {
        i++;
        while (ft_isdigit(str[i]))
        {
            result += fraction * (str[i] - '0');
            fraction *= 0.1;
            i++;
        }
    }
    if (endptr)
        *endptr = (char *)&str[i];
    return (result * sign);
}
