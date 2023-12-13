# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchaaibi <mchaaibi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 15:37:36 by mchaaibi          #+#    #+#              #
#    Updated: 2023/12/12 18:51:27 by mchaaibi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

SRCS			= 	push_swap.c \
					functions/check_arg.c \
					functions/stacks.c \
					functions/linknode.c \
					functions/sort.c \
					actions/action_push.c \
					actions/action_revrotate.c \
					actions/action_rotate.c \
					actions/action_swap.c \
					sort_easy.c func_sort_easy.c \
					rdx_sort.c
					
SRCS_B			= 	checker.c \
					functions/check_arg.c \
					functions/stacks.c \
					functions/linknode.c \
					functions/sort.c \
					actions/action_push.c \
					actions/action_revrotate.c \
					actions/action_rotate.c \
					actions/action_swap.c \
					sort_easy.c func_sort_easy.c \
					rdx_sort.c
					
OBJES 		= ${SRCS:.c=.o}
OBJES_B 	= ${SRCS_B:.c=.o}

NAME 		= push_swap
NAME_B		= checker
CC 			= cc
CFLAGS 		= -Wall -Wextra -Werror
RM 			= rm -rf

%.o			:	%.c
				$(CC) ${CFLAGS} -c $< -o $@
	

all			:	$(NAME)

$(NAME)		:	$(LIBFT) $(OBJES) push_swap.h
				$(CC) $(OBJES) ${LIBFT} -o $(NAME)
				
$(NAME_B)	:   $(LIBFT) $(OBJES_B) push_swap.h
				$(CC) $(OBJES_B) ${LIBFT} -o $(NAME_B)

$(LIBFT)	:
				$(MAKE) -C $(LIBFT_PATH)

bonus		: $(NAME_B)

clean		:
				$(MAKE) -C $(LIBFT_PATH) clean
				$(RM) $(OBJES)
				$(RM) $(OBJES_B)

fclean		:	clean
				$(MAKE) -C $(LIBFT_PATH) fclean
				$(RM) $(NAME)
				$(RM) $(NAME_B)

re			:	clean all

.PHONY		:	all clean fclean re ${LIBFT}