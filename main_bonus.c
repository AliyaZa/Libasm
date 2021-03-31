/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhill <nhill@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 19:05:25 by nhill             #+#    #+#             */
/*   Updated: 2021/03/30 18:36:03 by nhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

int			ft_list_size(t_list *begin_list);
void		ft_list_sort(t_list **begin_list, int (*cmp)());

void		print_list(t_list *list)
{
	while (list != NULL)
	{
		printf("%s", list->data);
		list = list->next;
	}
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ls;

	if (!new)
		return ;
	ls = *lst;
	if (!ls)
		*lst = new;
	else
	{
		while (ls->next)
			ls = ls->next;
		ls->next = new;
	}
}

t_list	*ft_lstnew(void *content)
{
	t_list *node;

	if (!(node = malloc(sizeof(t_list))))
		return (NULL);
	node->data = content;
	node->next = NULL;
	return (node);
}

int		main()
{
	t_list	*lst;
	t_list *lst1;
	t_list *lst2;
	lst = NULL;
	lst1 = NULL;
	lst2 = NULL;
	printf("FT_LST_SIZE:\n");
	lst = ft_lstnew("Hello ");
	ft_lstadd_back(&lst, ft_lstnew((void *)"my "));
	ft_lstadd_back(&lst, ft_lstnew((void *)"dear "));
	ft_lstadd_back(&lst, ft_lstnew((void *)"friend!\n"));
	printf("lst is \n");
	print_list(lst);
	printf("List has %d nodes\n", ft_list_size(lst));
	printf("lst is NULL\n");
	printf("List has %d nodes\n", ft_list_size(lst1));
	/*printf("\nFT_LIST_SORT:\n");
	ft_lstadd_back(&lst2, ft_lstnew((void *)"2 "));
	ft_lstadd_back(&lst2, ft_lstnew((void *)"2 "));
	ft_lstadd_back(&lst2, ft_lstnew((void *)"7 "));
	ft_lstadd_back(&lst2, ft_lstnew((void *)"5 "));
	ft_lstadd_back(&lst2, ft_lstnew((void *)"0 "));
	ft_lstadd_back(&lst2, ft_lstnew((void *)"1 "));
	ft_lstadd_back(&lst2, ft_lstnew((void *)"7 "));
	ft_lstadd_back(&lst2, ft_lstnew((void *)"7 "));
	ft_lstadd_back(&lst2, ft_lstnew((void *)"9\n"));
	printf("before:\n");
	print_list(lst2);
	printf("after sort:\n");
	ft_list_sort(&lst2, &strcmp);
	print_list(lst2);*/
	return(0);
}
