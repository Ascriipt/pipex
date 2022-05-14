/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_lib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 21:55:39 by maparigi          #+#    #+#             */
/*   Updated: 2022/05/14 18:04:42 by maparigi         ###   ########.fr       */
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

/*-------------------------utilities-------------------------*/

size_t	ft_strlcat(char *dst, const char *src, size_t size);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

/*-----------------------------------------------------------*/

#endif