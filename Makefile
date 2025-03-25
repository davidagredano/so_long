CC = cc
CFLAGS = -MMD -Wall -Wextra -Werror
COMPILE.c = $(CC) $(CFLAGS) -c
OUTPUT_OPTION = -o $@

LIBFT = libft.a
LIBFT_DIR = lib/libft

LDFLAGS = -L $(LIBFT_DIR)
LINK.o = $(CC) $(LDFLAGS)
LDLIBS = -lft

RM = rm -f
RMDIR = rm -rf

NAME = so_long
SRCS_DIR = srcs
SRCS = main.c
BUILD_DIR = build
OBJS = $(SRCS:%.c=$(BUILD_DIR)/%.o)
DEPS = $(SRCS:%.c=$(BUILD_DIR)/%.d)

NAME_BONUS = so_long_bonus
SRCS_DIR_BONUS = srcs_bonus
SRCS_BONUS = main_bonus.c
BUILD_DIR_BONUS = build_bonus
OBJS_BONUS = $(SRCS_BONUS:%.c=$(BUILD_DIR_BONUS)/%.o)
DEPS_BONUS = $(SRCS_BONUS:%.c=$(BUILD_DIR_BONUS)/%.d)


.PHONY: all bonus clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(LINK.o) $^ $(LDLIBS) -o $@

$(BUILD_DIR)/%.o: $(SRCS_DIR)/%.c $(BUILD_DIR)/%.d Makefile | $(BUILD_DIR)
	$(COMPILE.c) $(OUTPUT_OPTION) $<

$(BUILD_DIR):
	mkdir -p $@


bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	$(MAKE) -C $(LIBFT_DIR)
	$(LINK.o) $^ $(LDLIBS) -o $@

$(BUILD_DIR_BONUS)/%.o: $(SRCS_DIR_BONUS)/%.c $(BUILD_DIR_BONUS)/%.d \
		Makefile | $(BUILD_DIR_BONUS)
	$(COMPILE.c) $(OUTPUT_OPTION) $<

$(BUILD_DIR_BONUS):
	mkdir -p $@


%.d: ;

-include $(DEPS) $(DEPS_BONUS)


clean:
	$(RMDIR) $(BUILD_DIR) $(BUILD_DIR_BONUS)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS) $(LIBFT_DIR)/$(LIBFT)

re:	fclean all
