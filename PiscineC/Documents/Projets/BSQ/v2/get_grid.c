/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_grid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/24 12:06:15 by dtedgui           #+#    #+#             */
/*   Updated: 2015/08/27 15:54:03 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char		*ft_strcat(char *dest, char *src, int size)
{
	char	*temp;
	int		size_dest;
	int		i;

	temp = (char*)malloc((size + 1) * sizeof(char));
	size_dest = 0;
	while (dest != NULL && dest[size_dest])
	{
		temp[size_dest] = dest[size_dest];
		size_dest++;
	}
	i = 0;
	while (i < (size - size_dest))
	{
		temp[size_dest + i] = src[i];
		i++;
	}
	temp[size_dest + i] = '\0';
	free(dest);
	return (temp);
}

char		**grid_str_to_tab(char *str, t_grid_specs *grid_specs, int i)
{
	char	**tab_grid;
	int		j;
	int		k;

	j = 0;
	k = 0;
	tab_grid = (char**)malloc(sizeof(char*) * grid_specs->lines);
	tab_grid[j] = (char*)malloc(sizeof(char) * (grid_specs->columns + 1));
	while (str[i])
	{
		if (str[i] == '\n')
		{
			tab_grid[j][k] = '\0';
			j++;
			k = 0;
			i++;
			tab_grid[j] = (char*)
				malloc(sizeof(char) * (grid_specs->columns + 1));
		}
		tab_grid[j][k] = str[i];
		i++;
		k++;
	}
	return (tab_grid);
}

char		*get_from_stdin(void)
{
	int		ret;
	int		size;
	char	str[50];
	char	*grid;

	size = 0;
	ret = 0;
	grid = NULL;
	while ((ret = read(0, str, 50)))
	{
		size += ret;
		grid = ft_strcat(grid, str, size);
	}
	return (grid);
}

char		*get_from_file(char *file)
{
	int		fd;
	char	str[50];
	char	*grid;
	int		size;
	int		ret;

	size = 0;
	ret = 0;
	grid = NULL;
	if (-1 == (fd = open(file, O_RDONLY)))
		return ("map error");
	while ((ret = read(fd, str, 50)))
	{
		size += ret;
		grid = ft_strcat(grid, str, size);
	}
	return (grid);
}
