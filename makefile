CC:=gcc
CLFLAGS:= -Wall -Werror -fPIC
ENDFLAGS:= -lm
COMP:= $(CC) $(CLFLAGS)

SRCS := $(wildcard *.c)
OBJS := ${SRCS:c=o}
EXEC_FILE:=electrotest

LOC := lib/
VERSION:=1.0
POW_FILE:=libpower.so.$(VERSION)
COM_FILE:=libcomponent.so.$(VERSION)
RES_FILE:=libresistance.so.$(VERSION)
LIB_FILES:= $(POW_FILE) $(COM_FILE) $(RES_FILE)

all : $(SRCS) lib $(EXEC_FILE) 

lib : $(LOC) $(POW_FILE) $(COM_FILE) $(RES_FILE)

$(EXEC_FILE) : $(EXEC_FILE).c
	$(CC) -Wl,-rpath,./$(LOC) $(EXEC_FILE).c -o $(EXEC_FILE) -L./$(LOC) -l:$(POW_FILE) -l:$(RES_FILE) -l:$(COM_FILE) $(ENDFLAGS)
libpower.o : libpower.c libpower.h
	$(COMP) -c libpower.c
libcomponent.o : libcomponent.c libcomponent.h
	$(COMP) -c libcomponent.c 
libresistance.o: libresistance.c libresistance.h
	$(COMP) -c libresistance.c

$(POW_FILE) : libpower.o
	gcc -shared -Wl,-soname,$(POW_FILE) -o $(LOC)$(POW_FILE) libpower.o
$(COM_FILE) : libcomponent.o
	gcc -shared -Wl,-soname,$(COM_FILE) -o $(LOC)$(COM_FILE) libcomponent.o
$(RES_FILE) : libresistance.o
	gcc -shared -Wl,-soname,$(RES_FILE) -o $(LOC)$(RES_FILE) libresistance.o
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
	cp $(LOC)$(POW_FILE) /usr/lib/$(POW_FILE)
	cp $(LOC)$(COM_FILE) /usr/lib/$(COM_FILE)
	cp $(LOC)$(RES_FILE) /usr/lib/$(RES_FILE)
	cp $(EXEC_FILE) /usr/bin/
endif

uninstall :
ifneq ($(shell whoami),root)
	@echo "You must be root to uninstall"
else
	rm -f $(addprefix /usr/lib/,$(LIB_FILES))
	rm -f /usr/bin/$(EXEC_FILE)
endif



.PHONY : clean
clean :
	-@rm -rf $(EXEC_FILE) $(OBJS) ./$(LOC)
