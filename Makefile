
NAMEC = client
NAMES = server

SRCC = Mandatory/client.c Mandatory/utils.c 
SRCS = Mandatory/server.c Mandatory/utils.c

SRCC_B = bonus/client.c bonus/utils.c 
SRCS_B = bonus/server.c bonus/utils.c

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCC_OBJS = $(SRCC:.c=.o)
SRCS_OBJS = $(SRCS:.c=.o)


all : $(NAMEC) $(NAMES)

$(NAMEC) : $(SRCC_OBJS)
	$(CC) $(CFLAGS)  $(SRCC_OBJS) -o $(NAMEC) 
$(NAMES) : $(SRCS_OBJS) 
	$(CC) $(CFLAGS) $(SRCS_OBJS) -o $(NAMES)
	
bonus/%.o : bonus/%.c bonus/head_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

Mandatory/%.o : Mandatory/%.c Mandatory/head.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(SRCC_OBJS) $(SRCS_OBJS)

fclean: clean
	$(RM) $(NAMEC) $(NAMES)

re: fclean all