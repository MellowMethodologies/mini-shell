/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtok.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadr <sbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:14:50 by sbadr             #+#    #+#             */
/*   Updated: 2023/03/09 11:40:12 by sbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

int avoid_sep(char *str, const char *sep)
{
	int i = 0;
	int j = 0;
	int brakes = 0;
	int brake = 1;

	while(str[i] && brake)
	{
		j = 0;
		while(sep[j])
		{
			if(str[i] == sep[j])
			{
				while(sep[j] == str[i++])
					brakes++;
			}
			else
				brake = 0;
			j++;
		}
		i++;
	}
	return(brakes);
}

char *ft_strtok(char *str, const char *sep)
{
	static char *arr;
	static int status = 1;
	char		*ret;
	int			var;
	int			brakes = 1;
	int			j;
	if (str != NULL && status == 1)
		arr = ft_strdup(str);
	int			i = avoid_sep(arr, sep);
	// printf("i = %d \n",i);
	while(arr[i] && brakes)
	{
		j = 0;
		while(sep[j])
		{
			if(sep[j] == arr[i])
			{
				var = i;
				brakes = 0;
			}
			j++;
		}
		i++;
	}
	// printf("var = %i\n",var);
	ret = ft_substr(arr, avoid_sep(arr, sep), var);
	arr = ft_strdup(arr + var);
	status = 0;
	return (ret);
}

int main()
{
	char str[22] = "hello \n    world\n!";
	printf("%s", ftstrtok(str, " \n"));
	printf("%s", strtok(NULL, " \n"));
	// printf("%s", strtok(NULL, " \n"));
	// printf("%s", ft_strtok(NULL, " "));
}