CC := cc
CFLAGS := -MMD -Wall -Wextra -Werror
COMPILE.c := $(CC) $(CFLAGS) -c
OUTPUT_OPTION = -o $@

LIBFT_DIR := lib/libft
LIBFT := $(LIBFT_DIR)/libft.a

LIBMLX_DIR := lib/MLX42
LIBMLX := $(LIBMLX_DIR)/build/libmlx42.a

LDFLAGS := -L$(LIBFT_DIR) -L$(LIBMLX_DIR)/build
LINK.o := $(CC) $(LDFLAGS)
LDLIBS := -lft -lmlx42 -ldl -lglfw -pthread -lm

RM := rm -f
RMDIR := rm -rf

NAME := so_long
SRCS_DIR := srcs
SRCS := main.c game.c tilemap.c collectibles.c exit.c player.c movements.c log.c
BUILD_DIR := build
OBJS := $(SRCS:%.c=$(BUILD_DIR)/%.o)
DEPS := $(SRCS:%.c=$(BUILD_DIR)/%.d)

NAME_BONUS := so_long_bonus
SRCS_DIR_BONUS := srcs_bonus
SRCS_BONUS := main_bonus.c
BUILD_DIR_BONUS := build_bonus
OBJS_BONUS := $(SRCS_BONUS:%.c=$(BUILD_DIR_BONUS)/%.o)
DEPS_BONUS := $(SRCS_BONUS:%.c=$(BUILD_DIR_BONUS)/%.d)


.PHONY: all bonus clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(LIBMLX) $(OBJS)
	$(LINK.o) $(OBJS) $(LDLIBS) -o $@

$(BUILD_DIR)/%.o: $(SRCS_DIR)/%.c $(BUILD_DIR)/%.d Makefile | $(BUILD_DIR)
	$(COMPILE.c) $(OUTPUT_OPTION) $<

$(BUILD_DIR):
	mkdir -p $@


bonus: $(NAME_BONUS)

$(NAME_BONUS): $(LIBFT) $(LIBMLX) $(OBJS_BONUS)
	$(LINK.o) $(OBJS_BONUS) $(LDLIBS) -o $@

$(BUILD_DIR_BONUS)/%.o: $(SRCS_DIR_BONUS)/%.c $(BUILD_DIR_BONUS)/%.d \
		Makefile | $(BUILD_DIR_BONUS)
	$(COMPILE.c) $(OUTPUT_OPTION) $<

$(BUILD_DIR_BONUS):
	mkdir -p $@


%.d: ;

-include $(DEPS) $(DEPS_BONUS)


$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(LIBMLX):
	cmake $(LIBMLX_DIR) -B $(LIBMLX_DIR)/build
	make -C $(LIBMLX_DIR)/build -j4


clean:
	$(RMDIR) $(BUILD_DIR) $(BUILD_DIR_BONUS)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(RMDIR) $(LIBMLX_DIR)/build

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS) $(LIBFT) $(LIBMLX)

re:	fclean all
