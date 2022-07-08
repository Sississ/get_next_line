/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschofer <sschofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 10:21:23 by sschofer          #+#    #+#             */
/*   Updated: 2022/07/08 13:41:43 by sschofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*js;
	size_t	i;

	if (!s1)
	s1 = (char *)calloc(1, sizeof(char));
	if (!s1 || !s2)
		return (NULL);
	js = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!js)
		return (NULL);
	i = 0;
	while (*s1 != '\0')
	{
		js[i] = *s1++;
		i++;
	}
	while (*s2 != '\0')
	{
		js[i] = *s2++;
		i++;
	}
	js[i] = 0;
	return (js);
}

// char	*ft_strchr(const char *s, int c)
// {
// 	while (*s != '\0' && *s != (char)c)
// 	{
// 		s++;
// 	}
// 	if (*s == (char)c)
// 	{
// 		return ((char *)s);
// 	}
// 	return (NULL);
// }

char	*ft_strchr(const char *str, int c)
{
	int	i;

	if (str)
	{
	i = 0;
	while (str[i] && (char)str[i] != (char)c)
			i++;
		if ((char)str[i] == (char)c)
			return ((char *)&str[i]);
	}
	return (NULL);
}


size_t	ft_lenton(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
	{
		i++;
	}
	return (i);
}

