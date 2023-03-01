/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadr <sbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 08:17:04 by sbadr             #+#    #+#             */
/*   Updated: 2023/02/28 18:53:10 by sbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

void print_err()
{
	write(2,"Error!\n",7);
	exit(1);
}

int main()
{
	char *line;
	char **tokens;
	pid_t pid = fork();
	int i = 0;
	printf("MINI-SHELL\n");
	while (1) {
		printf("> ");
		line = readline(line);
		add_history(line);
		tokens = ft_split(line, ' ');
		if (pid < 0)
			print_err();
		else if (pid == 0)
		{
			if (execv(tokens[0], tokens) < 0)
				print_err();
		}
		else
			waitpid(pid, &i, i);
		free(tokens);
		free(line);
	}
}
