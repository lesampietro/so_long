# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/04 21:48:42 by lsampiet          #+#    #+#              #
#    Updated: 2024/05/07 00:08:41 by lsampiet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= so_long
NAME_BONUS= so_long_bonus
C_FLAGS:= -Wextra -Wall -Werror
0MLX_FLAGS= -Wunreachable-code
MLX_FLAGS= -ldl -lglfw -pthread -lm
LIBMLX= ./lib/MLX42
LIBFT= ./lib/libft
BIN= ./bin/
BIN_BONUS= ./bin_bonus/
SRC_D= ./src/
SRC_B= ./src_bonus/

CC= cc
HEADER_M= ./includes/so_long.h
HEADER_B= ./includes/so_long_bonus.h \

LIBS= $(LIBMLX)/build/libmlx42.a $(LIBFT)/libft.a
SRC= main.c \
		clean.c \
		floodfill.c \
		init_assets.c \
		init_game.c \
		init_map.c \
		read_map.c \
		utils.c \
		validate_chars.c \
		validate_map.c \
		validate_moves.c \

BONUS= main_bonus.c \
		clean_bonus.c \
		floodfill_bonus.c \
		init_assets_bonus.c \
		init_game_bonus.c \
		init_map_bonus.c \
		read_map_bonus.c \
		utils_bonus.c \
		validate_chars_bonus.c \
		validate_map_bonus.c \
		validate_moves_bonus.c \
		animate.c \

CHECK_M= $(shell ar -t $(NAME) $(C_OBJS) 2>/dev/null)
CHECK_B= $(shell ar -t $(NAME) $(BONUS_OBJS) 2>/dev/null)

SRC:= $(addprefix $(SRC_D),$(SRC))
BONUS:= $(addprefix $(SRC_B),$(BONUS))

INCLUDES= -I includes -I $(LIBMLX)/include -I $(LIBFT)/ -I $(LIBFT)/ft_printf/includes -I $(LIBFT)/gnl/includes
C_OBJS= $(patsubst $(SRC_D)%.c, $(BIN)%.o, $(SRC))
BONUS_OBJS= $(patsubst $(SRC_B)%.c, $(BIN_BONUS)%.o, $(BONUS))

all: $(NAME)
	@echo "All done for mandatory part!🥳"

bonus: $(NAME_BONUS)
	@echo "All done for bonus part!🥳"

libmlx:
	@echo "Compiling graphic libraries..."
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4 --no-print-directory

libft:
	@echo "Compiling LIBFT..."
	@make all bonus new -C $(LIBFT) $(C_FLAGS) --no-print-directory

$(BIN)%.o: $(SRC_D)%.c $(HEADER_M)
	@mkdir -p $(BIN)
	@$(CC) $(C_FLAGS) $(0MLX_FLAGS) -o $@ -c $< && echo "Compiling: $(notdir $<)"

$(BIN_BONUS)%.o: $(SRC_B)%.c $(HEADER_B)
	@mkdir -p $(BIN_BONUS)
	@$(CC) $(C_FLAGS) $(0MLX_FLAGS) -o $@ -c $< && echo "Compiling: $(notdir $<)"

$(NAME): libmlx libft $(if $(CHECK_B), fclean $(C_OBJS), $(C_OBJS))
	@echo "Creating $(NAME)"
	@$(CC) $(C_OBJS) $(LIBS) $(INCLUDES) -o $(NAME) $(MLX_FLAGS)

$(NAME_BONUS): libmlx libft $(if $(CHECK_M), fclean $(BONUS_OBJS), $(BONUS_OBJS))
	@echo "Creating $(NAME_BONUS)"
	@$(CC) $(BONUS_OBJS) $(LIBS) $(INCLUDES) -o $(NAME_BONUS) $(MLX_FLAGS)

clean:
	@echo "Cleaning objects..."
	@rm -rf $(BIN) $(BIN_BONUS)
	@make clean -C $(LIBFT) --no-print-directory
	@echo "Cleaning build..."
	@rm -rf $(LIBMLX)/build
	@echo "All done!✨"

fclean: clean
	@echo "Cleaning libft.a..."
	@make clean -C $(LIBFT) --no-print-directory
	@echo "Cleaning executables..."
	@rm -rf $(NAME) $(NAME_BONUS)
	@echo "All done!✨"

re: fclean all

.PHONY: all, clean, fclean, re, libmlx

.SILENT: