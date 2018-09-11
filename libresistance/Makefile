all: testProgram

#Which compiler
CC = gcc

#Where to install
INSTDIR = /usr/local/bin

#temp dir for lib
LIBDIR = $(shell pwd)/lib

#Where are include files kept
INCLUDE = .

testProgram: libresistance.so testProgram.c
	$(CC) -o testProgram testProgram.c  -L$(LIBDIR) -lresistance -Wl,-rpath,$(LIBDIR)

lib: libresistance.so

libresistance.so: resistance.o
	@if [ ! -d $(LIBDIR) ];\
		then \
		mkdir $(LIBDIR);\
	fi
	$(CC) -shared -fPIC resistance.o -o $(LIBDIR)/libresistance.so

resistance.o: resistance.c resistance.h
	$(CC) -I$(INCLUDE) -fPIC -c resistance.c


clean:
	-@rm -Rf 2> /dev/null *.o ./lib testProgram


