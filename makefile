CC:=gcc
CLFLAGS:= -Wall -Werror -fPIC

SRCS := $(wildcard *.c)
OBJS := ${SRCS:c=o}
EXEC_FILE:=electrotest

LOC := lib/
VERSION:=1.0
LIB_FILE:=$(LOC)/libpower.so.$(VERSION)


all : $(SRCS) $(EXEC_FILE) $(LIB_FILE)

lib : $(LIB_FILE)
	rm *.o

$(EXEC_FILE) : $(OBJS)
	$(CC) $(CLFLAGS) $(OBJS) -o $(EXEC_FILE) ; \

$(LIB_FILE) : libpower.o
	gcc -shared libpower.o -o $(LIB_FILE)
	#Här går det att lägga till rader för att generera fler bibliotek

install : $(LIB_FILE)

main.o : main.c
libpower.o : libpower.c libpower.h

.PHONY : clean
clean :
	-@rm -rf $(EXEC_FILE) $(OBJS) $(LIB_FILE) 
