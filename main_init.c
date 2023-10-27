/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpollini <lpollini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:18:03 by naal-jen          #+#    #+#             */
/*   Updated: 2023/10/27 23:56:07 by lpollini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*creat_prompt(t_shell_stuff *shell, char *cmd_buff)
{
	cmd_buff = shft_prompt(shell, 0);
	loco()->exit = 0;
	return (cmd_buff);
}

t_loco	*loco(void)
{
	static t_loco	loco = {NULL, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		NULL, NULL, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	return (&loco);
}

void	reset_loco(void)
{
	*(loco()) = (t_loco){NULL, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		NULL, NULL, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
}

t_pare	*pare(void)
{
	static t_pare	pare = {0, NULL, 0, NULL, 0, 0, 0};

	return (&pare);
}

char	limiter_ok(char **comp, char *limiter)
{
	*comp = shft_get_word(limiter + 2, '\n');
	loco()->limiter_flag = 1;
	if (shft_strchr(*comp, '>', '\'', '\"') || shft_strchr(*comp, '<',
			'\'', '\"'))
		return (ft_putstr_fd("minishell: error: bad limiter\n",
				STDERR_FILENO), 0);
	return (1);
}
