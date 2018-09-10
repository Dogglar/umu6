CC:=gcc
CLFLAGS:= -Wall -Werror

SRCS := $(wildcard *.c)
OBJS := ${SRCS:c=o}
EXEC_FILE:=testfile
LIB_FILE:=libpower.so

all : $(SRCS) $(EXEC_FILE)

$(EXEC_FILE) : $(OBJS)
	$(CC) $(CLFLAGS) $(OBJS) -o $(EXEC_FILE)

make_static_lib : $(OBJS)
	ar crv $(LIB_FILE) $(OBJS) 

main.o : main.c
libpower.o : libpower.c libpower.h

.PHONY : clean
clean :
	-@rm -f $(EXEC_FILE) $(OBJS) $(LIB_FILE)
