NAME = libftprintf.a
#
SRCS 	= 	ft_printf.c\
			ft_printf_utils.c\
			arg_utils_one.c\
			arg_utils_two.c
#
HEADER	=	ft_printf.h
OBJ		=	$(patsubst %.c, %.o, $(SRCS))
#
CFLAGS 	= 	-Wall -Wextra -Werror
#
.PHONY	: 	all clean fclean re
#
all		:	${NAME}
#
$(NAME)	:	$(OBJ)
	ar	rcs	$(NAME) $?
#
%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
#
clean	:
	$(RM) $(OBJ)
#
fclean	:	clean
	$(RM) $(NAME)
#
re		:	fclean all
#