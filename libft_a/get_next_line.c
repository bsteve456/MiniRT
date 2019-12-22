/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 12:52:44 by stbaleba          #+#    #+#             */
/*   Updated: 2019/12/22 16:00:37 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define BUFFER_SIZE 4096

int		ft_newline(char *cumul)
{
	if(cumul == NULL)
		return(0);
	while(*cumul)
	{
		if(*cumul == '\n')
			return (1);
		cumul++;
	}
	return (0);
}

char *ft_strjoin_gnl(char *prev_cumul, char *buf, int read_file)
{
	char *next_cumul;
	int i = 0;
	int j = 0;

	if(!(next_cumul = ft_calloc(ft_strlen(prev_cumul) + read_file + 1, sizeof(char))))
		return (NULL);
	if(prev_cumul)
	{
		while(prev_cumul[i])
		{
			next_cumul[i] = prev_cumul[i];
			i++;
		}
		free(prev_cumul);
	}
	while(j < read_file)
	{
		next_cumul[i + j] = buf[j];
		j++;
	}
	return (next_cumul);
}

int		get_a_line(char **cumul, char **line, int read_file)
{
	int x =0;
	if((x = ft_newline(*cumul)) == 1 || (read_file == 0 && (*cumul && **cumul)))
	{
		free(*line);
		*line = ft_substr_gnl(*cumul, 0, ft_strlen(*cumul));
		*cumul = ft_substr_gnl(*cumul, ft_strlen(*line) + 1, ft_strlen(*cumul));
		if(x == 1)
			return (1);
		return(0);
	}
	return (0);
}

int		check_params(int fd, char **line, char **buf, int buff_size)
{
	if (BUFFER_SIZE == 0 || fd < 0 || !line ||
	!(*buf = ft_calloc(sizeof(char), (buff_size + 1)))
	|| !(*line = ft_calloc(1, sizeof(char))))
		return (-1);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	char *buf;
	static char *cumul = NULL;
	int read_file;

	if (check_params(fd, line, &buf, BUFFER_SIZE) == -1)
		return (-1);
	read_file = 1;
	while(read_file > 0 || (read_file == 0 && (cumul && *cumul)))
	{
		if(get_a_line(&cumul, line, read_file) == 1)
		{
			free(buf);
			return (1);
		}
		if((read_file = read(fd, buf, BUFFER_SIZE)) == -1)
		{
			free(buf);
			free(cumul);
			return (-1);
		}
		if(read_file != 0)
			cumul = ft_strjoin_gnl(cumul, buf, read_file);
	}
	free(buf);
	free(cumul);
	cumul = NULL;
	return (0);
}
