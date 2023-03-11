/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtok.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadr <sbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:14:50 by sbadr             #+#    #+#             */
/*   Updated: 2023/03/10 17:37:59 by sbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

int avoid_sep(char *str, const char *sep)
{
	int i = 0;

	while (ft_strchr(sep, str[i]) != NULL)
		i++;
	return(i);
}

char *ft_strtok(char *str, const char *sep)
{
	static char *arr;
	static int status = 1;
	char *ret;
	int var;
	int brakes = 1;
	int j;

	if (str == NULL && status == 1)
		return NULL;

	if (str != NULL)
		arr = strdup(str);
	int i = avoid_sep(arr, sep);
	j = i;
	while (ft_strchr(sep, str[i]) == NULL)
		i++;
	ret = ft_substr(arr, j, i);
	printf("%s\n",);
	arr = ft_strdup(arr + i);
	status = 0;

	// if (*arr == '\0')
	// {
	// 	free(arr);
	// 	arr = NULL;
	// }

	return ret;
}

int main()
{
	char str[22] = "hello    world !";
	char *token = ft_strtok(str, " \n");
	printf("%s\n", token);
	token = ft_strtok(NULL, " \n");
	printf("%s\n", token);
	return 0;
}
