CC:=gcc
CLFLAGS:= -Wall -Werror -fPIC
ENDFLAGS:= -lm
COMP:= $(CC) $(CLFLAGS)

SRCS := $(wildcard *.c)
OBJS := ${SRCS:c=o}
EXEC_FILE:=electrotest

LOC := lib
VERSION:=1.0
POW_FILE:=$(LOC)/libpower.so.$(VERSION)
COM_FILE:=$(LOC)/libcomponent.so.$(VERSION)
RES_FILE:=$(LOC)/libresistance.so.$(VERSION)

all : $(SRCS) lib $(EXEC_FILE) 

lib : libpower.o libcomponent.o libresistance.o
	@if [ ! -d "./lib" ];\
	then echo "lib directory does not exists\
	and will be created";\
	mkdir lib;\
        fi	
	gcc -shared libpower.o -o $(POW_FILE); \
	gcc -shared libcomponent.o -o $(COM_FILE); \
	gcc -shared libresistance.o -o $(RES_FILE); \
	ln -s ./libpower.so.$(VERSION) ./lib/libpower.so	
	ln -s ./libcomponent.so.$(VERSION) ./lib/libcomponent.so
	ln -s ./libresistance.so.$(VERSION) ./lib/libresistance.so
	rm *.o

$(EXEC_FILE) : $(EXEC_FILE).c
	$(CC) $(EXEC_FILE).c -o $(EXEC_FILE) -L./$(LOC) -lresistance -lcomponent -lpower  -Wl,-rpath,./$(LOC) $(ENDFLAGS); \

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
	-@rm -rf $(EXEC_FILE) $(OBJS) $(COM_FILE) $(POW_FILE) ./$(LOC)
