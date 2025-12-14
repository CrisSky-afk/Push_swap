/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csuomins <csuomins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 20:13:38 by csuomins          #+#    #+#             */
/*   Updated: 2025/12/14 13:58:08 by csuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char			*s;
	char				*d;
	const char			*last_s;
	char				*last_d;

	if (!dest && !src)
		return (NULL);
	d = dest;
	s = src;
	if (d < s)
		while (n--)
			*d++ = *s++;
	else
	{
		last_s = (s + (n - 1));
		last_d = (d + (n - 1));
		while (n--)
			*last_d-- = *last_s--;
	}
	return (dest);
}
