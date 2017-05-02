CFLAGS = -m32 -g -Wall

OBJECTS = sv_ccmds.o \
	sv_ents.o \
	sv_game.o \
	sv_init.o \
	sv_main.o \
	sv_send.o \
	sv_user.o \
	sv_world.o \

lib: libserver.a($(OBJECTS))

clean:
	-rm -rf $(OBJECTS) *~ *.a
