/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtok.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadr <sbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:14:50 by sbadr             #+#    #+#             */
/*   Updated: 2023/03/07 16:41:58 by sbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

char *ft_strtok(char *str, const char *sep)
{
	static char *arr;
	static int status = 1;
	static int i = 0;
	static int var;
	var = i;
	char *ret;
	int j;
	int brakes = 1;
	if (str != NULL && status == 1)
		arr = ft_strdup(str);
	// printf("%s",arr);
	while(arr[i] && brakes)
	{
		j = 0;
		while(sep[j])
		{
			if(sep[j] == arr[i])
			{
	// i = 7 / var = 7 / arr  ->  strdup (hello world !) / ret = hello / status = 0;
				while(arr[i] == sep[j])
					i++;
				ret = ft_substr(arr, var, i - var);
				brakes = 0;
			}
			j++;
		}
		i++;
	}
	status = 0;
	return (ret);
}

int main()
{
	char str[14] = "hello world !";
	printf("%s", ft_strtok(str, " \n"));
	printf("%s", ft_strtok(NULL, " "));
	printf("%s", ft_strtok(NULL, " "));
	printf("%s", ft_strtok(NULL, " "));

}