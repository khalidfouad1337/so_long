all:
	gcc   so_long.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c get_next_line/get_next_line.h  utils.c validation_map.c validation_path.c ft_strncmp.c print_error.c ft_printf.c  -lmlx -framework OpenGL -framework AppKit
