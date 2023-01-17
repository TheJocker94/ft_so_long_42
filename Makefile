# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dasereno <dasereno@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/09 13:04:45 by tnard             #+#    #+#              #
#    Updated: 2022/05/21 16:58:29 by dasereno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLU			= \033[0;34m
GRN			= \033[0;32m
RED			= \033[0;31m
RST			= \033[0m
END			= \e[0m

SRCS 	=	src/so_long.c \
			src/render_map.c \
			src/init_map.c \
			src/move_set.c \
			src/utils.c \
			src/error.c \
			src/free_close.c \
			src/check_map.c \
			src/move_logic.c \
			src/key_input_logic.c
			
SRCS_B 	=	src_bonus/so_long_bonus.c \
			src_bonus/render_map_bonus.c \
			src_bonus/init_map_bonus.c \
			src_bonus/move_set_bonus.c \
			src_bonus/utils_bonus.c \
			src_bonus/error_bonus.c \
			src_bonus/free_close_bonus.c \
			src_bonus/check_map_bonus.c \
			src_bonus/animazioni_bonus.c \
			src_bonus/init_img_bonus.c \
			src_bonus/enemy_movement_bonus.c \
			src_bonus/move_logic_bonus.c \
			src_bonus/key_input_logic_bonus.c \
			src_bonus/renderless_bonus.c

NAME		= so_long
NAME_B		= so_long_bonus
OBJS_DIR	= objs/
OBJS_DIR_B	= objs_b/
OBJS		= $(SRCS:.c=.o)
OBJS_B		= $(SRCS_B:.c=.o)
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))
OBJECTS_PREFIXED_B = $(addprefix $(OBJS_DIR_B), $(OBJS_B))
CC			= gcc -g
CC_FLAGS	= -Wall -Werror -Wextra
MLB_FLAGS	= libft/libft.a mlx/libmlx.a -no-pie -lm -lX11 -lXext
$(OBJS_DIR)%.o : %.c src/so_long.h
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)src
	@$(CC) $(CC_FLAGS) -c $< -o $@
	@printf	"\033[2K\r${BLU}[BUILD - $(NAME)]${RST} '$<' $(END)"

$(OBJS_DIR_B)%.o : %.c src_bonus/so_long_bonus.h
	@mkdir -p $(OBJS_DIR_B)
	@mkdir -p $(OBJS_DIR_B)src_bonus
	@$(CC) $(CC_FLAGS) -c $< -o $@
	@printf	"\033[2K\r${BLU}[BUILD - $(NAME_B)]${RST} '$<' $(END)"

$(NAME): $(OBJECTS_PREFIXED) maker
	@$(CC) -o $(NAME) $(OBJECTS_PREFIXED) $(CC_FLAGS) $(MLB_FLAGS)
	@printf "\033[2K\r\033[0;32m[END]\033[0m $(NAME)$(END)\n"

$(NAME_B): $(OBJECTS_PREFIXED_B) maker
	@$(CC) -o $(NAME_B) $(OBJECTS_PREFIXED_B) $(CC_FLAGS) $(MLB_FLAGS)
	@printf "\033[2K\r\033[0;32m[END]\033[0m $(NAME_B)$(END)\n"

all: $(NAME)

bonus:	$(NAME_B)

maker:
	make -C mlx
	@make -C libft

clean:
	@rm -rf $(OBJS_DIR)
	@rm -rf $(OBJS_DIR_B)
	@make clean -C libft
	@echo "${GRN}[CLEAN]${RST} done"

fclean: clean
	@make clean -C mlx
	@make fclean -C libft
	@rm -f $(NAME)
	@rm -f $(NAME_B)
	@echo "${GRN}[FCLEAN]${RST} done"

re: fclean all

.PHONY:		all clean fclean re
