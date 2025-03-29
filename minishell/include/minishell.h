/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 19:29:01 by pmendez-          #+#    #+#             */
/*   Updated: 2025/03/22 23:34:37 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <termios.h>
# include <term.h>
# include <dirent.h>
# include "../libft/libft.h"

extern sig_atomic_t	g_signal;

# define RED "\001\033[0;31m\002"
# define END "\001\033[0m\002"
# define READ 0
# define WRITE 1

# define COLOR_RESET "\001\033[0m\002"
# define COLOR_GREEN "\001\033[32m\002"
# define COLOR_LIGHT_BLUE "\001\033[38;5;39m\002"
# define COLOR_ORANGE "\001\033[38;5;208m\002"

# define NO_NEXT 0
# define NEXT_IS_AND 1
# define NEXT_IS_OR 2
# define NEXT_IS_PIPE 3

# define WRITE_OUTFILE 0
# define APPEND_OUTFILE 1

# define COLOR_RESET "\001\033[0m\002"
# define COLOR_GREEN "\001\033[32m\002"
# define COLOR_LIGHT_BLUE "\001\033[38;5;39m\002"
# define COLOR_ORANGE "\001\033[38;5;208m\002"

typedef struct s_exec
{
	int		fd[2];
	int		fd_temporal[2];
	int		pipe_aux[2];
	int		pipe_father[2];
	int		pid;
	int		last_pid;
	int		input;
	int		output;
	int		tmp_in;
	int		tmp_out;
	char	*infile;
	char	*outfile;
	int		output_type;
	int		index;
	int		num_cmds;
	int		input_redirection;
	int		output_redirection;
	int		there_is_heredoc;
	int		var_not_found;
	int		index_expansion;
	int		flag;

}	t_exec;

typedef struct s_outfile
{
	char				*outfile;
	int					type;
	struct s_outfile	*next;
}	t_outfile;

typedef struct s_command_list
{
	char					*command;
	char					**args;
	char					**infile;
	char					*heredoc_delimiter;
	int						fd_heredoc;
	int						is_heredoc;
	int						quotes_type;
	t_outfile				*outfile;
	int						todo_next;
	struct s_command_list	*next;
}	t_command_list;

typedef struct s_minishell
{
	char			**builtins;
	char			**separators;
	char			**args;
	char			**envp;
	char			**path;
	char			*line;
	char			*pwd_line;
	int				code;
	int				type_command;
	int				id_hd;
	char			**hd_files;
	t_exec			*exec;
	t_command_list	*command_list;
}	t_minishell;

//#############################################################################
//#############################  MINISHELL.C  #################################
//#############################################################################
void			start_shell(t_minishell *shell, char *line);
char			*command_before_parse(t_minishell *shell, char *comand);
void			parsing_and_execution(t_minishell *shell, char *comand);
void			checking_start_shell(t_minishell *shell, char **line, \
char **comand);
void			save_command(char *comand);
char			*get_prompt(t_minishell *shell);

//#############################################################################
//#############################  /UTILSS/UTILS_PATH.C  ########################
//#############################################################################
char			*search_path(t_minishell *shell, char **cmd_splitted);
char			**get_path(char **envp);
char			**obtain_env_to_envp_array(char **envp);
void			check_if_path_removed(t_minishell *shell);

// #############################################################################
// #############################  /UTILSS/UTILS_POS.C  #########################
// #############################################################################
int				ft_chrpos(char *str, int chr, int start);
int				idx(char **alphabet, char c);
int				idstr(char **alphabet, char *str);
int				index_of(char *str, char *search, int n);
int				index_newline(char *str);

// #############################################################################
// #############################  /UTILSS/UTILS.C  #############################
// #############################################################################
void			print_error(char *error_message, char *cmd, int exitCode);
void			print_no_exit(char *error_message, char *cmd);
void			close_fd(int *fd, char *name);
void			close_all_fds(t_minishell *shell);
void			error_no_cmd(char *error_message, int code, t_minishell *shell);

// #############################################################################
// #############################  /UTILSS/UTILS2.C  ############################
// #############################################################################
char			*ft_get_env(t_minishell *shell, char *str);
char			*get_whole_env_line(t_minishell *shell, char *str);
void			print_header(t_minishell *shell);
int				is_not_all_whitespaces(char *str);

// #############################################################################
// #############################  /UTILSS/UTILS3.C  ############################
// #############################################################################
void			separators_init(t_minishell *shell);
int				get_separators_type(char *comand);
int				is_separators(char *comand);
void			print_outfile(t_outfile *outfile);
void			print_list(t_command_list *command_list);
void			free_all_shell(t_minishell *shell);

// #############################################################################
// #############################  /UTILSS/UTILS_BUILTINS.C  ####################
// #############################################################################
int				is_builtin(t_minishell *shell, t_command_list *aux, char *line);
void			builtins_init(t_minishell *shell);

// #############################################################################
// #############################  /UTILSS/UTILS_HEREDOC.C  #####################
// #############################################################################
int				is_delimiter(char c);
char			*get_variable(char *str);
char			*get_argument(t_minishell *shell, int n);
int				is_in_env(char *temp, t_minishell *shell);
char			*command_before_parse(t_minishell *shell, char *comand);
int				write_line(char *line, t_command_list *new, char *del);

// #############################################################################
// #############################  /UTILSS/UTILS_EXPANSION_ENV.C  ###############
// #############################################################################
char			*env(t_minishell *shell, int *j, char *str);

// #############################################################################
// #######################  /UTILSS/ENV_UTILS.C  ###############################
// #############################################################################
char			*string_without_expansion(char *str, int *j, char *line, \
char *aux);
char			*safe_strdup_line(char *line);
char			*case_dollar(t_minishell *shell, char *temp, char *line, \
char *aux);

// #############################################################################
// #############################  /UTILSS/ENV_UTILS.C  #########################
// #############################################################################
char			*string_without_expansion(char *str, int *j, char *line, \
char *aux);
char			*safe_strdup_line(char *line);
char			*case_dollar(t_minishell *shell, char *temp, char *line, \
char *aux);

// #############################################################################
// #############################  /UTILSS/UTILS_PROCESS_DOLLAR.C  ##############
// #############################################################################
char			*expansion_dollar(char *line, char *temp, char *aux, \
char *line_aux);

// #############################################################################
// #############################  /UTILSS/UTILS_EXPANSION_PID.C  ###############
// #############################################################################
char			*expansion_pid(t_minishell *shell, int *j, char *str);

// #############################################################################
// #############################  /UTILSS/UTILS_EXPANSION_NOT_ALNUM.C  #########
// #############################################################################
char			*case_not_alnum(t_minishell *shell, char *str, int *j, \
char *line);

// #############################################################################
// ###################  /FUNCTIONS_TO_START/FUNCTIONS_NEEDED.C  ###############
// #############################################################################
void			print_str(char **str);
int				size_array(char **str);
char			**add_str_double_pointer(char **str, char *s);
int				find_char_pos(char *str, char c, int start);

// #############################################################################
// ###################  /FUNCTIONS_TO_START/CREATE_PROMPT.C  ###################
// #############################################################################
char			*create_prompt(char *pwd_line, char **envp);
char			*get_env_static(char **envp);

// #############################################################################
// ###################  /FUNCTIONS_TO_START/TREAT_MEMORY.C  ####################
// #############################################################################
void			initialize_struct(t_minishell *shell, char **envp);
void			free_double_str(char **str);

// #############################################################################
// #############################  SIGNALS.C  ###################################
// #############################################################################
void			signal_handler(int signum);
void			initialize_signals(void);
void			signal_infunction(void);
void			signal_heredoc(void);
int				is_shellexception(char **args, t_minishell *shell);
void			increase_shlvl(t_minishell *shell);

// #############################################################################
// #############################  /PARSE/PARSE.C  ##############################
// #############################################################################
int				end_args(char *comand, int end);
int				end_comand(char *comand, int end);
int				splitting_command(t_minishell *shell);
int				check_separators(t_minishell *shell);
t_command_list	*parsing(t_minishell *shell);
int				find_end(char *line, int *i);
void			free_error_splitting(t_minishell *shell, char *comand);
void			adding_double_args(t_minishell *shell, char *command);

// #############################################################################
// #############################  /PARSE/QUOTES.C  #############################
// #############################################################################
int				get_close_quote(char *comand, int end);
int				checking_quotes(char *comand);
void			clear_quotes(t_command_list *new);
void			add_args_quotes(char ***new, int i, char **splitted);
void			join_args_quotes(char **tmp2, char **splitted, int j, int type);

// #############################################################################
// #############################  /PARSE/INFILES_OUTFILES.C  ###################
// #############################################################################
int				append_redirections(char ***args, t_command_list *new, \
t_minishell *shell);

// #############################################################################
// #############################  /PARSE/COMAND_LIST.C  ########################
// #############################################################################
void			clear_command_list(t_command_list *comand_list);
int				new_arg(char ***args, t_command_list *new, t_minishell *shell);
void			new_node(t_command_list **new, t_command_list **shell, \
t_command_list **tmp);
int				create_comand_list(t_minishell *shell);

// #############################################################################
// #############################  /PARSE/UTILS_PARCE.C  ########################
// #############################################################################
void			free_command_list(t_minishell *shell);
void			free_list(t_command_list **command_list);
void			free_outfile_list(t_outfile *outfile);
void			open_parsing_heredoc(t_command_list *new);
int				comprobate_quotes(char *comand);
t_outfile		*new_outfile(char *file, int type);
void			add_args_outfile(char **outfile, char **splitted);

// #############################################################################
// ############################  /EXEC/UTILS_EXECUTION.C  ######################
// #############################################################################
void			do_exec(t_minishell *shell, char **line_completed, \
char *cmd);
void			execute(t_minishell *shell, t_command_list *aux);

// #############################################################################
// ############################  /EXEC/EXECUTION.C  ############################
// #############################################################################
void			execute_multiple_commands(t_minishell *shell);
void			handle_exec_command(t_minishell *shell);
void			execution_multiple(t_minishell *shell, t_command_list *aux);
void			execution_process(t_minishell *shell, t_command_list *aux);
void			close_pipe_father(t_minishell *shell);

// #############################################################################
// ############################  /EXEC/EXEC_ONE_COMMAND.C  #####################
// #############################################################################
void			check_builtins(t_minishell *shell);
void			exec_command_alone(t_minishell *shell);

// #############################################################################
// #################### /EXEC/MULT_EXEC/FIRST_ITERATION.C  #####################
// #############################################################################
void			first_iteration(t_minishell *shell);
void			outfile_management(t_minishell *shell, int *pipe);
void			last_infile(t_minishell *shell);

// #############################################################################
// #################### /EXEC/MULT_EXEC/LAST_ITERATION.C  ######################
// #############################################################################
void			last_iteration(t_minishell *shell);
void			infile_management(t_minishell *shell);

// #############################################################################
// #################### /EXEC/MULT_EXEC/OTHER_ITERATION.C  #####################
// #############################################################################
void			other_iterations(t_minishell *shell);

// #############################################################################
// #################### /EXEC/HEREDOC/EXEC_HEREDOC.C  ##########################
// #############################################################################
void			handle_heredoc(t_minishell *shell);
void			read_from_stdin(t_minishell *shell, char *del, \
t_command_list *new);
void			read_from_stdin_expansion(t_minishell *shell, char *del, \
t_command_list *new);
void			open_here_doc(t_minishell *shell, char *heredoc_delimiter, \
t_command_list *new);
char			*expansion_heredoc(t_minishell *shell, int *j, char *str);
int				check_signal(t_minishell *shell, char *line, \
t_command_list *new);

// #############################################################################
// #################### /EXEC/HEREDOC/HEREDOC_EXPANSION.C  #####################
// #############################################################################
char			*process_line_with_expansion(t_minishell *shell, char *line);
char			*temp_null(char *line, int aux, int *j, char *line_original);

// #############################################################################
// #################### /EXEC/HEREDOC/HEREDOC_EXPANSION2.C  ####################
// #############################################################################
char			*treat_expansion(t_minishell *shell, char *line, char *fusion, \
int *j);

// #############################################################################
// #################### EXEC/BUILTINS/EXEC_CD.C  ###############################
// #############################################################################
int				directory_change(char *cd_splitted, t_minishell *shell);
void			exec_cd(t_minishell *shell);

// #############################################################################
// #################### EXEC/BUILTINS/CD_EXTRA.C  ##############################
// #############################################################################
int				change_pwd(t_minishell *shell, char *path, int flag, \
char *old_pwd);
char			*home_case(t_minishell *shell, char *cd_splitted, \
char *old_pwd, int *code);
int				all_changes(t_minishell *shell, char **cd_splitted);
int				go_to_old_pwd(t_minishell *shell, char *old_pwd);

// #############################################################################
// #################### EXEC/BUILTINS/EXEC_ECHO_N.C  ###########################
// #############################################################################
void			exec_echo_n(t_minishell *shell);

// #############################################################################
// #################### EXEC/BUILTINS/EXEC_ECHO.C  #############################
// #############################################################################
void			exec_echo(t_minishell *shell);
void			process_line_in_quotes(t_minishell *shell, \
char *result, int i, int flag);

// #############################################################################
// #################### EXEC/BUILTINS/EXEC_ENV.C  ##############################
// #############################################################################
void			exec_env(t_minishell *shell);

// #############################################################################
// #################### EXEC/BUILTINS/EXEC_EXIT.C  #############################
// #############################################################################
void			exec_exit(t_minishell *shell);

// #############################################################################
// #################### EXEC/BUILTINS/EXEC_EXPORT_WORD_ONLY.C  #################
// #############################################################################
char			**ft_sort_array(char **envp);
void			exec_word_export_only(t_minishell *shell);
int				is_valid_format(char **temp, char *str);

// #############################################################################
// ############### EXEC/BUILTINS/EXPORT_ADD_ARRAY_STR.C  #######################
// #############################################################################
char			**add_array_str(t_minishell *shell, char **envp, char **temp \
, int size);
char			**other_func(t_minishell *shell, char **temp, char **aux, \
char **value);

// #############################################################################
// #################### EXEC/BUILTINS/EXEC_EXPORT.C  ###########################
// #############################################################################
void			exec_export(t_minishell *shell);

// #############################################################################
// #################### EXEC/BUILTINS/EXEC_PWD.C  ##############################
// #############################################################################
void			exec_pwd(void);

// #############################################################################
// #################### EXEC/BUILTINS/EXEC_UNSET.C  ###############
// #############################################################################
void			exec_unset(t_minishell *shell);

// #############################################################################
// #################### EXEC/BUILTINS/UNSET_UTILS.C  ###########################
// #############################################################################
void			delete_var_envp(t_minishell *shell, char **line);

// #############################################################################
// #################### EXEC/REDIRECTIONS/REDIRECTION_CONFIG.C  ################
// #############################################################################
void			reset_execution(t_minishell *shell);
void			init_redirections(t_minishell *shell);
void			handle_redirections(t_minishell *shell, t_command_list *aux);
int				is_fd_open(int fd, char *name);

// #############################################################################
// #################### EXEC/REDIRECTIONS/OUTFILE_CONFIG.C  ####################
// ############################################################################
char			*path_redirection_file(char *actual_path, char *file);
int				init_output(t_minishell *shell);

// #############################################################################
// #################### EXEC/REDIRECTIONS/UTILS_REDIRECTIONS.C  ################
// #############################################################################
int				ft_lstsize_outfile(t_outfile *lst);
void			add_exec_output(t_minishell *shell, t_outfile *tmp);
void			redirect_dev_null(t_minishell *shell);

//OTRAS FUNCIONES
void			expand_variables(t_minishell *shell);

#endif
