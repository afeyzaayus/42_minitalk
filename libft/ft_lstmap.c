/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserbest <aserbest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:40:58 by aserbest          #+#    #+#             */
/*   Updated: 2025/01/15 07:50:46 by aserbest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	content = f(lst->content);
	new_node = ft_lstnew(content);
	if (!new_node)
	{
		del(content);
		ft_lstclear(&new_node, del);
		return (NULL);
	}
	new_node->next = ft_lstmap(lst->next, f, del);
	return (new_node);
}
