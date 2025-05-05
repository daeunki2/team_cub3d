# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/05 12:39:27 by daeunki2          #+#    #+#              #
#    Updated: 2025/05/05 13:44:24 by daeunki2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = cc
SRC_DIR = src
OBJ_DIR = obj
MLX_DIR = mlx_linux
MINILIBX_LIB = $(MLX_DIR)/libmlx.a
CFLAGS = -Wall -Wextra -Werror -I$(MLX_DIR) -I includes
LDFLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lXfixes -lm

SRCS_LIST = main.c \
			game/init.c game/events.c game/render.c game/loop.c game/minimap.c game/clear.c game/utils.c\
			utils/ft_strlen.c utils/ft_strdup.c utils/ft_strcmp.c utils/ft_strncmp.c utils/ft_atoi.c utils/ft_split.c utils/ft_strchr.c utils/ft_substr.c\
			utils/gnl.c utils/ft_strjoin.c utils/ft_strnstr.c utils/ft_memset.c\
			parsing/color_parser.c parsing/down_parsing.c parsing/error.c parsing/file_read.c parsing/wall_check.c\
			parsing/init.c parsing/parsing.c parsing/up_parsing.c parsing/simple_tool.c \
			
			

SRCS = $(addprefix $(SRC_DIR)/, $(SRCS_LIST))

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I/usr/include -I$(MLX_DIR) -O3 -c $< -o $@ > /dev/null 2>&1

$(NAME): $(OBJS)
	@echo "Building $(NAME) 🛠️"
	@make -C $(MLX_DIR) > /dev/null 2>&1
	@rm -f $(HOME)/.valgrind.supp && \
		printf '{\n   X11 writev false positive\n   Memcheck:Param\n   writev(vector[0])\n   fun:writev\n   obj:/usr/lib/x86_64-linux-gnu/libxcb.so.*\n}' > $(HOME)/.valgrind.supp
	@grep -q 'VALGRIND_OPTS' $(HOME)/.bashrc || echo 'export VALGRIND_OPTS="--suppressions=$$HOME/.valgrind.supp"' >> $(HOME)/.bashrc
	@$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) > /dev/null 2>&1
	@echo "Build Complete! ✅"  

clean:
	@echo "Cleaning up 🧹🧹🧹"
	@make -C $(MLX_DIR) clean > /dev/null 2>&1  # mlx clean output suppressed
	@rm -rf $(OBJ_DIR)
	@echo "cleaning ✅"

fclean: clean
	@echo "Cleaning Executables 🧹🧹🧹"
	@rm -f $(NAME)
	@echo "fclean ✅"

re: fclean all

norm:
	@echo "Checking norminette for source files..."
	@norminette $(addprefix $(SRC_DIR)/, $(SRCS_LIST)) includes/*.h || { echo "Norminette failed :( "; exit 1; }
	@echo "no norm error!"


.PHONY: all clean fclean re