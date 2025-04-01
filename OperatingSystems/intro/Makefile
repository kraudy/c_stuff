
SRCS = io.c
TARG = io
CC = clang
OPTS = -O -Wall #-o
#LIBS
OBJS = $(SRCS:.c=.o)

all: $(TARG)

$(TARG): $(OBJS)
	$(CC) -o $(TARG) $(OBJS) 		# Links io.o to io

%.o: %.c
	$(CC) $(OPTS) -c $< -o $@  	# Compile io.c to io.o

clean:
	rm -f $(OBJS) $(TARG)
