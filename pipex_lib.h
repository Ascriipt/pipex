/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_lib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 21:55:39 by maparigi          #+#    #+#             */
/*   Updated: 2022/05/24 17:14:09 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_LIB_H
# define PIPEX_LIB_H

# include <stdlib.h>
/* remove later */
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>

/*---------------------------main---------------------------*/

char	*find_apath(char **env);

/*-------------------------utilities-------------------------*/

char	**ft_split(char const *s, char c);

char	*ft_strjoin(char const *s1, char const *s2);
char	*add_path(char *str, char *av1, char c);
char	*access_path(char **paths, char *cmd);
char	*check_access(char **av, char **env);

int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strlenx(char *str, char x);

size_t	ft_strlen(const char *s);

void	ft_free(char **tab);

/*-----------------------------------------------------------*/

#endif