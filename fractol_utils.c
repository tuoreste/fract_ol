/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:37:23 by otuyishi          #+#    #+#             */
/*   Updated: 2023/09/03 00:32:09 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atodigit(const char **str)
{
	double	result;

	result = 0.0;
	while (**str >= '0' && **str <= '9')
	{
		result = result * 10.0 + (**str - '0');
		(*str)++;
	}
	return (result);
}

double	ft_atofraction(const char **str)
{
	double	result;
	double	power;

	result = 0.0;
	power = 1.0;
	(*str)++;
	while (**str >= '0' && **str <= '9')
	{
		result = result * 10.0 + (**str - '0');
		power *= 10.0;
		(*str)++;
	}
	return (result / power);
}

int	is_valid_input(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-' || str[i] == '+'
			|| str[i] == '.')
			i++;
		else
			return (0);
	}
	return (1);
}

double	convert_to_float(const char *str)
{
	double	res;
	int		sign;
	int		f;

	res = 0.0;
	sign = 1;
	f = 0;
	while (*str && ((*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
				|| *str == '\f' || *str == '\r')))
		str++;
	if (*str == '-')
	{
		sign = -1.0;
		str++;
	}
	else if (*str == '+')
		str++;
	res = ft_atodigit(&str);
	if (*str == '.')
	{
		f = 1;
		res += ft_atofraction(&str);
	}
	return (res * sign);
}

double	ft_atof(const char *str)
{
	if (!is_valid_input(str))
	{
		write(1, "Invalid character(s) in input string\n", 38);
		exit(1);
	}
	return (convert_to_float(str));
}
