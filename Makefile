# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgarfi <lgarfi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 14:44:52 by lgarfi            #+#    #+#              #
#    Updated: 2023/12/17 18:22:58 by lgarfi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables

NAME		= push_swap
INCLUDE		= include
INCLUDE_B	= bonus/include
SRC_DIR		= src/
SRC_B_DIR	= bonus/
OBJ_DIR		= src/obj/
OBJ_B_DIR	= bonus/obj_b/
CC			= cc
CFLAGS		= -Wall -Werror -Wextra

# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

#Sources

SRC_FILES   = $(shell find $(SRC_DIR) -type f -name "*.c")
SRC_B_FILES = $(shell find $(SRC_B_DIR) -type f -name "*.c")

SRC         = $(addprefix $(SRC_DIR), $(notdir $(SRC_FILES)))
OBJ         = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))

SRC_B       = $(addprefix $(SRC_B_DIR), $(notdir $(SRC_B_FILES))) \
			src/create_list_a.c \
			src/parsing_str.c \
			src/parsing_av.c \
			src/tools.c \
			src/tools2.c \
			src/tools3.c \
			src/tools_list.c \
			src/split.c \

OBJ_B       = $(patsubst $(SRC_B_DIR)%.c, $(OBJ_B_DIR)%.o, $(SRC_B))

###

OBJF		=	$(OBJ_DIR).cache_exists

OBJF_B		=	$(OBJF_B_DIR).cache_exists


all:		$(NAME)

$(NAME):	$(OBJ)
			@$(CC) -g3 $(CFLAGS) $(SRC) -o $(NAME)
			@echo "$(GREEN)push_swap compiled!$(DEF_COLOR)"


$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
			@$(CC) -g3 $(CFLAGS) -I $(INCLUDE) -c $< -o $@

$(OBJ_B_DIR)%.o: $(SRC_B_DIR)%.c | $(OBJF_B)
			@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
			@$(CC) -g3 $(CFLAGS) -I $(INCLUDE_B) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)

$(OBJF_B):
			@mkdir -p $(OBJ_B_DIR)

bonus:		$(OBJF_B) | $(OBJ_B)
			@$(CC) -g3 $(CFLAGS) $(SRC_B) -o "checker"
			@echo "$(GREEN)push_swap bonus compiled!$(DEF_COLOR)"

clean:
			@$(RM) -rf $(OBJ_DIR) $(OBJ_B_DIR)
			@echo "$(BLUE)push_swap object files cleaned!$(DEF_COLOR)"

fclean:		clean
			@$(RM) -f $(NAME) checker 
			@echo "$(CYAN)push_swap executable files cleaned!$(DEF_COLOR)"

re:			fclean all
			@echo "$(GREEN)Cleaned and rebuilt everything for push_swap!$(DEF_COLOR)"

norm:
			@norminette $(SRC) $(INCLUDE) $(LIBFT) | grep -v Norme -B1 || true

.PHONY:		all clean fclean re norm bonus
