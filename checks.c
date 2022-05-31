/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:01:46 by maparigi          #+#    #+#             */
/*   Updated: 2022/05/31 21:11:48 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_lib.h"

char	*check_access(char **env, char *cmd)
{
	char	**paths;
	char	*str;

	paths = ft_split(find_apath(env), ':');
	str = access_path(paths, cmd);
	if (str == NULL)
	{
		free(str);
		ft_free(paths);
		return (NULL);
	}
	ft_free(paths);
	return (str);
}
