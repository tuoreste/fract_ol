/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:37:23 by otuyishi          #+#    #+#             */
/*   Updated: 2023/08/29 17:09:28 by otuyishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (s1[i] == s2[i])
		return (1);
	else
		return (0);
}
int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

double	ft_atodigit(const char **str)
{
	double	result;

	result = 0.0;
	while (ft_isdigit(**str))
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
	while (ft_isdigit(**str))
	{
		result = result * 10.0 + (**str - '0');
		power *= 10.0;
		(*str)++;
	}
	return (result / power);
}

double	ft_atof(const char *str)
{
	double	result;
	double	sign;
	int		f;

	result = 0.0;
	sign = 1.0;
	f = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		sign = -1.0;
		str++;
	}
	else if (*str == '+')
	{
		str++;
	}
	result = ft_atodigit(&str);
	if (*str == '.')
	{
		f = 1;
		result += ft_atofraction(&str);
	}
	return (result * sign);
}
