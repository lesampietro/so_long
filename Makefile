# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/04 21:48:42 by lsampiet          #+#    #+#              #
#    Updated: 2024/05/04 21:49:41 by lsampiet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= so_long
# NAME_BONUS= so_long_bonus
C_FLAGS:= -Wextra -Wall -Werror
0MLX_FLAGS= -Wunreachable-code
MLX_FLAGS= -ldl -lglfw -pthread -lm
LIBMLX= ./lib/MLX42
LIBFT= ./lib/libft
BIN= ./bin/
SRC_D= ./src/

CC= cc
# HEADERS= -I ./include -I $(LIBMLX)/include
HEADERS= ./includes/so_long.h
LIBS= $(LIBMLX)/build/libmlx42.a $(LIBFT)/libft.a
SRC= so_long.c \
		read_map.c \
		validate_map.c \
		validate_chars.c \
		floodfill.c \
		utils.c \
		init_game.c \
		init_assets.c \
		init_map.c \
		validate_moves.c \
		clean.c \

# BONUS= $(shell find ./bonus -iname ".c")
SRC:= $(addprefix $(SRC_D),$(SRC))
INCLUDES= -I includes -I $(LIBMLX)/include -I $(LIBFT)/ -I $(LIBFT)/ft_printf/includes -I $(LIBFT)/gnl/includes
OBJS= $(patsubst $(SRC_D)%.c, $(BIN)%.o, $(SRC))
# BONUS_OBJS= $(BONUS:%.c=%.o)

all: $(NAME)
	@echo "All done!🥳"

libmlx:
	@echo "Compiling graphic libraries..."
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4 --no-print-directory

libft:
	@echo "Compiling LIBFT..."
	@make all bonus new -C $(LIBFT) $(C_FLAGS) --no-print-directory

$(BIN)%.o: $(SRC_D)%.c $(HEADERS)
	@mkdir -p $(BIN)
	@$(CC) $(C_FLAGS) $(0MLX_FLAGS) -o $@ -c $< && echo "Compiling: $(notdir $<)"

$(NAME): libmlx libft  $(OBJS)
	@echo "Creating $(NAME)"
	@$(CC) $(OBJS) $(LIBS) $(INCLUDES) -o $(NAME) $(MLX_FLAGS)

# $(NAME_BONUS): $(OBJS_BONUS)
#	@echo "Creating $(NAME)"
#	@$(CC) $(OBJS_BONUS) $(LIBS) $(INCLUDES) -o $(NAME_BONUS) $(MLX_FLAGS)

clean:
	@echo "Cleaning objects..."
	@rm -rf $(BIN)
	@make clean -C $(LIBFT) --no-print-directory
	@echo "Cleaning build..."
	@rm -rf $(LIBMLX)/build
	@echo "All done!✨"

fclean: clean
	@echo "Cleaning libft.a..."
	@make clean -C $(LIBFT) --no-print-directory
	@echo "Cleaning executables..."
	@rm -rf $(NAME)
	@echo "All done!✨"

re: fclean all

.PHONY: all, clean, fclean, re, libmlx

.SILENT: