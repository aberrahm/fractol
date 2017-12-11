/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberrahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 00:33:52 by aberrahm          #+#    #+#             */
/*   Updated: 2016/12/26 19:06:43 by aberrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	size_t		i;
	char		*s2;
	size_t		len;
	char		*s3;

	s3 = (char *)s1;
	i = 0;
	len = 0;
	while ((s3[len] != '\0') && (len < n))
		len++;
	if (!(s2 = (char *)malloc(sizeof(*s3) * (len + 1))))
		return (NULL);
	while ((s3[i] != '\0') && (i < n))
	{
		s2[i] = s3[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
