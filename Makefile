# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/15 05:20:59 by emaksimo          #+#    #+#              #
#    Updated: 2023/01/24 17:23:42 by emaksimo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = numbers_dict


INCD = includ/
SRSD = srcs/
OBJD = objects/

SOURCES = main.c course.c nbr.c utl.c more_bl.c

OBJECTS := ${addprefix ${OBJD},${SOURCES:.c=.o}}
SOURCES := ${addprefix ${SRCD},${SOURCES:.c=.o}}

CC = cc
CFLAGS = -Wall -Wextra -Werror

BLUE = \033[1;36m 
PINK = \033[1;35m
RESET = \033[0m

WHALE	=	"\n$(BLUE)       ::: \n     ___:____     |^\/^| \n   ,'        '.    \  / \n   |  O        \___/  | \n ~^~^~^~^~^~^~^~^~^~^~^~^~\n \n Compilation Successful!\n\n   by emaksimo for 42 \n	${NC}\n"
NUKE	=	"\n$(PINK)    _.-^^---....,,--       \n _--                  --_  \n<                        >)\n|                         | \n \._                   _./  \n    '''--. . , ; .--'''       \n          | |   |             \n       .-=||  | |=-.   \n       '-=£€%&%€£=-'   \n          | ;  :|     \n _____.,-£%&€@%£&£~,._____\n ${NC}\n"

.PHONY: all clean fclean re


all: $(NAME)
	@echo $?

$(NAME): $(OBJECTS) $(INCD)rush.h
	$(CC) $(CFLAGS) $(OBJECTS) -I$(INCD) -o $(NAME) 
	@echo "\n$(NAME): $(BLUE) Making Numbers_dict2... $(RESET)"
	@echo $(WHALE)
	

$(OBJD)%.o: $(SRSD)%.c
	mkdir -p $(OBJD)
	$(CC) -c -o $@ $(CFLAGS) -I$(INCD) $?


clean:  
	-rm -rf $(OBJD)
	@echo "$(PINK)clean Numbers_dict $(RESET)"


fclean: clean
	-rm -f $(NAME)
	@echo "$(PINK)fclean Numbers_dict $(RESET)"
	@echo "$(PINK) ...3 2 1 $(RESET)"
	@echo $(NUKE)

re: fclean all