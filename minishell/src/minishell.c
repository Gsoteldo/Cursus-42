/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 16:04:10 by pmendez-          #+#    #+#             */
/*   Updated: 2025/03/22 19:46:36 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	g_signal = 0;

static void	check_if_removed(void)
{
	char	*aux_pwd;
	char	*cwd;
	DIR		*dir;

	cwd = getcwd(NULL, 0);
	aux_pwd = getenv("PWD");
	if (!cwd)
	{
		dir = opendir(aux_pwd);
		while (!dir && aux_pwd[0])
		{
			*(ft_strrchr(aux_pwd, '/')) = '\0';
			dir = opendir(aux_pwd);
		}
		if (dir)
		{
			closedir(dir);
			chdir(aux_pwd);
		}
	}
	free(cwd);
}

/**
 * Funcion que se va a encargar en obtener el prompt del usuario, que se va a
 * mostrar en la terminal.
 * 
 * Si no se puede obtener el directorio actual, se imprime un mensaje de error y
 * se asigna un prompt por defecto "minishell bash-bros> ".
 * 
 * @param shell: Un puntero a la estructura `t_minishell` que gestiona el
 * shell.
 * 
 * @return char *: El prompt que se va a mostrar en la terminal.
 */
char	*get_prompt(t_minishell *shell)
{
	char	*pwd_line;
	char	*prompt;
	char	*comand;

	comand = NULL;
	check_if_removed();
	pwd_line = getcwd(NULL, 0);
	if (pwd_line == NULL)
		print_no_exit("Error getting current directory", "pwd");
	else
	{
		prompt = create_prompt(pwd_line, shell->envp);
		free(pwd_line);
		return (prompt);
	}
	return (comand);
}

// void	save_command(char *comand)
// {
// 	int	fd;

// 	add_history(comand);
// 	if (access(".minishell_history", F_OK) == 0)
// 		fd = open(".minishell_history", O_RDWR | O_APPEND);
// 	else
// 		fd = open(".minishell_history", O_CREAT | O_RDWR, 0644);
// 	ft_putendl_fd(comand, fd);
// 	close(fd);
// }

// char	*command_before_parse(t_minishell *shell, char *comand)
// {
// 	shell->line = ft_strtrim(comand, " ");
// 	if (!shell->line)
// 		return (0);
// 	return (shell->line);
// }

// void	parsing_and_execution(t_minishell *shell, char *comand)
// {
// 	if (shell->line)
// 		free(shell->line);
// 	shell->line = command_before_parse(shell, comand);
// 	if (!shell->line)
// 	{
// 		free(comand);
// 		comand = NULL;
// 		return ;
// 	}
// 	shell->command_list = parsing(shell);
// 	if (!shell->command_list)
// 	{
// 		free(comand);
// 		comand = NULL;
// 		return ;
// 	}
// 	save_command(shell->line);
// 	handle_exec_command(shell);
// }

// void	checking_start_shell(t_minishell *shell, char **line, char **comand)
// {
// 	if (shell->command_list)
// 		free_command_list(shell);
// 	check_if_path_removed(shell);
// 	*line = get_prompt(shell);
// 	if (comand != NULL)
// 		free(*comand);
// 	*comand = readline(*line);
// 	if (!(*comand))
// 	{
// 		close_all_fds(shell);
// 		free(*line);
// 		rl_clear_history();
// 		free_all_shell(shell);
// 		exec_exit(NULL);
// 	}
// }

/**
 * Inicia el bucle principal del shell interactivo, que se llama desde el main.
 *
 *
 * Si el usuario ingresa "exit", el bucle se interrumpe y el shell termina.
 * También se maneja cualquier error de `readline`, como una interrupción de
 * la entrada. En el caso de que el usuario presione `Ctrl + D`, el shell se
 * cierra de forma segura.
 *
 * Si el comando ingresado es "cat", se activa la variable global `cat_running`
 * para que cuando se ejecute el comando, se pueda leer la entrada del usuario,
 * mostrarla en la salida estándar y si utilizas "Ctrl + C" para salir del
 * proceso hijo, que no se duplique el prompt
 *
 * Se abre el archivo `.minishell_history` en modo de lectura y escritura, si
 * no existe, se crea. Se guarda el comando ingresado por el usuario en el
 * archivo de historial; para poder mantener todos los comandos que se han
 * ido utilizando en las distintas ejecuciones de nuestro proyecto.
 * No solamente eso, sino que también se guarda en el historial de `readline`;
 * para poder utilizar las flechas arriba y abajo para navegar por los comandos
 * que se han utilizado en la sesión actual.
 * 
 * Se ejecuta el comando ingresado por el usuario, se parsea y se ejecuta.
 *
 * @param shell: Un puntero a la estructura `t_minishell` que gestiona el
 *
 * @param line: Es el formato del prompt que se muestra al usuario; todo
 * lo que va antes de la entrada del usuario.
 *
 */
void	start_shell(t_minishell *shell, char *line)
{
	struct termios	term;
	char			*comand;

	comand = NULL;
	tcgetattr(0, &term);
	term.c_lflag &= ~ECHOCTL;
	tcsetattr(0, TCSANOW, &term);
	g_signal = 0;
	while (1)
	{
		checking_start_shell(shell, &line, &comand);
		g_signal = 0;
		free(line);
		if (is_not_all_whitespaces(comand) == 1)
		{
			free(comand);
			comand = NULL;
			continue ;
		}
		if (comand && *comand)
			parsing_and_execution(shell, comand);
		while (waitpid(-1, NULL, 0) > 0)
			;
	}
}

static void	initialize_history(void)
{
	int		fd;
	char	*line;
	char	*trimmed;

	fd = open(".minishell_history", O_RDONLY);
	if (fd < 0)
		return ;
	line = get_next_line(fd);
	while (line != NULL)
	{
		trimmed = ft_strtrim(line, "\n");
		free(line);
		if (trimmed != NULL)
			add_history(trimmed);
		free(trimmed);
		line = get_next_line(fd);
	}
	close(fd);
}

/**
 *
 * Inicializa la estrctura de sigaction para manejar las señales de interrupción
 * y salida del shell.
 *
 * Inicializa la estructura `t_minishell` con valores predeterminados.
 *
 * Muestra el header del SHELL; nombre de proyecto con environment o sin ellas.
 *
 * Obtiene el prompt del usuario, que se muestra en la terminal; y la guarda en
 * la variable `line` que mas tarde se va a pasar a la función de `start_shell`.
 *
 * @param handler: Un puntero a la estructura `t_minishell` que se inicializa.
 * @param envp: Un puntero a la lista de variables de entorno, la cual
 * llega desde los parametros del main.
 * 
 * @return int 0 si todo sale bien.
 */

int	main(int argc, char *argv[], char *envp[])
{
	t_minishell			shell;
	char				*line;

	(void)argv;
	line = NULL;
	shell = (t_minishell){0};
	initialize_signals();
	if (argc > 1)
	{
		ft_printf("Error: minishell does not accept arguments\n");
		return (1);
	}
	initialize_struct(&shell, envp);
	initialize_history();
	print_header(&shell);
	start_shell(&shell, line);
	free_all_shell(&shell);
	rl_clear_history();
	return (0);
}
