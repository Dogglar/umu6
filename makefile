CC:=gcc
CLFLAGS:= -Wall -Werror -fPIC
ENDFLAGS:= -lm
COMP:= $(CC) $(CLFLAGS)

SRCS := $(wildcard *.c)
OBJS := ${SRCS:c=o}
EXEC_FILE:=electrotest

LOC := lib/
VERSION:=1.0
POW_FILE:=$(LOC)/libpower.so.$(VERSION)
COM_FILE:=$(LOC)/libcomponent.so.$(VERSION)
RES_FILE:=$(LOC)/libresistance.so.$(VERSION)

all : $(SRCS) $(EXEC_FILE) $(lib)

lib : libpower.o libcomponent.o libresistance.o
	gcc -shared libpower.o -o $(POW_FILE); \
	gcc -shared libcomponent.o -o $(COM_FILE); \
	gcc -shared libcomponent.o -o $(RES_FILE); \
	rm *.o

$(EXEC_FILE) : $(OBJS)
	$(COMP) $(OBJS) -o $(EXEC_FILE) $(ENDFLAGS); \

install : $(LIB_FILE)

main.o : main.c
libpower.o : libpower.c libpower.h
	$(COMP) -c libpower.c
libcomponent.o : libcomponent.c libcomponent.h
	$(COMP) -c libcomponent.c 
libresistance.o: libresistance.c libresistance.h
	$(COMP) -c libresistance.c 

.PHONY : clean
clean :
	-@rm -rf $(EXEC_FILE) $(OBJS) $(COM_FILE) $(POW_FILE) 
