/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:05:35 by daeunki2          #+#    #+#             */
/*   Updated: 2025/05/04 15:09:01 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*get_next_line(int fd)
{
	static char		*backup;
	char			*line;
	char			*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (free(buf), NULL);
	backup = ft_file_read(fd, backup, buf);
	free(buf);
	if (!backup)
		return (NULL);
	line = ft_get_line(backup);
	backup = ft_get_backup(backup);
	return (line);
}

char	*ft_get_backup(char *backup)
{
	int		d;
	int		i;
	int		len;
	char	*new;

	i = 0;
	while (backup[i] != '\n' && backup[i] != '\0')
		i++;
	if (backup[i] == '\0')
		return (free(backup), NULL);
	len = ft_strlen(backup);
	new = malloc(sizeof(char) * (len - i + 1));
	if (new == NULL)
		return (free(backup), NULL);
	d = 0;
	while (backup[++i] != '\0')
		new[d++] = backup[i];
	new[d] = '\0';
	free(backup);
	return (new);
}

char	*ft_file_read(int fd, char *backup, char *buf)
{
	char	*rest;
	int		eof_cheack;

	eof_cheack = 1;
	while (eof_cheack != 0)
	{
		eof_cheack = read(fd, buf, BUFFER_SIZE);
		if (eof_cheack == -1)
			return (free(backup), NULL);
		buf[eof_cheack] = '\0';
		rest = backup;
		if (!rest)
			rest = ft_strdup("");
		backup = ft_strjoin (rest, buf);
		if (!backup)
			return (free(rest), NULL);
		free (rest);
		if (ft_strchr(backup, '\n') != NULL)
			break ;
	}
	return (backup);
}

char	*ft_get_line(char *backup)
{
	char	*line;
	int		i;
	int		len;

	i = 0;
	if (!backup[i])
		return (NULL);
	len = ft_strlen(backup);
	line = malloc(sizeof(char) * (len + 1));
	if (line == NULL)
		return (free(backup), NULL);
	while (backup[i] != '\n' && backup[i] != '\0')
	{
		line[i] = backup[i];
		i++;
	}
	if (backup[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}