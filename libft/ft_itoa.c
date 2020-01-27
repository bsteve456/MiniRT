/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 23:00:13 by blacking          #+#    #+#             */
/*   Updated: 2019/10/20 12:55:20 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_count_char_n(int n)
{
	int count;

	count = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
		count++;
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static void			ft_strrev(char *str)
{
	int				i;
	int				j;
	char			mem;

	j = ft_strlen(str) - 1;
	i = 0;
	while (i <= j)
	{
		mem = str[i];
		str[i++] = str[j];
		str[j--] = mem;
	}
}

static char			int_to_char(unsigned int n)
{
	if (n >= 10)
		return ((n % 10) + '0');
	else
		return (n + '0');
}

char				*ft_itoa(int n)
{
	char			*num;
	unsigned	int	nb;
	int				i;

	i = 0;
	if (!(num = ft_calloc(ft_count_char_n(n) + 1, sizeof(char))))
		return (NULL);
	nb = (n >= 0) ? n : -n;
	while (i < ft_count_char_n(n))
	{
		if (n < 0 && i + 1 == ft_count_char_n(n))
			num[i++] = '-';
		else
			num[i++] = int_to_char(nb);
		nb /= 10;
	}
	num[i] = '\0';
	ft_strrev(num);
	return (num);
}
