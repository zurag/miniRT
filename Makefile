NAME		= miniRT

CC			= gcc
RM			= rm -rf

CFLAGS		= -Wall -Wextra  -I $(MINILIBX_INC) -MMD -march=native -O2 -msse4a -flto -pipe #-Werror

# Project builds and dirs
SRCDIR = ./srcs/
SRCNAMES = $(shell ls $(SRCDIR) | grep -E ".+\.c")
SRC = $(addprefix $(SRCDIR), $(SRCNAMES))
INC = ./includes/
BUILDDIR = ./build/
BUILDOBJS = $(addprefix $(BUILDDIR), $(SRCNAMES:.c=.o))

# Libft builds and dirs
LIBDIR = ./libft/
LIBFT = ./libft/libft.a
LIBINC = ./libft/includes/

# Lib minilibx
MINILIBX_DIR = ./minilibx/
MINILIBX_INC = ./minilibx/mlx.h
MLX = libmlx.dylib

all: $(BUILDDIR) $(LIBFT) $(MLX) $(NAME)

# Object dir rule
$(BUILDDIR):
	mkdir -p $(BUILDDIR)

# Objects rule
$(BUILDDIR)%.o:$(SRCDIR)%.c
	$(CC) $(CFLAGS) -I$(LIBINC) -I$(INC) -I$(MINILIBX_INC) -o $@ -c $<

# Project file rule
$(NAME): $(BUILDOBJS)
	$(CC) $(CFLAGS) $(BUILDOBJS) $(LIBFT) -I $(INC) -I $(MINILIBX_INC) $(MLX) -o $(NAME)

# minilibx rule
$(MLX):
	make -C $(MINILIBX_DIR)
	mv $(addprefix $(MINILIBX_DIR), $(MLX)) .

# Libft rule

$(LIBFT):
	make -C $(LIBDIR)

clean:
	$(RM) $(BUILDDIR)
	make -C $(LIBDIR) clean
	make -C $(MINILIBX_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBDIR) fclean
	make -C $(MINILIBX_DIR) clean

re: fclean all

.PHONY: all clean fclean re