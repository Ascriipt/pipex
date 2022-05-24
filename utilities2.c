/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:25:31 by maparigi          #+#    #+#             */
/*   Updated: 2022/05/24 16:59:48 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_lib.h"

void	ft_free(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	if (tab)
		free(tab);
}

int	ft_strlenx(char *str, char x)
{
	int	i;
	int	n;

	n = 0;
	i = -1;
	while (str[++i])
		if (str[i] != x)
			n++;
	return (n);
}
