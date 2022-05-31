/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_lib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 21:55:39 by maparigi          #+#    #+#             */
/*   Updated: 2022/05/31 17:34:51 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_LIB_H
# define PIPEX_LIB_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>

/*---------------------------main---------------------------*/

char	*find_apath(char **env);

/*-------------------------utilities-------------------------*/

char	**ft_split(char const *s, char c);

char	*add_path(char *str, char *av1, char c);
char	*access_path(char **paths, char *cmd);
char	*check_access(char **env, char *cmd);
char	*find_apath(char **env);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

size_t	ft_strlen(const char *s);

void	ft_free(char **tab);

/*-----------------------------------------------------------*/

#endif