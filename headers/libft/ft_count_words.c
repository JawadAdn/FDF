/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-adna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 09:33:11 by mel-adna          #+#    #+#             */
/*   Updated: 2019/04/16 14:47:46 by mel-adna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_words(char *s, char c)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (s[i] && s[i] == c)
		i++;
	if (!s[i])
		return (0);
	if (i == 0)
	{
		i++;
		count++;
	}
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
			count++;
		i++;
	}
	return (count);
}
