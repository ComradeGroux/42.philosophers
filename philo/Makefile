# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/22 14:55:53 by vgroux            #+#    #+#              #
#    Updated: 2023/03/28 14:20:14 by vgroux           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREENGREEN = \033[38;5;46m
RED = \033[0;31m
GREY = \033[38;5;240m
RESET = \033[0m

NAME =     philo

CC =         gcc
CFLAGS =     -Wall -Wextra -Werror
RM =         rm -rf

SFLAGS = -fsanitize=thread -g

DIR_H = headers/
DIR_S =	srcs/
DIR_O =	objs/
DIR_SAN = san/

SRCS_LIST =	main.c \
			clear.c \
			error.c \
			init.c \
			philo.c \
			routine.c \
			thread.c \
			time.c \
			utils.c

SRCS =		${addprefix ${DIR_S}, ${SRCS_LIST}}

OBJS =		${SRCS:${DIR_S}%.c=${DIR_O}%.o}

SAN-OBJS =	${SRCS:${DIR_S}%.c=${DIR_SAN}%.o}

${NAME}: ${OBJS}
	@echo "$(RESET)[$(GREENGREEN)${NAME}$(RESET)]: ${NAME} objects were created${GREY}"
	${CC} ${OBJS} -lpthread -o ${NAME}
	@echo "$(RESET)[$(GREENGREEN)${NAME}$(RESET)]: ${NAME} created !"

all: ${NAME}

san: fclean ${SAN-OBJS}
	${CC} ${SAN-OBJS} -lpthread -o ${NAME} ${SFLAGS}

${DIR_O}%.o:${DIR_S}%.c
	@printf "${GREY}"
	@mkdir -p ${DIR_O}
	${CC} ${CFLAGS} -I ${DIR_H} -o $@ -c $<

${DIR_SAN}%.o:${DIR_S}%.c
	@printf "${GREY}"
	@mkdir -p ${DIR_SAN}
	${CC} ${CFLAGS} ${SFLAGS} -I ${DIR_H} -o $@ -c $<

clean:
	@echo "[$(RED)${NAME}$(RESET)]: oleaning ${NAME} objects...${GREY}"
	${RM} ${OBJS}
	${RM} ${DIR_O}
	${RM} ${DIR_SAN}
	@echo "[$(RED)${NAME}$(RESET)]: ${NAME} objects were cleaned${GREY}"

fclean: clean
	@echo "${RESET}[$(RED)${NAME}$(RESET)]: oleaning ${NAME}...${GREY}"
	${RM} ${NAME}
	@echo "${RESET}[$(RED)${NAME}$(RESET)]: ${NAME} executable was cleaned"

printcompil:
	@echo "$(RESET)[$(GREENGREEN)${NAME}$(RESET)]: ${NAME} objects compilation...${GREY}"

re: fclean printcompil all

.PHONY: all clean fclean re