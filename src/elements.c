/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 09:04:33 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/05 19:12:26 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 08:58:58 by heltayb           #+#    #+#             */
/*   Updated: 2024/07/03 09:00:14 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_element	*element_new(void **content);
void		element_add_back(t_element **lst, t_element *new);
void		element_delone(t_element *lst, void (*del)(void ***));
void		element_clear(t_element **lst, void (*del)(void ***));
t_element	*element_last(t_element *lst);

t_element	*element_new(void **content)
{
	t_element	*node;

	node = malloc(sizeof(t_element));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

void	element_add_back(t_element **lst, t_element *new)
{
	t_element	*start;

	if (lst == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	start = *lst;
	(*lst) = element_last(*lst);
	(*lst)->next = new;
	*lst = start;
}

t_element	*element_last(t_element *lst)
{
	t_element	*temp;

	if (lst == NULL)
		return (NULL);
	temp = lst;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}

void	element_delone(t_element *lst, void (*del)(void ***))
{
	if (lst == NULL || !del)
		return ;
	del(&lst->content);
	free (lst);
}

void	element_clear(t_element **lst, void (*del)(void ***))
{
	t_element	*temp;
	t_element	*node;

	if (lst == NULL || del == NULL || (*lst) == NULL)
		return ;
	node = *lst;
	while (node != NULL)
	{
		temp = node->next;
		element_delone(node, del);
		node = temp;
	}
	*lst = NULL;
}