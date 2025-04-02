LIBFT_DIR := lib/libft
LIBFT := $(LIBFT_DIR)/libft.a

LIBMLX_DIR := lib/MLX42
LIBMLX := $(LIBMLX_DIR)/build/libmlx42.a

CC := cc
WFLAGS := -Wall -Wextra -Werror
IDIRS := -I$(LIBMLX_DIR)/include -I$(LIBFT_DIR) -Iincludes
CFLAGS := -MMD $(WFLAGS) $(IDIRS) -g
COMPILE.c := $(CC) $(CFLAGS) -c
OUTPUT_OPTION = -o $@

LDFLAGS := -L$(LIBFT_DIR) -L$(LIBMLX_DIR)/build
LINK.o := $(CC) $(LDFLAGS)
LDLIBS := -lft -lmlx42 -ldl -lglfw -pthread -lm

RM := rm -f
RMDIR := rm -rf

NAME := so_long
SRCS_DIR := srcs
SRCS := main.c game.c map.c map_validation.c collectibles.c player.c \
		movements.c graphics.c textures.c images.c hooks.c exit.c log.c
BUILD_DIR := build
OBJS := $(SRCS:%.c=$(BUILD_DIR)/%.o)
DEPS := $(SRCS:%.c=$(BUILD_DIR)/%.d)


.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(LIBMLX) $(OBJS)
	$(LINK.o) $(OBJS) $(LDLIBS) -o $@

$(BUILD_DIR)/%.o: $(SRCS_DIR)/%.c $(BUILD_DIR)/%.d Makefile | $(BUILD_DIR)
	$(COMPILE.c) $(OUTPUT_OPTION) $<

$(BUILD_DIR):
	mkdir -p $@


%.d: ;

-include $(DEPS)


$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(LIBMLX):
	cmake $(LIBMLX_DIR) -B $(LIBMLX_DIR)/build
	make -C $(LIBMLX_DIR)/build -j4


clean:
	$(RMDIR) $(BUILD_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(RMDIR) $(LIBMLX_DIR)/build

fclean: clean
	$(RM) $(NAME) $(LIBFT) $(LIBMLX)

re:	fclean all
