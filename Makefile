# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abellion <abellion@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/25 21:03:07 by abellion          #+#    #+#              #
#    Updated: 2015/02/17 16:47:03 by abellion         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_C =	gnl/get_next_line.c \
		program_files/src/main.c \
		program_files/src/utilities/utilities_env.c \
		program_files/src/utilities/utilities_args.c \
		program_files/src/utilities/utilities_errors.c \
		program_files/src/utilities/utilities_lst.c \
		program_files/src/utilities/utilities_path_checker.c \
		program_files/src/utilities/utilities_path_formater.c \
		program_files/src/utilities/utilities_tab.c \
		program_files/src/prompt/prompt_controller.c \
		program_files/src/cmd/cmd_controller.c \
		program_files/src/cmd/cmd_determine.c \
		program_files/src/cmd/cmd_formater_p1.c \
		program_files/src/cmd/cmd_formater_p2.c \
		program_files/src/launcher/launcher_controller.c \
		program_files/src/launcher/launcher_errors_printer.c \
		program_files/src/builtins/builtin_env/env_env.c \
		program_files/src/builtins/builtin_env/env_set.c \
		program_files/src/builtins/builtin_env/env_unset.c \
		program_files/src/builtins/builtin_env/env_errors_printer.c \
		program_files/src/builtins/builtin_cd/builtin_cd.c \
		program_files/src/builtins/builtin_cd/cd_path.c \
		program_files/src/builtins/builtin_cd/cd_options.c \
		program_files/src/builtins/builtin_cd/cd_errors_printer.c \
		program_files/src/builtins/builtin_exit/builtin_exit.c \
		program_files/src/builtins/builtin_exit/exit_errors_printer.c \

OBJ = $(patsubst %.c, %.o, $(notdir $(SRC_C)))

SOFT_NAME = ft_minishell1

C_G = $(shell echo "\033[0;32m")

C_END = $(shell echo "\033[0m")

all: $(SOFT_NAME)

$(SOFT_NAME): $(SRC_C)
	make -C libft/
	@echo "\n$(C_G)	==========	SOFTWARE COMPILATION	==========$(C_END)"
	gcc -g -Wall -Wextra -Werror -I libft/includes/ -c $(SRC_C)
	@echo "\n$(C_G)	==========	CREATING EXECUTBLE FILE	==========$(C_END)"
	gcc -g -o $(SOFT_NAME) $(OBJ) -L libft/ -lft

clean:
	make -C libft/ clean
	@echo "\n$(C_G)	==========	DELETING OBJECTS FILES	==========$(C_END)"
	rm -rf $(OBJ)

fclean: clean
	make -C libft/ fclean
	@echo "\n$(C_G)	==========	DELETING SOFT FILE		==========$(C_END)"
	rm -rf $(SOFT_NAME)

re: fclean all
