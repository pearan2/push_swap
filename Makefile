# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: honlee <honlee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/04 21:49:15 by honlee            #+#    #+#              #
#    Updated: 2021/03/05 01:16:23 by honlee           ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

SHARE_DIR	=		./srcs_share/
SHARE_SRCNAME = 	\
					get_next_line.c\
					list_stack_util1.c\
					list_stack_util2.c\
					list_stack_util3.c\
					list_stack_util4.c\
					string_util1.c\
					test_util.c\
					validate_util1.c

SHARE_SRCS		=	${addprefix ${SHARE_DIR}, ${SHARE_SRCNAME}}
SHARE_OBJS		=	${SHARE_SRCS:.c=.o}

CHECKER_DIR	=		./srcs_checker/
CHECKER_SRCNAME	=	\
					main.c\

CHECKER_SRCS	=	${addprefix ${CHECKER_DIR}, ${CHECKER_SRCNAME}}
CHECKER_NAME	=	checker
CHECKER_OBJS	=	${CHECKER_SRCS:.c=.o}

PUSH_SWAP_DIR = 	./srcs_push_swap/
PUSH_SWAP_SRCNAME	=	\
						main.c\
						solve_util1.c\
						solve_util2.c\

PUSH_SWAP_SRCS		=	${addprefix ${PUSH_SWAP_DIR}, ${PUSH_SWAP_SRCNAME}}
PUSH_SWAP_NAME		=	push_swap
PUSH_SWAP_OBJS		=	${PUSH_SWAP_SRCS:.c=.o}

INCDIR		=		./includes/
CC			=		gcc
#CF			=		-Wall -Wextra -Werror
CF			=		-g

.c.o		:
					${CC} ${CF} -c $< -o ${<:.c=.o} -I${INCDIR}

${CHECKER_NAME}		:	${CHECKER_OBJS} ${SHARE_OBJS}
					${CC} ${CF} ${CHECKER_OBJS} ${SHARE_OBJS} -o ${CHECKER_NAME}

${PUSH_SWAP_NAME}	:	${PUSH_SWAP_OBJS} ${SHARE_OBJS}
					${CC} ${CF} ${PUSH_SWAP_OBJS} ${SHARE_OBJS} -o ${PUSH_SWAP_NAME}

fclean		:		cclean psclean
					rm -f ${CHECKER_NAME}
					rm -f ${PUSH_SWAP_NAME}

cclean		:		
					rm -f ${CHECKER_OBJS}
					rm -f ${SHARE_OBJS}

psclean		:
					rm -f ${PUSH_SWAP_OBJS}
					rm -f ${SHARE_OBJS}

all			:		${CHECKER_NAME} ${PUSH_SWAP_NAME}

re			:		fclean all
