/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nozkara <nozkara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 20:56:41 by nozkara           #+#    #+#             */
/*   Updated: 2024/12/02 20:57:08 by nozkara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	expand_cmd(t_jobs *jobs, char **prompt)
{
	char	*expanded_prompt;

	if (!*prompt || !jobs)
		return ;
	expanded_prompt = expand_vars(jobs, *prompt);
	if (!expanded_prompt)
		return ;
	free(*prompt);
	*prompt = expanded_prompt;
}
