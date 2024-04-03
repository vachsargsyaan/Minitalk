 NAMEC	= client
NAMES	= server

NAMECB	= client_bonus
NAMESB	= server_bonus

SRC_DIR = src

SRC_B_DIR	= src_bonus

SRCC = $(patsubst %.c, $(SRC_DIR)/%.c, client.c)
SRCS = $(patsubst %.c, $(SRC_DIR)/%.c, server.c)

SRCCB = $(patsubst %.c, $(SRC_B_DIR)/%.c, client_bonus.c)
SRCSB = $(patsubst %.c, $(SRC_B_DIR)/%.c, server_bonus.c)

OBJ_DIR	= obj
OBJ_B_DIR = obj_bonus

OBJC = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCC))
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

OBJCB = $(patsubst $(SRC_B_DIR)/%.c, $(OBJ_B_DIR)/%.o, $(SRCCB))
OBJSB = $(patsubst $(SRC_B_DIR)/%.c, $(OBJ_B_DIR)/%.o, $(SRCSB))

CC		= cc
HEADER	= $(wildcard ./includes/minitalk.h)
HEADERB	= $(wildcard ./includes/minitalk_bonus.h)
INCLUDE	= -Iincludes -Ift_printf
CFLAGS	= -Wall -Wextra -Werror $(INCLUDE)
MK		= mkdir -p

all: ft_printf $(OBJ_DIR) $(NAMEC) $(NAMES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	$(MK) $(OBJ_DIR)

$(NAMES): $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) -o $@ $< -Lft_printf -lftprintf

$(NAMEC): $(OBJC) $(HEADER)
	$(CC) $(CFLAGS) -o $@ $< -Lft_printf -lftprintf

bonus :ft_printf $(OBJ_B_DIR) $(NAMECB) $(NAMESB)

$(OBJ_B_DIR) :
	$(MK) $(OBJ_B_DIR)

$(OBJ_B_DIR)/%.o : $(SRC_B_DIR)/%.c $(HEADERB) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

$(NAMECB) : $(OBJCB) $(HEADERB)
	$(CC) $(CFLAGS) -o $@ $< -Lft_printf -lftprintf
 
$(NAMESB) : $(OBJSB) $(HEADERB)
	$(CC) $(CFLAGS) -o $@ $< -Lft_printf -lftprintf

ft_printf:
	@make -C ft_printf

clean:
	@rm -f $(OBJC)
	@rm -f $(OBJS)
	@rm -f $(OBJCB)
	@rm -f $(OBJSB)
	@make -C ft_printf clean
	
fclean: clean
	@rm -f $(NAMEC) $(NAMES)
	@rm -f $(NAMECB) $(NAMESB)
	@rm -rf ft_printf/libftprintf.a
	@rm -rf $(OBJ_DIR)
	@rm -rf $(OBJ_B_DIR)

re: fclean all bonus

.PHONY: all bonus ft_printf clean fclean re