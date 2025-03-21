CLIENT = client.c
SERVER = server.c

CLIENT_BONUS = client_bonus.c
SERVER_BONUS = server_bonus.c

OBJ_CLIENT = $(CLIENT:.c=.o)
OBJ_SERVER = $(SERVER:.c=.o)

OBJ_CLIENT_B = $(CLIENT_BONUS:.c=.o)
OBJ_SERVER_B = $(SERVER_BONUS:.c=.o)

EXE_CLIENT = client
EXE_SERVER = server

FT_PRINTF_PATH = ./ft_printf
FT_PRINTF = $(FT_PRINTF_PATH)/libftprintf.a

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: mandatory


mandatory:		$(OBJ_CLIENT) $(OBJ_SERVER) $(FT_PRINTF) $(LIBFT)
				$(CC) $(CFLAGS) $(OBJ_CLIENT) $(FT_PRINTF) $(LIBFT) -o $(EXE_CLIENT)
				$(CC) $(CFLAGS) $(OBJ_SERVER) $(FT_PRINTF) $(LIBFT) -o $(EXE_SERVER)
				echo "Created mandatory part."

$(LIBFT):
				@make -C $(LIBFT_PATH)

$(FT_PRINTF):
				@make -C $(FT_PRINTF_PATH)

bonus:			$(OBJ_CLIENT_B) $(OBJ_SERVER_B) $(FT_PRINTF) $(LIBFT)
				$(CC) $(CFLAGS) $(OBJ_CLIENT_B) $(FT_PRINTF) $(LIBFT) -o $(EXE_CLIENT)
				$(CC) $(CFLAGS) $(OBJ_SERVER_B) $(FT_PRINTF) $(LIBFT) -o $(EXE_SERVER)
				echo "Created bonus part."

clean:
				@make -C $(LIBFT_PATH) clean
				@make -C $(FT_PRINTF_PATH) clean
				@rm -rf $(OBJ_CLIENT)
				@rm -rf $(OBJ_CLIENT_B)
				@rm -rf $(OBJ_SERVER)
				@rm -rf $(OBJ_SERVER_B)

fclean: clean
				@make -C $(LIBFT_PATH) fclean
				@make -C $(FT_PRINTF_PATH) fclean
				@rm -rf $(FT_PRINTF)
				@rm -rf $(LIBFT)
				@rm -rf $(EXE_CLIENT) $(EXE_SERVER)

re:	fclean all

.PHONY: all fclean clean re 
