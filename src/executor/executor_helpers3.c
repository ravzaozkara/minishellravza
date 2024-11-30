/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer_helpers3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nozkara <nozkara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 23:31:13 by nozkara           #+#    #+#             */
/*   Updated: 2024/11/30 23:37:39 by nozkara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static char *build_env_string(char *key)
{
	char *env_entry;
	char *temp_str;

	env_entry = ft_strdup(key);
	if (!env_entry)
		return (NULL);

	temp_str = env_entry;
	env_entry = ft_strjoin_const(env_entry, "=");
	free(temp_str);

	return (env_entry);
}

static char *append_env_value(char *env_entry, char *value)
{
	char *temp_str;
	char *result;

	temp_str = env_entry;
	result = ft_strjoin_const(env_entry, value);
	free(temp_str);

	return (result);
}

static int add_to_env_array(char ***env_array, char *env_entry)
{
	*env_array = str_arr_realloc(*env_array, env_entry);
	if (!*env_array)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

char **get_env_for_exec(t_env *env)
{
	char **env_array;
	char *env_entry;
	int index;

	env_array = NULL;
	index = 0;
	while (index < env->len)
	{
		env_entry = build_env_string(env->key[index]);
		if (!env_entry)
			return (NULL);

		env_entry = append_env_value(env_entry, env->value[index]);
		if (!env_entry)
			return (NULL);

		if (add_to_env_array(&env_array, env_entry))
		{
			free(env_entry);
			return (NULL);
		}
		free(env_entry);
		index++;
	}
	return (env_array);
}