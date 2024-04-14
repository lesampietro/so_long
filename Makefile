NAME= so_long
# NAME_BONUS= so_long_bonus
C_FLAGS:= -Wextra -Wall -Werror
0MLX_FLAGS= -Wunreachable-code
MLX_FLAGS= -ldl -lglfw -pthread -lm
LIBMLX= ./lib/MLX42
LIBFT= ./lib/libft

CC= cc
# HEADERS= -I ./include -I $(LIBMLX)/include
HEADERS= ./includes/so_long.h
LIBS= $(LIBMLX)/build/libmlx42.a $(LIBFT)/libft.a
# SRC= $(shell find ./src -iname ".c")
SRC= ./src/so_long.c \
		./src/read_map.c \
		./src/validate_map.c \
		./src/validate_entry.c \
		./src/validate_chars.c \
		./src/floodfill.c \
		./src/utils.c \

# BONUS= $(shell find ./bonus -iname ".c")
INCLUDES= -I includes -I $(LIBMLX)/include -I $(LIBFT)/ -I $(LIBFT)/ft_printf/includes -I $(LIBFT)/gnl/includes
OBJS= $(SRC:%.c=%.o)
# BONUS_OBJS= $(BONUS:%.c=%.o)

all: $(NAME)
	@echo "All done!🥳"

libmlx:
	@echo "Compiling graphic libraries..."
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4 --no-print-directory

libft:
	@echo "Compiling LIBFT..."
	@make all bonus new -C $(LIBFT) $(C_FLAGS) --no-print-directory

%.o: %.c $(HEADERS)
	@$(CC) $(C_FLAGS) $(0MLX_FLAGS) -o $@ -c $< && echo "Compiling: $(notdir $<)"

$(NAME): libmlx libft  $(OBJS)
	@echo "Creating $(NAME)"
	@$(CC) $(OBJS) $(LIBS) $(INCLUDES) -o $(NAME) $(MLX_FLAGS)

# $(NAME_BONUS): $(OBJS_BONUS)
#	@echo "Creating $(NAME)"
#	@$(CC) $(OBJS_BONUS) $(LIBS) $(INCLUDES) -o $(NAME_BONUS) $(MLX_FLAGS)

clean:
	@echo "Cleaning objects..."
	@rm -rf $(OBJS)
	@make clean -C $(LIBFT) --no-print-directory
	@echo "Cleaning build..."
	@rm -rf $(LIBMLX)/build
	@echo "All done!✨"

fclean: clean
	@echo "Cleaning libft.a..."
	@make clean -C $(LIBFT) --no-print-directory
# Por que precisa repetir a linha acima (já está no clean)?
	@echo "Cleaning executables..."
	@rm -rf $(NAME)
	@echo "All done!✨"

re: fclean all

.PHONY: all, clean, fclean, re, libmlx

.SILENT: