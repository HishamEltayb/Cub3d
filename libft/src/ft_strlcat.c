/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:32:42 by heltayb           #+#    #+#             */
/*   Updated: 2024/06/26 13:23:47 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	destination_length;
	size_t	source_length;

	if (src != NULL && dstsize == 0)
		return (ft_strlen(src));
	source_length = ft_strlen(src);
	destination_length = ft_strlen(dst);
	if (destination_length > dstsize)
		return (dstsize + source_length);
	ft_strlcpy(dst + destination_length, src, dstsize - destination_length);
	return (destination_length + source_length);
}
#include <string.h>

int main()
{
	printf("%zu\n", ft_strlcat(NULL,NULL, 0));
	printf("%zu\n", strlcat(NULL,NULL, 0));
}