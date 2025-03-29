# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/31 23:36:44 by pmendez-          #+#    #+#              #
#    Updated: 2025/03/29 19:38:26 by gsoteldo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m
CURRENT_FILE = 0
TOTAL_FILES = $(words $(FILES))
CLEAN_SHELL = \033[2K\r


NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror  -g3


FILES = src/minishell.c \
\
		src/utils_minishell.c \
		src/functions_to_start/treat_memory.c \
		src/functions_to_start/functions_needed.c \
		src/functions_to_start/create_prompt.c \
		src/functions_to_start/utils_functions_needed.c \
		src/utilss/utils.c \
		src/utilss/utils2.c \
		src/utilss/utils3.c \
		src/utilss/utils_pos.c \
		src/utilss/utils_path.c \
		src/utilss/utils_heredoc.c \
		src/utilss/utils_builtins.c \
		src/utilss/utils_expansion_env.c \
		src/utilss/env_utils.c \
		src/utilss/utils_general_expansion.c \
		src/utilss/utils_process_dollar.c \
		src/utilss/utils_expansion_pid.c \
		src/utilss/utils_expansion_not_alnum.c \
		src/utilss/utils_signals.c \
		src/exec/mult_exec/first_iteration.c \
		src/exec/mult_exec/last_iteration.c \
		src/exec/mult_exec/other_iterations.c \
		src/exec/execution.c \
		src/exec/utils_execution.c \
		src/exec/utils_execution2.c \
		src/exec/exec_one_command.c \
		src/exec/heredoc/exec_heredoc.c \
		src/exec/heredoc/heredoc_expansion.c \
		src/exec/heredoc/heredoc_expansion2.c \
		src/exec/builtins/exec_echo.c \
		src/exec/builtins/exec_echo_n.c \
		src/exec/builtins/exec_cd.c \
		src/exec/builtins/cd_extra.c \
		src/exec/builtins/exec_pwd.c \
		src/exec/builtins/exec_export.c \
		src/exec/builtins/exec_export_word_only.c \
		src/exec/builtins/export_add_array_str.c \
		src/exec/builtins/exec_unset.c \
		src/exec/builtins/unset_utils.c \
		src/exec/builtins/exec_env.c \
		src/exec/builtins/exec_exit.c \
		src/exec/redirections/redirection_config.c \
		src/exec/redirections/outfile_config.c \
		src/exec/redirections/utils_redirection.c \
		src/parse/parse.c \
		src/parse/quotes.c \
		src/parse/utils_quotes.c \
		src/parse/comand_list.c \
		src/parse/infiles_outfiles.c \
		src/parse/utils_parse.c \
		src/parse/utils_parse2.c \
		src/signals.c 

OBJS = $(FILES:.c=.o)

all: show_progress $(NAME)

$(NAME): $(OBJS) include/minishell.h
	@make -s -C libft
	@$(CC) $(FILES) -lncurses -L libft -lft -lreadline -o $(NAME)
	@echo "$(CLEAN_SHELL) $(GREEN)\n 🚀 Compilation finished! $(NC)👍"

%.o: %.c
	$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE) + 1))))
	@printf "$(CLEAN_SHELL) 🚀 Compiling $<... $(shell echo $$(($(CURRENT_FILE) * 100 / $(TOTAL_FILES))))%%"
	@$(CC) $(CFLAGS) -c $< -o $@

show_progress:
	@if [ -f $(NAME) ]; then \
		echo "$(GREEN)The compiled code is already updated.$(NC)"; \
	fi

clean:
	@rm -f $(OBJS)
	@make fclean -C libft
	@echo "Cleaning finished! 🧹"

fclean: clean
	@rm -f $(NAME)
	@make -s fclean -C libft
	@echo " Deleting finished! 🗑"

git:
	@git add .
	@git commit
	@git push

norm:
	@norminette src/*/*.c include/*.h

re: fclean all

.PHONY: all clean fclean re upload norm
