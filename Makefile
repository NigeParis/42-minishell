# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 09:04:05 by bgoulard          #+#    #+#              #
#    Updated: 2024/08/18 10:57:52 by bgoulard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


GRAY		= "\\e[90m"
GREEN		= "\\e[42m"
RED			= "\\e[41m"
RESET		= "\\e[0m"
BOLD		= "\\e[1m"

PRINTF		=	$(shell which printf)
CC			=	$(shell which clang)
ECHO		=	$(shell which echo) -e
RM			=	$(shell which rm) -rf

CLOG_FILE	=	./compilation.log
NAME		=	./minishell
SRC_DIR		=	src
BUILD_DIR	=	build
INC_DIR		=	include

CPPFLAGS	=\
				-I$(INC_DIR) -I./libft/include
WFLAGS		=\
				-Wall -Wextra -Wno-unused-parameter				\
				-Werror											\
				-Wno-unused-variable -Wno-unused-function		\
				-Wno-unused-value								\
				-Wno-unused-label -Wno-unused-local-typedefs	\
				-Wno-unused-const-variable -Wno-unused-macros	\

FFLAGS	   =\
				-fsanitize=address			\
				-fno-omit-frame-pointer		\
				-fsanitize=undefined		\
				-fsanitize=leak				\
				-fsanitize=pointer-subtract	\
				-fsanitize=pointer-compare	\
				-fsanitize=pointer-overflow	

CFLAGS	   =\
				$(WFLAGS) $(CPPFLAGS) $(STD)	\
				-MMD -MP	

LDFLAGS		=\
				-L./libft -lft_personal -lreadline
SRC_FILES	=\
			./src/builtins/echo.c	\
			./src/builtins/env.c	\
			./src/builtins/bultin_buff_utils.c	\
			./src/builtins/call_bin.c	\
			./src/builtins/cd.c	\
			./src/builtins/exit.c	\
			./src/builtins/pwd.c	\
			./src/builtins/unset.c	\
			./src/builtins/export.c	\
			./src/builtins/builtins_utils.c	\
			./src/env/set_env.c	\
			./src/env/unset_env.c	\
			./src/env/get_env.c	\
			./src/core/minishell_pipe_utils.c	\
			./src/core/minishell_signals.c	\
			./src/core/minishell_rdr_utils.c	\
			./src/core/minishell_dollarsign.c	\
			./src/core/minishell_execute.c	\
			./src/core/minishell_exec_p.c	\
			./src/core/minishell_dispatcher.c	\
			./src/core/minishell_parser_init.c	\
			./src/core/minishell_main.c	\
			./src/core/minishell_cleanup.c	\
			./src/core/minishell_loop.c	\
			./src/core/minishell_rdr.c	\
			./src/core/minishell_hdoc.c	\
			./src/core/minishell_expansions.c	\
			./src/core/minishell_discard_cmd.c	\
			./src/core/minishell_exec_c.c	\
			./src/core/minishell_prompt.c	\
			./src/core/minishell_setup.c	\
			./src/pair/access_pair.c	\
			./src/pair/cmp_pair.c	\
			./src/pair/fcmp_pair.c	\
			./src/pair/new_pair.c	\
			./src/pair/destroy_pair.c	\
			./src/parser/parser_syntax.c	\
			./src/parser/preparsed_node_factory.c	\
			./src/parser/parser_line_init.c	\
			./src/parser/parser_pl_update.c	\
			./src/parser/parser_node_utils.c	\
			./src/parser/parser_glob_cleanup.c	\
			./src/parser/parser_glob_init.c	\
			./src/parser/parser_line_cleanup.c	\
			./src/parser/parser_file_cr.c	\
			./src/parser/parser_tok_to_cmd.c	\
			./src/parser/tok_func/tok_eol/print.c	\
			./src/parser/tok_func/tok_eol/create.c	\
			./src/parser/tok_func/tok_eol/isok.c	\
			./src/parser/tok_func/tok_eol/append.c	\
			./src/parser/tok_func/tok_eol/update_lb.c	\
			./src/parser/tok_func/tok_eol/destroy.c	\
			./src/parser/tok_func/tok_eol/nd2ex.c	\
			./src/parser/tok_func/tok_space/append.c	\
			./src/parser/tok_func/tok_space/create.c	\
			./src/parser/tok_func/tok_space/update_lb.c	\
			./src/parser/tok_func/tok_space/destroy.c	\
			./src/parser/tok_func/tok_space/isok.c	\
			./src/parser/tok_func/tok_space/nd2ex.c	\
			./src/parser/tok_func/tok_space/print.c	\
			./src/parser/tok_func/tok_word/nd2ex_wd.c	\
			./src/parser/tok_func/tok_word/create.c	\
			./src/parser/tok_func/tok_word/isok.c	\
			./src/parser/tok_func/tok_word/print.c	\
			./src/parser/tok_func/tok_word/update_lb.c	\
			./src/parser/tok_func/tok_word/destroy.c	\
			./src/parser/tok_func/tok_word/append.c	\
			./src/parser/tok_func/tok_quote/nd2ex.c	\
			./src/parser/tok_func/tok_quote/destroy.c	\
			./src/parser/tok_func/tok_quote/isok.c	\
			./src/parser/tok_func/tok_quote/update_lb.c	\
			./src/parser/tok_func/tok_quote/print.c	\
			./src/parser/tok_func/tok_quote/append.c	\
			./src/parser/tok_func/tok_quote/create.c	\
			./src/parser/tok_func/tok_pipe/create.c	\
			./src/parser/tok_func/tok_pipe/isok.c	\
			./src/parser/tok_func/tok_pipe/update_lb.c	\
			./src/parser/tok_func/tok_pipe/destroy.c	\
			./src/parser/tok_func/tok_pipe/append.c	\
			./src/parser/tok_func/tok_pipe/print.c	\
			./src/parser/tok_func/tok_pipe/nd2ex.c	\
			./src/parser/tok_func/tok_redir/create.c	\
			./src/parser/tok_func/tok_redir/append.c	\
			./src/parser/tok_func/tok_redir/destroy.c	\
			./src/parser/tok_func/tok_redir/isok.c	\
			./src/parser/tok_func/tok_redir/print.c	\
			./src/parser/tok_func/tok_redir/nd2ex.c	\
			./src/parser/tok_func/tok_redir/update_lb.c	\
			./src/parser/parser_get_next_token.c	\
			./src/ft_addons/ft_optional_init.c	\
			./src/ft_addons/ft_strsignals.c	\
			./src/ft_addons/ft_strerror.c	\
			./src/ft_addons/ft_perror.c	\
			./src/ft_addons/ft_vec_end.c	\
			./src/ft_addons/ft_string_to_str_inplace.c	\
			./src/ft_addons/ft_vec_collect.c	\
			./src/ft_addons/optinal_join.c	\
			./src/ft_addons/ft_atol.c	\
			./src/main.c

