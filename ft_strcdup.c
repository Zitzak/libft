/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcdup.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/21 18:42:49 by mgross         #+#    #+#                */
/*   Updated: 2019/02/27 12:07:28 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function creates a new string up to (excl) char c from string *str and
** returns the new string.
*/

char	*ft_strcdup(const char *str, int c)
{
	int		i;
	char	*new;

	i = ft_findchar(str, c) - 1;
	if (i < 0)
		return (NULL);
	new = ft_strnew(i);
	if (new == NULL)
		return (NULL);
	ft_strncpy(new, str, i);
	return (new);
}
