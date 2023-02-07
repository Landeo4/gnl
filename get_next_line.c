/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: landeo <landeo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:54:18 by tpotilli@st       #+#    #+#             */
/*   Updated: 2023/02/07 14:20:58 by landeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_first_backup(char *backup, int fd)
{
	int		help;
	char	*buffer;

	help = 1;
	while (!ft_strchr(backup, '\n') && help != 0)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		help = read(fd, buffer, BUFFER_SIZE);
		if (help == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[help] = '\0';
		backup = free_join(backup, buffer);
		free(buffer);
	}
	return (backup);
}

char *ft_get_str(char *backup)
{
	char *str;
	int i;

	i = 0;
	//printf("%s", backup);
	while (backup[i] && backup[i] != '\n')
		i++;
	if (backup[i] == '\n')
		str = malloc(sizeof(char) * (i + 2));
	else if (backup[i] != '\n')
		str = malloc(sizeof(char) * (i + 1));
	//if (!str)
		//return (NULL);
	i = 0;
	while (backup[i] && backup[i] != '\n')
	{
		str[i] = backup[i];
		i++;
	}
	if (backup[i] == '\n')
	{
		str[i] = backup[i];
		i++;
	}
	str[i] = '\0';
	//printf("%s", str);
	return (str);
}

/*char *ft_next_line(char *backup)
{
	int i;
	int j;
	char *str;

	i = 0;
	j = 0;
	while (backup[i] && backup[i] != '\n')
		i++;
	if (backup[i] == '\0')
		str = malloc(sizeof(char) * (ft_strlen(backup) - i));
	else if (backup[i] != '\0')
		str = malloc(sizeof(char) * (ft_strlen(backup) - i + 1));
	printf("1 - %i\n", i);
	if (!str)
		return (NULL);
	i++;
	printf("2 - %i\n", i);
	while (backup[i])
	{
		str[j] = backup[i];
		i++;
		j++;
	}
	printf("3 - %i\n", i);
	printf("S - %i\n", j);
	str[j] = '\0';
	if (backup[i] == '\0')
	{
		printf("c 1 0\n");
	}
	if (backup[i] == '\n')
	{
		printf("c 1 n\n");
	}
	
	free(backup);
	return (str);
}*/
// lors de la derniere compilation il y a le \n qui s'ajoute au malloc
//
// essayer avec substr
char *ft_next_line(char *backup)
{
	int i;
	char *new;
	
	i = 0;
	//printf("%s", backup);
	while(backup[i] && backup[i] != '\n')
		i++;
	new = ft_substr(backup, i, ft_strlen(backup) - i + 1);
	free(backup);
	return (new);
}

char *get_next_line(int fd)
{
	static char *backup;
	char *str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	printf(" avant le first backup :%s\n", backup);
	backup = ft_first_backup(backup, fd);
	printf("apres le first backup:%s\n", backup);
	//printf("1 %s\n", backup);
	if (!backup)
		return (NULL);
	str = ft_get_str(backup);
	//printf("2%s\n", str);
	backup = ft_next_line(backup);
	//printf("3 %s\n", backup);
	return (str);
}