OBJ			=\
			 	$(patsubst %.c, %.o, $(addprefix $(BUILD_DIR)/,$(SRC_FILES)))

# get the max length of the file name for pretty print
MAX_FLEN	=\
			 $(shell $(PRINTF) "%s\n" $(OBJ) | \
			 awk '{print length}' | sort -n | tail -1)

$(BUILD_DIR)/%.o: %.c
	@$(ECHO) -n	$(GRAY)	"building from " 
	@$(PRINTF) "%*s ..."$(RESET) $(MAX_FLEN) $<
	@mkdir -p $(dir $@)
	@( $(CC) $(CFLAGS) -c $< -o $@ 2>> $(CLOG_FILE) && \
	$(ECHO) $(GREEN) "Success" $(RESET) ) || \
	$(ECHO) $(RED) "Failed" $(RESET) "see:" $(CLOG_FILE)

all:	$(NAME)

libft/libft_personal.a:
	@make --no-print-directory -C ./libft

$(NAME):	$(OBJ) libft/libft_personal.a
	@$(ECHO) -n $(GRAY) "Making ... " $(RESET) $(BOLD) "$(NAME)" \
	$(RESET)	$(GRAY) " ... " $(RESET)
	@( $(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(LDFLAGS) 2>> $(CLOG_FILE) && \
	$(ECHO) $(GREEN) "Success" $(RESET) && $(RM) $(CLOG_FILE)) || \
	$(ECHO) $(RED) "Failed" $(RESET) "see:" $(CLOG_FILE)

clean:
	@$(ECHO) -n $(GRAY) "Clean ... " $(RESET)
	@( $(RM) -rf $(BUILD_DIR) $(CLOG_FILE) supress_readline.valgrind \
	2> /dev/null && \
	make --no-print-directory -C ./libft clean	2> /dev/null &&		\
	$(ECHO) $(GREEN) "Success" $(RESET) ) || \
	$(ECHO) $(RED) "Failed" $(RESET)

fclean: clean
	@$(ECHO) -n $(GRAY) "FClean ... " $(RESET)
	@( $(RM) $(NAME) 2> /dev/null && \
	make --no-print-directory -C ./libft fclean 2> /dev/null &&	\
	$(ECHO) $(GREEN) "Success" $(RESET) ) || \
	$(ECHO) $(RED) "Failed" $(RESET)

supression_file_readline:
	@$(ECHO) -n $(GRAY) "Supression file readline ... " $(RESET)
	@( $(ECHO) -en \
	"{\n"\
	"\tignore_libreadline_leaks\n"\
	"\tMemcheck:Leak\n"\
	"\t...\n"\
	"\tobj:*/libreadline.so.*\n"\
	"}\n" > supress_readline.valgrind && \
	$(ECHO) $(GREEN) "Success" $(RESET) ) || \
	$(ECHO) $(RED) "Failed" $(RESET)

tests_run:
	make --no-print-directory -C ./libft tests_run

-include $(OBJ:.o=.d)

re:	fclean all

.PHONY: re fclean clean
