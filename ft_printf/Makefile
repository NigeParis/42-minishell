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

NAME=libftprintf.a
CFLAGS=-Wall -Wextra -Werror
SRCS=$(addprefix $(SRC_DIR), $(SRC))
OBJ=$(SRC:.c=.o)
HEAD=$(addprefix $(INCLUDE), $(HEADER))
CCOPTIONS=-c
SRC_OBJ=$(addprefix $(OBJ_DIR), $(OBJ))
CC=clang
###############################################################################
## SOURCES 

SRC_DIR=./src/
OBJ_DIR=
INCLUDE=./src/
SRC=ft_printf.c ft_formatcheck.c ft_printf_unsigned_nbr.c
SRC+=ft_printf_nbr.c ft_printf_str.c ft_len_of_nbr.c
SRC+=ft_printf_hex.c ft_printf_ptr.c ft_printf_char.c 
SRC+=ft_printf_str_fd.c ft_formatchk_fd.c
SRC+=ft_printf_char_fd.c ft_printf_strlen.c ft_printf_fd.c 
HEADER=ft_printf.h
###############################################################################
## RULES

all: $(NAME)

$(NAME): $(OBJ)
	@echo -n $(GRAY) "Making ...  $(RESET) $(BOLD) libftprintf.a $(GRAY)      ...  " 
	@ar -rcs $(NAME) $(OBJ)  >/dev/null   && \
	($(ECHO) $(GREEN) "Success" $(RESET)   || \
	$(ECHO) $(RED) "Failed" $(RESET))


$(OBJ):
	@$(CC) $(CFLAGS) $(CCOPTIONS) $(SRCS) -I.$(HEAD)  >/dev/null
	
clean:
	@rm -f $(SRC_OBJ)  >/dev/null

fclean:clean
	@rm -f $(NAME)  >/dev/null

re:fclean all

.PHONY: all clean fclean re
