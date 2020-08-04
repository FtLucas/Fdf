# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luwargni <luwargni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/25 19:31:02 by luwargni          #+#    #+#              #
#    Updated: 2019/06/15 19:05:02 by luwargni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=		gcc
NAME			=		fdf
DIR_CURR		=		/fdf
DIR_INCL		=		./includes
DIR_MLX			=		~/projet/librairies/minilibx
DIR_LIBFT		=		./libft
DIR_OBJS		=		./objs
DIR_SRCS		=		./srcs
FLAGS_COMP		=		-Wall -Wextra -Werror
FLAGS_INCL		=		-I $(DIR_INCL)
FLAGS_LIBFT		=		-L $(DIR_LIBFT) -lft
FLAGS_MLX		=		-L $(DIR_MLX) -lmlx -framework OpenGL -framework AppKit
FILES_HEADER	=		fdf.h
FILES_SRCS		=		check_file.c		\
						draw_map.c			\
						events.c			\
						free_list.c			\
						init_mlx.c			\
						ligne.c				\
						main.c				\
						manage_point.c		\
						set_hud.c			\
						set_map.c
HEADERS			=		$(FILES_HEADER:%.h=$(DIR_INCL)/%.h)
OBJS			=		$(FILES_SRCS:%.c=$(DIR_OBJS)/%.o)
SRCS			=		$(FILES_SRCS:%.c=$(DIR_SRCS)/%.c)

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c
	@mkdir -p objs
	@$(CC) $(FLAGS_COMP) -c $< -o $@ $(FLAGS_INCL)
	@printf "."

all : libft
	@$(MAKE) $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(FLAGS_COMP) -o $(NAME) $(OBJS) $(FLAGS_LIBFT) $(FLAGS_MLX)
	@echo
	@echo $(DIR_CURR) : \"$(NAME)\" made successfully

libft :
	@$(MAKE) -C $(DIR_LIBFT)

clean :
	@$(MAKE) -C $(DIR_LIBFT)/ clean
	@rm -f $(OBJS)
	@echo $(DIR_CURR) : all object files deleted

fclean :
	@$(MAKE) -C $(DIR_LIBFT)/ fclean
	@rm -f $(OBJS)
	@echo $(DIR_CURR) : all object files deleted
	@rm -f $(NAME)
	@echo $(DIR_CURR) : \"$(NAME)\" deleted

re : fclean all

norme :
	@$(MAKE) -C $(DIR_LIBFT)/ norme
	@norminette -R CheckForbiddenSourceHeader $(SRCS)
	@norminette -R CheckForbiddenSourceHeader $(HEADERS)

.PHONY: clean fclean re all norme libft
