CFLAGS=-Dstricmp=strcasecmp -m32 -g -O0

OBJECTS = \
	net_udp.o \
	sys_solaris.o \
	in_solaris.o \
	cd_solaris.o \
	in_solaris.o \
	snddma_solaris.o \
	swimp_solaris.o \
	sys_solaris.o \
	vid_solaris.o \

all: $(OBJECTS)

lib: libsolaris.a($(OBJECTS))

clean:
	-rm -rf *.o *~
