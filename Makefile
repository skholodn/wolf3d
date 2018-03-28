
NAME = wolf3d

CC = gcc

CFLAGS = -Wall -Wextra -Werror -O3

GL = -lm -lmlx -framework OpenGL -framework AppKit

INCLUDES = wolf3d.h

SRCS =  main.c \
		help_error.c \
        parse_map.c \
        valid_yes_no.c \
        help.c \
        main_wolf.c \
        wolf_init.c \
        drawline.c \
        draw_tools.c \
        keykode.c \
        help1.c \
        help3.c \
        textures.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ) 
	$(CC) $(CFLAGS) $(GL) $(OBJ) -o $(NAME)

%.o: %.c $(INCLUDES) 
	$(CC) $(CFLAGS) -c -o $@ $< -I $(INCLUDES)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
