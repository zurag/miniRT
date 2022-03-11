
NAME		= miniRT

SOURCES_LIST	= 	srcs/main/main.c \
					srcs/main/vector.c \
					srcs/main/vector1.c \
					srcs/main/scene.c \
					srcs/Parser/parse_capital.c \
					srcs/Parser/parse_lowercase.c \
					srcs/Parser/parser_root.c \
					srcs/Parser/parser_utils.c \
					srcs/Parser/parser_utils1.c \
					srcs/Utils/init_and_hooks.c \
					srcs/Utils/color.c \
					srcs/Utils/utils.c \
					srcs/Figures/camera.c \
					srcs/Figures/cylinder.c \
					srcs/Figures/light.c \
					srcs/Figures/plane.c \
					srcs/Figures/sphere.c \
					srcs/Raytracer/intersect.c \
					srcs/Raytracer/raytrace_root.c \

CC		= gcc
CFLAGS	=	-Werror -Wall -Wextra -g
# -MMD -march=native -O2 -msse4a -flto -pipe
LIBRARIES = -lmlx -lm -lft\
	-L$(LIBFT_DIRECTORY) -L$(MINILIBX_DIRECTORY)\
	-Wno-deprecated-declarations\
	-framework OpenGL -framework AppKit
INCLUDES = -I$(LIBFT_HEADERS) -I$(MINILIBX_HEADERS) -I$(HEADERS_DIR)

HEADERS_LIST = \
				miniRT.h
HEADERS_DIR	=	./includes/
HEADERS =	$(addprefix $(HEADERS_DIR), $(HEADERS_LIST))


LIBFT	=	$(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = ./libft/
LIBFT_HEADERS = $(LIBFT_DIRECTORY)includes/

MINILIBX =	$(MINILIBX_DIRECTORY)libmlx.a
MINILIBX_DIRECTORY = ./minilibx_opengl/
MINILIBX_HEADERS = $(MINILIBX_DIRECTORY)mlx.h

OBJECTS	=	$(patsubst %.c, %.o, $(SOURCES_LIST))
D_OBJECTS	=	$(patsubst %.c, %.d, $(SOURCES_LIST))


.PHONY:	all clean fclean re

all	: 	$(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(OBJECTS)
		@$(CC) $(CFLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS) -o $(NAME)

%.o : %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@


$(LIBFT):
		@$(MAKE) -sC $(LIBFT_DIRECTORY)


$(MINILIBX):
		@$(MAKE) -sC $(MINILIBX_DIRECTORY)

clean:
		@$(MAKE) clean -sC $(LIBFT_DIRECTORY)
		@$(MAKE) clean -sC $(MINILIBX_DIRECTORY)
		@rm -f $(OBJECTS)
		@rm -f $(D_OBJECTS)

fclean:	clean
		@rm -f $(NAME)
		@rm -f $(LIBFT)
		@rm -f $(MINILIBX)


re:		fclean all