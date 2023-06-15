SRCS = so_long.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c ft_printf.c ft_strncmp.c \
		print_error.c utils.c valide_map/validation_map.c valide_map/validation_path.c valide_map/utilsmap.c \
		drawer/drawer.c drawer/moves.c



OBJS			= $(SRCS:.c=.o)
CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.
NAME			= so_long


%.o : %.c
		@$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME) 

$(NAME): $(OBJS)
			CC  -lmlx -framework OpenGL -framework AppKit  $(OBJS) -o $(NAME)

clean:
				@$(RM) $(OBJS) 
			
fclean:			clean
				@$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY: all fclean clean re