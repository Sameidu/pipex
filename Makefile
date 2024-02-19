NAME	=	pipex
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
LFT		=	libft/libft.a
OBJS	=	$(SRCS:.c=.o)
SRCS	=	pipex.c \

all:		$(LFT) $(NAME)

$(NAME):	$(OBJ)
			@$(CC) $(CFLAGS) -o $@ $^ $(LFT)
			@echo "\033[32m[✔] $(NAME) created successfully!\033[0m"

$(LFT):
			@make -s -C libft
			@echo "\033[32m[✔] $(LFT) created successfully!\033[0m"

$(OBJ):		%.o: %.c
			@$(CC) $(CFLAGS) -c -o $@ $<

clean:
			@make -s $@ -C libft
			@rm -rf $(OBJS)
			@echo "\033[31m[✘] $(NAME) objects deleted!\033[0m"

fclean:		clean
			@make -s $@ -C libft
			@rm -rf $(NAME)
			@echo "\033[31m[✘] $(NAME) deleted!\033[0m"

re:			fclean all

.PHONY:		all clean fclean re
		