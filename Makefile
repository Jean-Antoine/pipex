SRCS_D				= ./srcs/
HEADER_D			= ./include/
SRCS_F 				= ft_init_data.c\
						ft_free_data.c\
						ft_get_env_var.c\
						ft_path.c\
						ft_get_cmd_path.c\
						ft_pipex.c\
						ft_exit.c\
						ft_exec.c\
						ft_get_here_doc.c\
						ft_wait.c\
						ft_close_fd.c\
						ft_parse_cmd.c
SRCS				= $(addprefix $(SRCS_D), $(SRCS_F)) main.c
OBJS				= $(SRCS:.c=.o)
LIBFT_D				= ./libft/
LIBFT_HEADER_D		= $(addprefix $(LIBFT_D), /include/)
LIBFT				= $(addprefix $(LIBFT_HEADER_D), libft.a)
CC					= cc
CFLAGS				= -Wall -Wextra -Werror -g
CPPFLAGS			= -I$(HEADER_D) -I$(LIBFT_HEADER_D)
NAME				= pipex

all: 				$(NAME)

$(NAME):			$(OBJS) 
					make -C $(LIBFT_D)
					$(CC) $(CPPFLAGS) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_D) -lft

bonus:				$(NAME)

force_objs:			
					rm -f $(OBJS)

debug:				force_objs $(OBJS)
					make -C $(LIBFT_D)
					$(CC) $(CPPFLAGS) $(CFLAGS) -o debug $(OBJS) -L$(LIBFT_D) -lft

clean:
					make -C $(LIBFT_D) clean
					rm -f $(OBJS)

fclean:
					make -C $(LIBFT_D) fclean
					rm -f $(OBJS) $(NAME)

re:					fclean all

norme:
					norminette $(SRCS)

.PHONY:				all clean fclean re force_objs