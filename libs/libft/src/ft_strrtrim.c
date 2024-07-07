/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrtrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:19:28 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/07 13:57:29 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(char c, char set)
{
	if (set == c)
		return (1);
	return (0);
}

char	*ft_strrtrim(char *s, char c)
{
	int	size;
	int	i;

	if (s == NULL || !c)
		return (NULL);
	size = ft_strlen(s) - 1;
	i = 0;
	while (check(s[i], c))
		i++;
	if (i == (size + 1))
		return (ft_strdup(""));
	while (check(s[size], c))
		size--;
	return (ft_substr(s, 0, ((size + 1))));
}
