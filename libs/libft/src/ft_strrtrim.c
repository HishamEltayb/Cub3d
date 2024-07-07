/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrtrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:19:28 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/07 09:31:17 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrtrim(char *s, char c)
{
	int		size;
	char	*temp;

	if (!s || !*s)
		return (NULL);
	if (ft_strlen(s) == 0)
		return (ft_strdup(""));
	size = ft_strlen(s) - 1;
	while (size > 0 && s[size] == c)
		size--;
	temp = ft_substr(s, 0, size + 1);
	return (temp);
}