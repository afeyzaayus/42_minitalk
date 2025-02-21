SRC_CLIENT = client.c
SRC_SERVER = server.c

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)

EXE_CLIENT = client
EXE_SERVER = server

FT_PRINTF_PATH = ./ft_printf
FT_PRINTF = $(FT_PRINTF_PATH)/libftprintf.a

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: mandatory

$(LIBFT):
				@make -C $(LIBFT_PATH)

$(FT_PRINTF):
				@make -C $(FT_PRINTF_PATH)

mandatory:		$(OBJ_CLIENT) $(OBJ_SERVER) $(FT_PRINTF) $(LIBFT)
				@$(CC) $(CFLAGS) $(OBJ_CLIENT) $(FT_PRINTF) $(LIBFT) -o $(EXE_CLIENT)
				@$(CC) $(CFLAGS) $(OBJ_SERVER) $(FT_PRINTF) $(LIBFT) -o $(EXE_SERVER)
				@echo "Created mandatory part."

clean:
				@make -C $(LIBFT_PATH) clean
				@make -C $(FT_PRINTF_PATH) clean
				@rm -rf $(OBJ_CLIENT)
				@rm -rf $(OBJ_SERVER)

fclean: clean
				@make -C $(LIBFT_PATH) fclean
				@make -C $(FT_PRINTF_PATH) fclean
				@rm -rf $(FT_PRINTF)
				@rm -rf $(LIBFT)
				@rm -rf $(EXE_CLIENT) $(EXE_SERVER)

re:	fclean all

.PHONY: all fclean clean re
