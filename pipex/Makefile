###############################################################################
## Colors - merci Baptiste

GRAY		= "\\e[90m"
GREEN		= "\\e[42m"
RED			= "\\e[41m"
RESET		= "\\e[0m"
BOLD		= "\\e[1m"

ECHO		=	$(shell which echo) -e

###############################################################################
## ARGUMENTS

NAME= pipex

CFLAGS= -Wall -Wextra -Werror -I$(HEADERS) -g3

SRCS=$(addprefix $(SRC_DIR), $(SRC))
OBJ=$(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

CC=clang

PND=--no-print-directory

###############################################################################
## SOURCES 

SRC= ./src/main.c ./src/pipex.c ./src/get_path.c 
SRC+=./src/clean_and_errors.c ./src/get_cmds.c
SRC+=./src/make_pipe.c ./src/get_heredoc.c
SRC+=./src/ft_toggle_char.c 

LIBFT_DIR=../libft
FT_PRINTF_DIR= ../ft_printf
GNL_DIR=../get_next_line

A_FILES=  ../libft/libft_personal.a
A_FILES+= ../ft_printf/libftprintf.a
A_FILES+= ../get_next_line/get_next_line.a

HEADERS=  ../include 
HEADERS+= -I../libft/include -I../ft_printf/src -I../get_next_line



###############################################################################
## RULES

all: $(NAME)

$(NAME): $(OBJ)
	@make $(PND) -C $(LIBFT_DIR) all
	@make $(PND) -C $(FT_PRINTF_DIR) all
	@make $(PND) -C $(GNL_DIR) all
	@echo -n $(GRAY) "Making ...  $(RESET) $(BOLD) pipex $(GRAY)              ...  " 
	@($(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(A_FILES) && \
	($(ECHO) $(GREEN) "Success" $(RESET)) )   || \
	$(ECHO) $(RED) "Failed" $(RESET)

lib:
	@make $(PND) -C $(LIBFT_DIR) re
	@make $(PND) -C $(FT_PRINTF_DIR) re
	@make $(PND) -C $(GNL_DIR) re

libclean:
	@make $(PND) -C $(LIBFT_DIR) clean
	@make $(PND) -C $(FT_PRINTF_DIR) clean
	@make $(PND) -C  $(GNL_DIR) clean

libfclean:
	@make $(PND) -C $(LIBFT_DIR) fclean
	@make $(PND) -C $(FT_PRINTF_DIR) fclean
	@make $(PND) -C $(GNL_DIR) fclean

clean: libclean
	@rm -f $(OBJ)
	@rm -f $(OBJ)

fclean:clean libfclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all bonus lib libclean clean fclean re
