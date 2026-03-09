NAME			:=	get_next_line.a

MAKEFLAGS		+=	-j
COMPILER		:=	cc
CFLAGS			+=	-Wall -Wextra -Werror							\
					-Wpedantic -Wundef -Wstrict-prototypes			\
					-Wshadow -Wconversion -Wsign-conversion			\
					-Wformat=2 -Wuninitialized -Wunreachable-code	\
					-MMD -MP

OPTIMIZATION	:=	-O2
SECURITY		:=	-D_FORTIFY_SOURCE=2 -fstack-protector-strong
DEBUG_FLAGS		:=	-g3 -fno-omit-frame-pointer
SANITIZERS		:=	-fsanitize=address,undefined,null,leak,integer-divide-by-zero,signed-integer-overflow,bounds,alignment
CFLAGS			+=	$(OPTIMIZATION) $(SECURITY)
ifneq ($(filter debug,$(MAKECMDGOALS)),)
	CFLAGS		+=	$(DEBUG_FLAGS) $(SANITIZERS)
endif

PRINT_NO_DIR	:=	--no-print-directory
RM				:=	rm -rf

SRC_DIR			:=	src
INC_DIR			:=	include
BUILD_DIR		:=	.build

GNL				:=	get_next_line.c		get_input_buff.c

# Generate source file names
SRC				:=	$(addprefix $(SRC_DIR)/, $(GNL))

# Generate object file names
OBJ				:=	$(SRC:%.c=$(BUILD_DIR)/%.o)

# Generate Dependency files
DEPS			:=	$(OBJ:.o=.d)

DELETE			:=	*.out			**/*.out			.DS_Store	\
					**/.DS_Store	.dSYM/				**/.dSYM/

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@printf "$(CREATED)" $@ $(CUR_DIR)

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(COMPILER) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	@$(RM) $(BUILD_DIR) $(DELETE)
	@printf "$(REMOVED)" $(BUILD_DIR) $(CUR_DIR)$(BUILD_DIR)

fclean: clean
	@$(RM) $(NAME) $(DELETE)
	@printf "$(REMOVED)" $(NAME) $(CUR_DIR)

re:
	$(MAKE) $(PRINT_NO_DIR) fclean
	$(MAKE) $(PRINT_NO_DIR) all

debug: all

print-%:
	$(info $($*))

-include $(DEPS)

.PHONY:	all clean fclean re debug print-%

# Terminal markup
BOLD			:=	\033[1m
GREEN			:=	\033[32m
MAGENTA			:=	\033[35m
CYAN			:=	\033[36m
RESET			:=	\033[0m

R_MARK_UP		:=	$(MAGENTA)$(BOLD)
CA_MARK_UP		:=	$(GREEN)$(BOLD)

# Current directory and formatted status messages
CUR_DIR			:=	$(dir $(abspath $(firstword $(MAKEFILE_LIST))))
REMOVED			:=	$(R_MARK_UP)REMOVED $(CYAN)%s$(MAGENTA) (%s) $(RESET)\n
CREATED			:=	$(CA_MARK_UP)CREATED $(CYAN)%s$(GREEN) (%s) $(RESET)\n
