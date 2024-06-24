
NAMEC = client
NAMES = server
NAMEC_B = client_bonus
NAMES_B = server_bonus


SRCC = Mandatory/client.c Mandatory/utils.c 
SRCS = Mandatory/server.c Mandatory/utils.c

SRCC_B = bonus/client_bonus.c bonus/utils_bonus.c 
SRCS_B = bonus/server_bonus.c bonus/utils_bonus.c

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCC_OBJS = $(SRCC:.c=.o)
SRCS_OBJS = $(SRCS:.c=.o)

SRCC_OBJS_B = $(SRCC_B:.c=.o)
SRCS_OBJS_B = $(SRCS_B:.c=.o)

bonus/%.o : bonus/%.c bonus/head_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

Mandatory/%.o : Mandatory/%.c Mandatory/head.h
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAMEC) $(NAMES)

bonus: $(NAMEC_B) $(NAMES_B)


$(NAMEC) : $(SRCC_OBJS)
	$(CC) $(CFLAGS)  $(SRCC_OBJS) -o $(NAMEC) 
$(NAMES) : $(SRCS_OBJS) 
	$(CC) $(CFLAGS) $(SRCS_OBJS) -o $(NAMES)

$(NAMEC_B) : $(SRCC_OBJS_B)
	$(CC) $(CFLAGS)  $(SRCC_OBJS_B) -o $(NAMEC_B) 
$(NAMES_B) : $(SRCS_OBJS_B) 
	$(CC) $(CFLAGS) $(SRCS_OBJS_B) -o $(NAMES_B)
	

clean:
	$(RM) $(SRCC_OBJS) $(SRCS_OBJS) $(SRCS_OBJS_B) $(SRCC_OBJS_B)

fclean: clean
	$(RM) $(NAMEC) $(NAMES) $(NAMEC_B) $(NAMES_B)

re: fclean all bonus