/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-adna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 08:21:53 by mel-adna          #+#    #+#             */
/*   Updated: 2020/01/05 01:27:15 by mel-adna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	check_result(long *res, int n)
{
	if (*res < 0 && n == 1)
		*res = -1;
	if (*res > 0 && n == -1)
		*res = 0;
}

int			ft_atoi(const char *str)
{
	int		i;
	int		n;
	long	res;

	i = 0;
	n = 1;
	res = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
				str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '+' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
		i++;
	if (str[i] == '-' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
	{
		n = -1;
		i++;
	}
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	res *= n;
	check_result(&res, n);
	return ((int)res);
}
