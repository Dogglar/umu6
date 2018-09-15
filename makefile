CC:=gcc
CLFLAGS:= -Wall -Werror -fPIC
ENDFLAGS:= -lm
COMP:= $(CC) $(CLFLAGS)

SRCS := $(wildcard *.c)
OBJS := ${SRCS:c=o}
EXEC_FILE:=electrotest

LOC := lib/
VERSION:=1.0
POW_FILE:=$(LOC)libpower.so
COM_FILE:=$(LOC)libcomponent.so
RES_FILE:=$(LOC)libresistance.so
LIB_FILES:= $(POW_FILE) $(COM_FILE) $(RES_FILE)

all : $(SRCS) lib $(EXEC_FILE) 

lib : $(LOC) $(POW_FILE) $(COM_FILE) $(RES_FILE)
	rm *.o

$(EXEC_FILE) : $(EXEC_FILE).c
	$(CC) $(EXEC_FILE).c -o $(EXEC_FILE) -L./$(LOC) -lresistance -lcomponent -lpower  -Wl,-rpath,./$(LOC) $(ENDFLAGS);

libpower.o : libpower.c libpower.h
	$(COMP) -c libpower.c
libcomponent.o : libcomponent.c libcomponent.h
	$(COMP) -c libcomponent.c 
libresistance.o: libresistance.c libresistance.h
	$(COMP) -c libresistance.c

$(POW_FILE) : libpower.o
	gcc -shared libpower.o -o $(POW_FILE)
$(COM_FILE) : libcomponent.o
	gcc -shared libcomponent.o -o $(COM_FILE)
$(RES_FILE) : libresistance.o
	gcc -shared libresistance.o -o $(RES_FILE)
$(LOC) :
	@if [ ! -d "./lib" ];\
	then echo "lib directory does not exists\
	and will be created";\
	mkdir lib;\
        fi

install : 
ifneq ($(shell whoami),root)
	@echo "You must be root to install"
else
	cp $(POW_FILE) /usr/$(POW_FILE).$(VERSION)
	cp $(COM_FILE) /usr/$(COM_FILE).$(VERSION)
	cp $(RES_FILE) /usr/$(RES_FILE).$(VERSION)
	cp $(EXEC_FILE) /usr/bin/
endif

uninstall :
ifneq ($(shell whoami),root)
	@echo "You must be root to uninstall"
else
	rm -f $(addsuffix .$(VERSION),$(addprefix /usr/,$(LIB_FILES)))
	rm -f /usr/bin/$(EXEC_FILE)
endif



.PHONY : clean
clean :
	-@rm -rf $(EXEC_FILE) $(OBJS) ./$(LOC)
