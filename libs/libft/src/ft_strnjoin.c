/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:29:26 by heltayb           #+#    #+#             */
/*   Updated: 2024/08/04 13:57:31 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(int total, char **arry2d)
{
	int			i;
	char		*tmp;
	char		*result;

	i = 0;
	result = NULL;
	while (i < total)
	{
		tmp = ft_strjoin(result, arry2d[i]);
		if (!tmp)
			return (free(result), NULL);
		free(result);
		result = tmp;
		tmp = NULL;
		i++;
	}
	return (result);
}
