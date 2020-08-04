# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luwargni <luwargni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 00:22:39 by luwargni          #+#    #+#              #
#    Updated: 2019/06/08 14:28:23 by luwargni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=		gcc
NAME			=		libft.a
DIR_CURR		=		/libft
DIR_INCL		=		./includes
DIR_OBJS		=		./objs
DIR_SRCS		=		./srcs
FLAGS_COMP		=		-Wall -Wextra -Werror -g3
FLAGS_INCL		=		-I $(DIR_INCL)
FILES_HEADER	=		libft.h				\
						get_next_line.h
FILES_SRCS		=		ft_atoi.c			\
						ft_bzero.c			\
						ft_freetab.c		\
						ft_isdigit.c		\
						ft_memalloc.c		\
						ft_memset.c			\
						ft_putchar_fd.c		\
						ft_putchar.c		\
						ft_putendl_fd.c		\
						ft_putendl.c		\
						ft_putstr_fd.c		\
						ft_putstr.c			\
						ft_strchr.c			\
						ft_strdel.c			\
						ft_strdup.c			\
						ft_strjoin.c		\
						ft_strjoinfree.c	\
						ft_strlen.c			\
						ft_strndup.c		\
						ft_strnlen.c		\
						ft_strsplit.c		\
						ft_strsub.c			\
						ft_words_count.c	\
						get_next_line.c
HEADERS 		=		$(FILES_HEADER:%.h=$(DIR_INCL)/%.h)
OBJS			=		$(FILES_SRCS:%.c=$(DIR_OBJS)/%.o)
SRCS			=		$(FILES_SRCS:%.c=$(DIR_SRCS)/%.c)

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c
	@mkdir -p objs
	@$(CC) $(FLAGS_COMP) -c $< -o $@ $(FLAGS_INCL)
	@printf "."

$(NAME) : $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@echo
	@echo $(DIR_CURR) : \"$(NAME)\" made successfully

all : $(NAME)

clean :
	@rm -f $(OBJS)
	@echo $(DIR_CURR) : all object files deleted

fclean : clean
	@rm -f $(NAME)
	@echo $(DIR_CURR) : \"$(NAME)\" deleted

re : fclean all

norme :
	@norminette -R CheckForbiddenSourceHeader $(SRCS)
	@norminette -R CheckForbiddenSourceHeader $(HEADERS)

.PHONY: clean fclean re all norme
