PROG = testnumber
CC = g++
CPPFLAGS = -g 
LDFLAGS =
OBJS = testnumber.o integer.o fraction.o util.o
INC = ./inc
$(PROG) : $(OBJS)
	$(CC) -I$(INC) $(LDFLAGS) -o $(PROG) $(OBJS)
testnumber.o : testnumber.C
	$(CC) -I$(INC) $(CPPFLAGS) -c testnumber.C
integer.o :   integer.C $(INC)/integer.H $(INC)/numberbase.H
	$(CC) -I$(INC) $(CPPFLAGS) -c integer.C
fraction.o : fraction.C $(INC)/fraction.H $(INC)/numberbase.H 
	$(CC) -I$(INC) $(CPPFLAGS) -c fraction.C

util.o : util.C $(INC)/util.H 
	$(CC) -I$(INC) $(CPPFLAGS) -c util.C

clean:
	rm -f core $(PROG) $(OBJS) "*~"



