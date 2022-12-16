/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 12:41:56 by cpost         #+#    #+#                 */
/*   Updated: 2022/04/22 13:34:46 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
Function:
	Iterates the list ’lst’ and applies the function 
	’f’ on the content of each node. Creates a new 
	list resulting of the successive applications of 
	the function ’f’. The ’del’ function is used to 
	delete the content of a node if needed.
Input: 
	- lst: The address of a pointer to a node.
	- f: The address of the function used to iterate on 
	the list.
	- del: The address of the function used to delete 
	the content of a node if needed.
Return value: 
	The new list. NULL if the allocation fails.
*/

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*new;

	if (!lst)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	if (!new)
		return (NULL);
	temp = new;
	lst = lst->next;
	while (lst)
	{
		temp->next = ft_lstnew(f(lst->content));
		temp = temp->next;
		if (!temp)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		lst = lst->next;
	}
	return (new);
}
