GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDEDIR = include
#LIBFT_PATH = include/libft
MLX_PATH = include/minilibx-linux

SRCDIR = .
#//OTHER DIRS
SRCS = $(SRCDIR)/main.c

OBJS = $(SRCS:.c=.o)

#LIBFT = $(LIBFT_PATH)/libft.a
MLX = $(MLX_PATH)/libmlx.a

$(MLX):
	@$(MAKE) -C $(MLX_PATH)

TARGET = fractols

all:	$(TARGET)

$(TARGET):	$(OBJS) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OBJS) -o  $(TARGET) -L$(MLX_PATH) -lmlx -lXext -lX11
	@echo "$(TARGET): $(GREEN)object files were created$(RESET)"
	@echo "$(TARGET): $(GREEN)$(TARGET) was created$(RESET)"


%.o:	%.c
	$(CC) $(CFLAGS) -I$(INCLUDEDIR) -I$(LIBFT_PATH) -I$(MLX_PATH) -c $< -o $@

clean:
	rm -f $(OBJS)
	@echo "$(RED)Cleaned object files$(RESET)"

fclean:
	rm -f $(TARGET)
	@echo "$(RED)Cleaned targets$(RESET)"

re:	fclean all
	@echo "$(GREEN)Rebuilding Library$(RESET)"

