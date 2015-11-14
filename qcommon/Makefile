CFLAGS = -m32 -g

OBJECTS = cmd.o \
	cmodel.o \
	common.o \
	crc.o \
	cvar.o \
	files.o \
	m_flash.o \
	md4.o \
	net_chan.o \
	pmove.o \
	q_shared.o \

qcommon: $(OBJECTS)

clean:
	-rm *.a *~ $(OBJECTS)
