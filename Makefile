# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: megrelli <melchior.grellier42@gmail.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/20 17:15:16 by megrelli          #+#    #+#              #
#    Updated: 2026/04/30 02:50:40 by megrelli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CFLAGS = -Wall -Werror -Wextra -g3
Libft = ./libft/libft.a
OBJ_DIR = objs

# --- COLORS ---
GREEN	= \033[0;32m
CYAN	= \033[1;36m
RED		= \033[0;31m
BLUE	= \033[0;94m
RESET	= \033[0m

# --- SRCS ---
SRCS =	srcs/core/main.c srcs/core/parsing.c srcs/core/clean.c \
srcs/core/stack_utils.c srcs/core/turk_sort.c srcs/core/turk_utils.c \
srcs/core/sort_three.c srcs/operations/push.c srcs/operations/swap.c \
srcs/operations/rotate.c srcs/operations/rev_rotate.c \

# --- OBJS ---
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

# --- RULES ---
all: $(NAME)

$(Libft):
	@printf "$(CYAN)┌── $(BLUE)Compiling Libft...$(RESET)\n"
	@make -C ./libft > /dev/null
	@printf "$(CYAN)└── $(BLUE)Libft OK$(RESET)\n"

$(NAME): $(OBJS) $(Libft)
	@printf "\n$(GREEN)Building $(NAME)...$(RESET)\n"
	@cc $(CFLAGS) $(OBJS) $(Libft) -o $(NAME)
	@printf "$(GREEN)Done! $(NAME) is ready $(RESET)\n"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@printf "$(CYAN)│ $(BLUE) Compiling $<...$(RESET)\n"
	@cc $(CFLAGS) -c $< -o $@

clean:
	@printf "\n$(GREEN)Cleaning objects...$(RESET)\n"
	@rm -rf $(OBJ_DIR)
	@make -C ./libft clean > /dev/null

fclean: clean
	@printf "$(RED)Cleaning executables...$(RESET)\n"
	@rm -f $(NAME)
	@make -C ./libft fclean > /dev/null

re: fclean all

.PHONY: all clean fclean re