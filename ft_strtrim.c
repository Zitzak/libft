/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgross <mgross@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/09 14:37:05 by mgross         #+#    #+#                */
/*   Updated: 2019/11/09 16:03:22 by mgross        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_in_set(char c, const char *set)
{
	int		set_index;

	set_index = 0;
	while (set[set_index] != '\0')
	{
		if (c == set[set_index])
			return (1);
		set_index++;
	}
	return (0);
}

static int	skip_begin(char const *string, char const *set, int str_len)
{
	int		str_index;

	str_index = 0;
	while (string[str_index] != '\0')
	{
		if (check_in_set(string[str_index], set))
			str_index++;
		else
			break ;
	}
	if (str_index == str_len)
		return (0);
	else
		return (str_index);
}

static int	skip_end(char const *string, char const *set, int str_len)
{
	int		str_index;

	str_index = str_len - 1;
	while (str_index >= 0)
	{
		if (check_in_set(string[str_index], set))
			str_index--;
		else
			break ;
	}
	return (str_len - str_index);
}

char		*ft_strtrim1(char const *s1, char const *set)
{
	int		begin;
	int		str_len;
	int		end;
	char	*new_str;

	if (s1 == NULL || set == NULL)
		return (NULL);
	str_len = ft_strlen(s1);
	begin = skip_begin(s1, set, str_len);
	end = skip_end(s1, set, str_len);
	str_len = str_len - (begin + end);
	new_str = (char*)malloc(sizeof(char) * (str_len + 1));
	if (new_str == NULL)
		return (NULL);
	new_str = ft_strncpy(new_str, &(s1[begin]), (size_t)str_len + 1);
	new_str[str_len + 1] = '\0';
	return (new_str);
}
