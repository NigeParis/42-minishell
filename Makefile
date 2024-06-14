# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 09:04:05 by bgoulard          #+#    #+#              #
#    Updated: 2024/06/14 09:45:42 by bgoulard         ###   ########.fr        #
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

DEBUG_LEVEL	=\
			 	0
DEBUG		=\
				-DDEBUG_LVL=$(DEBUG_LEVEL) -g2 -O3
STD			=\
				--std=c99
CPPFLAGS	=\
				-I$(INC_DIR) -I./libft/include
WFLAGS		=\
				-Wall -Wextra -Wno-unused-parameter				\
				-Werror											\
				-Wno-unused-variable -Wno-unused-function		\
				-Wno-unused-value								\
				-Wno-unused-label -Wno-unused-local-typedefs	\
				-Wno-unused-const-variable -Wno-unused-macros

FFLAGS	   =\
				-fsanitize=address			\
				-fno-omit-frame-pointer		\
				-fsanitize=undefined		\
				-fsanitize=leak				\
				-fsanitize=pointer-subtract	\
				-fsanitize=pointer-compare	\
				-fsanitize=pointer-overflow	\

CFLAGS	   =\
				$(WFLAGS) $(CPPFLAGS) $(STD)	\
				-MMD -MP $(DEBUG) 

LDFLAGS		=\
				-L./libft -lft_personal -lreadline
SRC_FILES	=\
				$(shell find $(SRC_DIR) -type f -name "*.c" | sed 's/\.\/src\///')

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
	@$(ECHO) $(RED) "WILDCARD IN PROJECT" $(RESET)
	@$(ECHO) $(RED) "DEBUG FLAGS IN PROJECT" $(RESET)

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
	@( $(RM) -rf $(BUILD_DIR) $(CLOG_FILE) 2> /dev/null && \
	make --no-print-directory -C ./libft clean	2> /dev/null &&		\
	$(ECHO) $(GREEN) "Success" $(RESET) ) || \
	$(ECHO) $(RED) "Failed" $(RESET)

fclean: clean
	@$(ECHO) -n $(GRAY) "FClean ... " $(RESET)
	@( $(RM) $(NAME) 2> /dev/null && \
	make --no-print-directory -C ./libft fclean 2> /dev/null &&	\
	$(ECHO) $(GREEN) "Success" $(RESET) ) || \
	$(ECHO) $(RED) "Failed" $(RESET)

-include $(OBJ:.o=.d)

re:	fclean all

.PHONY: re fclean clean
