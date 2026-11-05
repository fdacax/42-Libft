#	====================		Make		====================
MAKEFLAGS += -s

NAME = libft.a

PROJECT = Libft
USER = fedacax

CC = cc
FLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -rf

SRCS = $(shell find . -name "*.c")
OBJS = $(SRCS:.c=.o)

#	====================		Colors		====================

RED = \033[0;31m
GREEN = \033[0;32m
BLUE = \033[0;34m
YELLOW = \033[0;33m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
B_RED = \033[1;31m
B_GREEN = \033[1;32m
B_BLUE = \033[1;34m
L_BLUE = \033[1;94m
B_YELLOW = \033[1;33m
B_MAGENTA = \033[1;35m
B_CYAN = \033[1;36m
RESET = \033[0m

#	====================		Spin		====================

FLAG = 0
SPIN = ⠁ ⠃ ⠇ ⠧ ⠷ ⠿ ⠃ ⠇ ⠧ ⠷ ⠿
SPIN_DELAY = 0.18
LOOP = 0

ifeq ($(FLAG),1)
LOOP = 9
endif

define run_spin
	i=0; \
	while [ $$i -lt $(LOOP) ]; do \
		SPIN_CHAR=$$(printf '%s\n' $(SPIN) | sed -n "$$(( (i % 10) + 1 ))p"); \
		printf "\r\033[K$(CYAN)$$SPIN_CHAR$(RESET) $(1)"; \
		sleep $(SPIN_DELAY); \
		i=$$((i+1)); \
	done; \
	printf "\r\033[K$(GREEN)✔$(RESET) $(1)\n"
endef

#	====================		Header		====================

define print_header
	printf "   $(CYAN)/* ********************************************************************* */$(RESET)\n"
	printf "   $(CYAN)/*                                                                       */$(RESET)\n"
	printf "   $(CYAN)/*                           $(PROJECT) by: $(USER)                           */$(RESET)\n"
	printf "   $(CYAN)/*                                                                       */$(RESET)\n"
	printf "   $(CYAN)/*            :::      ::::::::    :::::::::  :::::::::::  :::::::::     */$(RESET)\n"
	printf "   $(CYAN)/*          :+:      :+:    :+:   :+:     :+: :+:     :+: :+:     :+:    */$(RESET)\n"
	printf "   $(CYAN)/*        +:+ +:+         +:+     +:+     +:+ +:+     +:+ +:+     +:+    */$(RESET)\n"
	printf "   $(CYAN)/*      +#+  +:+       +#+        +#+     +:+ +#+#+#+#+#+ +#+     +:+    */$(RESET)\n"
	printf "   $(CYAN)/*    +#+#+#+#+#+   +#+           +#+     +#+ +#+         +#+     +#+    */$(RESET)\n"
	printf "   $(CYAN)/*         #+#    #+#             #+#     #+# #+#         #+#     #+#    */$(RESET)\n"
	printf "   $(CYAN)/*        ###   ########           #########  ###          #########     */$(RESET)\n"
	printf "   $(CYAN)/*                                                                       */$(RESET)\n"
	printf "   $(CYAN)/* ********************************************************************* */$(RESET)\n"
	printf "\n"
endef

#	====================		Help		====================

define print_help
	printf "  $(BOLD)$(CYAN)╔══════════════════════════════════╗$(RESET)\n"
	printf "  $(BOLD)$(CYAN)║            $(PROJECT) - help          ║$(RESET)\n"
	printf "  $(BOLD)$(CYAN)╚══════════════════════════════════╝$(RESET)\n"
	printf "  $(B_GREEN)make$(RESET)          $(B_YELLOW)→$(RESET) build $(NAME)\n"
	printf "  $(B_GREEN)make bonus$(RESET)    $(B_YELLOW)→$(RESET) build with bonus files\n"
	printf "  $(B_GREEN)make clean$(RESET)    $(B_YELLOW)→$(RESET) remove object files\n"
	printf "  $(B_GREEN)make fclean$(RESET)   $(B_YELLOW)→$(RESET) remove objects and $(NAME)\n"
	printf "  $(B_GREEN)make re$(RESET)       $(B_YELLOW)→$(RESET) fclean + build\n"
	printf "  $(B_GREEN)make norm$(RESET)     $(B_YELLOW)→$(RESET) run Norminette\n"
	printf "  $(B_RED)make val$(RESET)      $(B_YELLOW)→$(RESET) run Valgrind\n"
	printf "  $(B_RED)make debug$(RESET)    $(B_YELLOW)→$(RESET) build with debug flags\n"
	printf "  $(B_GREEN)make help$(RESET)     $(B_YELLOW)→$(RESET) show this message\n"
	printf "\n"
endef

#	====================		Rules		====================

all : $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
	clear
	$(call print_header)
	$(call run_spin, Compiling source files)
	$(call run_spin, Creating library $(NAME))

%.o: %.c libft.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(call run_spin, Removing object files)

fclean:
	$(RM) $(NAME) $(OBJS)
	$(call run_spin, Cleaning)

bonus: all

re: fclean all

norm:
	norminette $(SRCS) *.h

help:
	clear
	$(call print_help)

test:re
	$(CC) $(FLAGS) main.c $(NAME) -lbsd

.PHONY: all bonus clean fclean re norm test