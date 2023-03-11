/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadr <sbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 10:30:43 by sbadr             #+#    #+#             */
/*   Updated: 2023/03/11 15:02:32 by sbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define WHITESPACE -1
#define WORD 0
#define DOUBLE_QUOTE 1
#define SINGLE_QUOTE 2
#define PIPE 3
#define GREAT 4
#define LESS 5
#define CHAR_TAB 6
#define CHAR_NEWLINE 7

int find_me(char *str, int endquot, int stat)
{
	char *ret;

	int rem = endquot;
	if (stat)
		while (str[endquot] != '\"')
			endquot++;
	else
		while (str[endquot] != '\'')
			endquot++;
	return(endquot);
}

void lexer(char *str, t_token *lex)
{
	int i = 0;
	int quo;
	char *s;
	
	lex = NULL;
	while (str[i])
	{
		if (str[i] == ' ')
			add_back(&lex, ft_lstne(strdup(" "), -1));
		else if (str[i] == '\"')
		{
			quo = find_me(str, i + 1, 1);
			add_back(&lex, ft_lstne(ft_substr(str, i + 1, quo - 1), 1));
			i += quo;
		}
		else if (str[i] == '\'')
		{
			quo = find_me(str, i + 1, 0);
			add_back(&lex, ft_lstne(ft_substr(str, i + 1, quo - 1), 2));
			i += quo;
		}
		else if (str[i] == '|')
			add_back(&lex, ft_lstne(strdup("|"), 3));
		else if (str[i] == '>')
			add_back(&lex, ft_lstne(strdup(">"), 4));
		else if (str[i] == '<')
			add_back(&lex, ft_lstne(strdup("<"), 5));
		else if (str[i] == '\t')
			add_back(&lex, ft_lstne(strdup("\t"), 6));
		else if (isalpha(str[i]))
		{
			int j = 0;
			while (isalpha(str[j]))
				j++;
			s = malloc(j + 1);
			if (!s)
				return ;
			j = 0;
			while (isalpha(str[i]))
				s[j++] = str[i++];
			s[j] = '\0';
			add_back(&lex, ft_lstne(s, 0));
			free(s);
			i--;
		}
		i++;
	}
	while(lex)
	{
		printf("value = |%s|\t type = |%d|\n", lex->value, lex->type);
		lex = lex ->next;
	}
}
