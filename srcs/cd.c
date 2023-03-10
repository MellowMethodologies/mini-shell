/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadr <sbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 16:46:55 by sbadr             #+#    #+#             */
/*   Updated: 2023/03/11 09:45:50 by sbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

void cd(char *str, char *home)
{
            if (str == NULL)
            {
                chdir(getenv("HOME"));
            } else {
                chdir(str);
            }
}