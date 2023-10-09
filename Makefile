# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/18 12:43:01 by pvong             #+#    #+#              #
#    Updated: 2023/10/09 11:12:54 by pvong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= cub3D
UNAME			= $(shell uname -s)

#COLORS 
NC= \033[0m
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m


#MLX
ifeq ($(UNAME), Darwin)
		OS = APPLE
		MLX_DIR = mlx
		MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework Appkit
		MLX_INC = -Imlx
else
		OS = LINUX
		MLX_DIR = mlx_linux/
		MLX_FLAGS = -Lmlx_linux -lmlx -lXext -lX11
		MLX_INC = -Imlx_linux
endif

#INCLUDE

INCLUDE			= -I ./include
INC_LIB			= -I ./libft/includes
INCLUDES		= $(INCLUDE) $(INC_LIB) $(MLX_INC)

#LIB

LIB_DIR			= libft
LIB_NAME		= libft/libft.a
MY_LDFLAGS		= -L $(LIB_DIR)
MY_LDLIBS		= -lft -lm

LDFLAGS			+= $(MY_LDFLAGS)
LDLIBS			+= $(MY_LDLIBS)

#COMPILATION FLAGS

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -g3 #-fsanitize=address

#SOURCES

SRC_DIR			= src

SRCS			:=	main/main.c \
					hooks/events.c \
					hooks/hooks.c \
					hooks/key_hook.c \
					init/init.c \
					parsing/map_parsing.c \
					parsing/map_parsing_utils.c \
					parsing/player_parsing.c \
					parsing/texture_parsing.c \
					raycasting/raycasting.c \
					raycasting/raycasting2.c \
					raycasting/texture.c \
					utils/utils.c \
					utils/utils_mlx.c \
					

SRCS			:=	$(SRCS:%=$(SRC_DIR)/%)

#OBJS
OBJ_DIR			:=	obj
OBJS			:= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

DIR_DUP			= @mkdir -p $(@D)

#COMPILATION

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

$(NAME):	$(OBJS)
	@make -s -C $(MLX_DIR)
	make -sC $(LIB_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME) $(LDFLAGS) $(LDLIBS) $(MLX_FLAGS)

clean:
	@make clean -sC $(LIB_DIR)
	@make clean -sC $(MLX_DIR)
	@rm -rf $(OBJ_DIR)
	@echo "$(BLUE)Object files cleaned!$(DEF_COLOR)"

fclean: clean
	@make fclean -C $(LIB_DIR)
	@rm -f $(NAME)
	@echo "$(CYAN)Executable files cleaned!$(DEF_COLOR)"

re: fclean all
	@echo "$(GREEN)Cleaned and rebuilt everything for $(NAME)!$(DEF_COLOR)"


.PHONY: all clean fclean re