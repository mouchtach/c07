/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 19:20:01 by ymouchta          #+#    #+#             */
/*   Updated: 2024/09/17 16:31:41 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i); 
}

char	*ft_strcat(char *maloc, char **str, char *sep, int size)
{
	int	i;
	int	j;
	int	t;

	j = 0;
	t = 0;
	while (j <= size - 1)
	{
		i = 0;
		while (str[j][i])
			maloc[t++] = str[j][i++];
		i = 0;
		while (sep[i] && j < size - 1)
			maloc[t++] = sep[i++];
		j++;
	}
	maloc[t] = '\0';
	return (maloc);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		total;
	int		sepp;
	char	*maloc;

	total = 0;
	i = 0;
	if (size == 0)
		return (NULL);
	while (i <= size - 1)
	{
		total = str_len(strs[i]) + total;
		i++;
	}
	sepp = str_len(sep) * (size - 1);
	if (size > 0)
	{
		maloc = malloc (sizeof(char) * (total + sepp + 1));
		if (maloc == NULL)
			return (NULL);
		return (ft_strcat(maloc, strs, sep, size));
	}
	return (NULL);
}

#include <stdio.h>
int main()
{
    char *strs[] = {"youssef", "mouchtach", "you", "are ", "student", "now" , "ohogho"};
    char sep[] = "///";
    printf("%s\n", ft_strjoin(7, strs, sep));
}