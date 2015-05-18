/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell1.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 16:25:11 by abellion          #+#    #+#             */
/*   Updated: 2015/02/12 20:48:31 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL1_H
# define FT_MINISHELL1_H

# include <unistd.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/stat.h>
# include <dirent.h>
# include <errno.h>
# include "../libft/includes/libft.h"
# include "../gnl/get_next_line.h"

/*
** Declaration de structures
*/
typedef struct	s_cmd
{
	char	*name;
	char	*path;
	char	**args;
}				t_cmd;

typedef struct	s_infos
{
	char	*user_name;
	char	*path;
}				t_infos;

typedef struct	s_error
{
	int		number;
	char	*details;
}				t_error;

/*
**Declarations de typedef
*/
typedef void	(*t_printer)(t_error *error);

/*
** Prototypes utilities
*/
char			*get_from_env_tab(char *to_get, char **env);
char			*get_from_env_lst(char *to_get, t_list *env);
t_list			*env_creator(char **env);
t_error			*errors_init(int number, char *details);
void			errors_delete(t_error **error);
void			errors_controller(t_error *error, t_printer printer_fun);
int				args_checker(char **args, int nb_min, int nb_max);
int				is_option(char *options);
char			*args_input(char **args);
char			*options_formater(char **args);
char			*options_checker(char *available_options, char *options);
int				count_links(t_list *lst);
char			**lst_to_tab(t_list *lst);
t_list			*lst_dup(t_list *lst);
int				path_checker_exec(char *path);
int				path_checker_exist(char *path);
int				path_checker_rights(char *path);
int				path_checker_isreg(char *path);
int				path_checker_isdir(char *path);
char			*path_clear(char *path);
char			*path_formater(char *cwd, char *input);
char			*ft_tabjoin(char **tab);
int				ft_tablen(char **tab);
void			tab_free(char ***tab);

/*
**Prototypes prompt
*/
char			*prompt_controller(t_list *env, int get_input);
char			*curent_directory(char *path, char *user_name);
void			prompt_line(char *user_name, char *curent_d);

/*
**Prototypes cmd
*/
t_cmd			*cmd_controller(char *to_exec, t_list *env);
void			cmd_errors_printer(t_error *error);
char			**cmd_formater(char *str, t_list *env);
char			is_delimiteur(char curent, char prev, char delimiteur);
int				return_part(char *str, char **save);
char			**make_parts(char *str);
char			**clear_parts(char **parts, t_list *env);
char			*replace_special(char *str, t_list *env);
char			*clear_exhausts(char *str);
char			*cmd_path(char **path_list, char *cmd_name);
char			**cmd_args(char *path, char **cmd);
t_cmd			*cmd_init(char *name, char *path, char **args);
void			cmd_delete(t_cmd **cmd);

/*
**Prototypes laucher
*/
void			launcher_controller(t_cmd *cmd, t_list **env);
int				is_available(char *available_cmd, char *cmd);
void			launcher_binary(t_cmd *cmd, t_list **env);
void			launcher_builtin(t_cmd *cmd, t_list **env);
void			launcher_errors_printer(t_error *error);

/*
**Prototypes builtin env
*/
void			env_errors_printer(t_error *error);
int				env_env(char **args, t_list **env);
int				env_env_ignore(char **args);
t_list			*env_env_set(char **args, t_list *env);
int				env_env_launcher(char **args, t_list *env);
int				env_setenv(char **args, t_list **env);
t_list			*env_set(char *name, char *value, t_list *env);
int				env_unsetenv(char **args, t_list **env);
t_list			*env_unset(char *unset_name, t_list *env);

/*
**Prototypes builtin cd
*/
void			cd_errors_printer(t_error *error);
int				builtin_cd(char **args, t_list **env);
char			*determine_path(char *path, t_list *env);
char			*absolute_path(char *home);
char			*relative_path(char *pwd, char *path);
char			*cd_option_p(char *path);
int				cd_errors(char *options, char *input);

/*
**Prototypes builtin exit
*/
void			exit_errors_printer(t_error *error);
int				builtin_exit(char **args);
void			exit_prog(void);

void			disp_lst(t_list *lst);

#endif
