
SRCS = io.c

TARG = io

CC = clang

OPTS = -O -Wall #-o
#LIBS
OBJS = $(SRCS:.c=.o)

all: $(TARG)

$(TARG): $(SRCS)
	$(CC) $(OPTS) -o $(TARG) $(SRCS)

clean:
	rm -f $(TARG)
