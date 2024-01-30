SRCS_BASE =					ft_isalpha.c\
							ft_isdigit.c\
							ft_isalnum.c\
							ft_isascii.c\
							ft_isprint.c\
							ft_strlen.c\
							ft_memset.c\
							ft_bzero.c\
							ft_memcpy.c\
							ft_memmove.c\
							ft_strlcpy.c\
							ft_strlcat.c\
							ft_toupper.c\
							ft_tolower.c\
							ft_strchr.c\
							ft_strrchr.c\
							ft_strncmp.c\
							ft_memchr.c\
							ft_memcmp.c\
							ft_strnstr.c\
							ft_atoi.c\
							ft_calloc.c\
							ft_strdup.c\
							ft_substr.c\
							ft_strjoin.c\
							ft_strtrim.c\
							ft_split.c\
							ft_itoa.c\
							ft_strmapi.c\
							ft_striteri.c\
							ft_putchar_fd.c\
							ft_putstr_fd.c\
							ft_putendl_fd.c\
							ft_putnbr_fd.c\
							ft_atof.c\
							ft_min.c\
							ft_max.c\
							ft_abs.c\
							ft_max_array.c\
							ft_min_array.c\
							ft_free_tab.c
SRCS_LIST =					ft_lstnew_bonus.c\
							ft_lstadd_front_bonus.c\
							ft_lstsize_bonus.c\
							ft_lstlast_bonus.c\
							ft_lstadd_back_bonus.c\
							ft_lstdelone_bonus.c\
							ft_lstclear_bonus.c\
							ft_lstiter_bonus.c\
							ft_lstmap_bonus.c
SRCS_GNL = 					get_next_line.c\
							get_next_line_utils.c
SRCS_PRINTF =				ft_printf.c\
							ft_itostr.c\
							ft_ptrtostr.c\
							ft_putstr.c\
							ft_strapd_c.c\
							ft_strppd_c.c\
							ft_newfld.c\
							ft_readformat.c \
							ft_readflags.c \
							ft_readparams.c \
							ft_strpadding.c \
							ft_applyprecision.c\
							ft_applysign.c \
							ft_applyhexprefix.c\
							ft_applywidth.c\
							ft_fldmap.c \
							ft_clearfldlst.c 
SRCS = 						$(addprefix ./srcs/base/, $(SRCS_BASE))\
							$(addprefix ./srcs/list/, $(SRCS_LIST))\
							$(addprefix ./srcs/gnl/, $(SRCS_GNL))\
							$(addprefix ./srcs/printf/, $(SRCS_PRINTF))
HEADER_D =					./include/
OBJS = $(SRCS:.c=.o)
NAME = libft.a
CC = cc
CPPFLAGS = -I./include/
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar crs $@ $?

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

norme:
	norminette $(SRCS)
	norminette -R CheckDefine $(HEADER_D)
