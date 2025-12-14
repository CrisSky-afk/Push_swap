/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csuomins <csuomins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:34:02 by csuomins          #+#    #+#             */
/*   Updated: 2025/12/14 13:58:57 by csuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		len;
	char	*size;

	len = ft_strlen((char *)s);
	size = (char *)malloc((len + 1) * (sizeof(char)));
	if (!size)
		return (NULL);
	ft_memcpy(size, s, len);
	size[len] = '\0';
	return (size);
}
