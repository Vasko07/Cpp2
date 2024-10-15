# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpinilla <gpinilla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/14 17:32:25 by gpinilla          #+#    #+#              #
#    Updated: 2024/10/15 18:02:12 by gpinilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Suprimir la salida de los comandos make
# MAKEFLAGS += --silent

################################################################################
### COLORS
################################################################################

DEL_LINE =		\033[2K
NC		=		\033[0m
ITALIC =		\033[3m
BOLD =			\033[1m
DEF_COLOR =		\033[0;39m
GRAY =			\033[0;90m
RED =			\033[0;91m
GREEN =			\033[0;92m
YELLOW =		\033[0;93m
BLUE =			\033[0;94m
MAGENTA =		\033[0;95m
CYAN =			\033[0;96m
WHITE =			\033[0;97m
BLACK =			\033[0;99m
ORANGE =		\033[38;5;209m
BROWN =			\033[38;2;184;143;29m
DARK_GRAY =		\033[38;5;234m
MID_GRAY =		\033[38;5;245m
DARK_GREEN =	\033[38;2;75;179;82m
DARK_YELLOW =	\033[38;5;143m

################################################################################
### COMMANDS
################################################################################

NAME            = Fixed
CC              = c++
FLAGS           = -g -Wall -Werror -Wextra -std=c++98
RM              = rm -rf

HEADERS			= Fixed.hpp
SRC             = Fixed.cpp  main.cpp
DIR_OBJ         = temp/
OBJ             = $(SRC:src/%.c=$(DIR_OBJ)%.o)

################################################################################
### RULES
################################################################################

all: $(DIR_OBJ) $(NAME)
	@echo "$(GREEN)$(NAME) is up to date ✓$(DEF_COLOR)\n"

$(DIR_OBJ):
	@mkdir -p $(DIR_OBJ)

$(DIR_OBJ)%.o: $(SRC) $(HEADERS) Makefile | $(DIR_OBJ)
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "${BLUE} ◎ $(BROWN)Compiling   ${MAGENTA}→   $(CYAN)$< $(DEF_COLOR)"

$(NAME): $(OBJ) $(HEADERS) $(DIR_OBJ)%.o Makefile
	@$(CC) $(FLAGS) $(OBJ)  -o $(NAME)
	@echo "$(GREEN)Created $(NAME) ✓$(DEF_COLOR)\n"

clean:
	@$(RM) $(DIR_OBJ)
	@echo "${RED}Objects and dependencies successfully removed${DEF_COLOR}"

fclean: clean
	@$(RM) $(NAME)
	@echo "${RED}Executables successfully removed${DEF_COLOR}"

re: fclean all

.PHONY: all clean fclean re