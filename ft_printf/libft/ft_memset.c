/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 15:01:28 by clianne           #+#    #+#             */
/*   Updated: 2019/09/06 15:17:14 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*buf;
	size_t			index;

	if (len == 0)
		return (b);
	buf = (unsigned char *)b;
	index = 0;
	while (len--)
		*buf++ = (unsigned char)c;
	return (b);
}
