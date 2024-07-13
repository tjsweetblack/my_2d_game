/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badriano <badriano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:38:36 by badriano          #+#    #+#             */
/*   Updated: 2024/07/11 16:10:46 by badriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_map.h"

int num_Sub_Str(char const *s, char c)
{
	int i;
	int token;

	i = 0;
	token = 0;
	while(s[i] == c)
		i++;
	while(s[i])
	{
		if (s[i] == c)
			i++;
		if(!(s[i] == c))
		{
			token += 1;
			while(!(s[i] == c))
				i++;
		}
		i++;
	}
	return(token);
}


/*char **ft_split(char *s, char c)
{
	int i;
	int j;
	int l;
	int m;
	int sizearr = (num_Sub_Str(s, c) + 1);
	char **array;
	
	array = (char **) malloc (sizeof(char *) * sizearr);
	if (!array)
	{
		return(NULL);
	}
	i = 0;
	j = 0;
	while(s[i] == c)
		i++;
	while(s[i])
	{	
		if (s[i] == c)
			i++;
		if(!(s[i] == c))
		{
			l = i;
			while(!(s[i] == c))
				i++;
			array[j] = (char *) malloc (sizeof(char) * ((i - l) + 1));
			if(!(array[j]))
				return(NULL);
			m = 0;
			while(l != i)
			{
				array[j][m] = s[l];
				m++;
				l++;
			}
			array[j][m] = '\0';
			printf("%s\n", array[j]);
			j++;
		}
		i++;
	}
	array[j] = NULL;
	return(array);
}*/
size_t ft_strlen(char *s)
{
    size_t count = 0;
    while (s[count] != '\0')
        count++;
    return count;
}

char *ft_strjoin(char *s1, char *s2)
{
    char *result;
    size_t i, j, total_len;

    if (!s1)
    {
        s1 = malloc(sizeof(char) * 1);
        if (!s1)
            return (NULL);
        s1[0] = '\0';
    }
    total_len = ft_strlen(s1) + ft_strlen(s2);
    result = (char *)malloc((total_len + 1) * sizeof(char));
    if (result == NULL)
        return (NULL);
    i = 0;
    while (s1[i] != '\0')
    {
        result[i] = s1[i];
        i++;
    }
    j = 0;
    while (s2[j] != '\0')
        result[i++] = s2[j++];
    result[i] = '\0';
    free(s1);
    return (result);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (i < (dstsize - 1) && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}


static char	**ft_malloc_error(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static size_t	ft_nb_words(char const *s, char c)
{
	size_t	i;
	size_t	nb_words;

	if (!s[0])
		return (0);
	i = 0;
	nb_words = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			nb_words++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		nb_words++;
	return (nb_words);
}

static void	ft_get_next_word(char **next_word, size_t *next_word_len, char c)
{
	size_t	i;

	*next_word += *next_word_len;
	*next_word_len = 0;
	i = 0;
	while (**next_word && **next_word == c)
		(*next_word)++;
	while ((*next_word)[i])
	{
		if ((*next_word)[i] == c)
			return ;
		(*next_word_len)++;
		i++;
	}
}

char	**ft_split(char *s, char c)
{
	char	**tab;
	char	*next_word;
	size_t	next_word_len;
	size_t	i;

	if (!s)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (ft_nb_words(s, c) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	next_word = (char *)s;
	next_word_len = 0;
	while (i < ft_nb_words(s, c))
	{
		ft_get_next_word(&next_word, &next_word_len, c);
		tab[i] = (char *)malloc(sizeof(char) * (next_word_len + 1));
		if (!tab[i])
			return (ft_malloc_error(tab));
		ft_strlcpy(tab[i], next_word, next_word_len + 1);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
