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

NAME=get_next_line.a
EXEC=outbonus
CFLAGS=-Wall -Wextra -Werror -I.$(HEAD)
SRCS=$(addprefix $(SRC_DIR), $(SRC))
OBJ=$(SRC:.c=.o)
HEAD=$(addprefix $(INCLUDE), $(HEADER))
CCOPTIONS=-c -g3 -D BUFFER_SIZE=42
SRC_OBJ=$(addprefix $(OBJ_DIR), $(OBJ))

CC=clang
############################################:###################################
## SOURCES 

SRC_DIR=
OBJ_DIR=
INCLUDE=
SRC=get_next_line.c get_next_line_utils.c

HEADER=get_next_line.h
###############################################################################
## RULES

all: $(NAME)

$(NAME): $(OBJ)
	@echo -n $(GRAY) "Making ...  $(RESET) $(BOLD) get_next_line.a $(GRAY)    ...  " 
	@ar -rcs $(NAME) $(OBJ)  >/dev/null   && \
	($(ECHO) $(GREEN) "Success" $(RESET)  || \
	$(ECHO) $(RED) "Failed" $(RESET))


$(OBJ):
	@$(CC) $(CFLAGS) $(CCOPTIONS) $(SRCS) >/dev/null

clean:
	@rm -f $(SRC_OBJ) $(MAIN_OBJ)  >/dev/null

fclean:clean
	@rm -f $(NAME) $(EXEC)  >/dev/null

re:fclean all

.PHONY: all clean fclean re
