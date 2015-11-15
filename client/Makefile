CFLAGS = -m32 -g

OBJECTS = cl_cin.o	\
	cl_fx.o		\
	cl_inv.o	\
	cl_newfx.o	\
	cl_pred.o	\
	cl_tent.o	\
	console.o	\
	menu.o		\
	snd_dma.o	\
	snd_mix.o	\
	cl_ents.o	\
	cl_input.o	\
	cl_main.o	\
	cl_parse.o	\
	cl_scrn.o	\
	cl_view.o	\
	keys.o		\
	qmenu.o		\
	snd_mem.o	\


lib: libclient.a($(OBJECTS))

clean:
	-rm -rf *~ *.a

