CFLAGS = -m32 -KPIC
SHLDFLAGS = -shared

OBJECTS = r_aclip.o \
	  r_alias.o \
	  r_bsp.o \
	  r_draw.o \
	  r_edge.o \
	  r_image.o \
	  r_light.o \
	  r_main.o \
	  r_misc.o \
	  r_model.o \
	  r_part.o \
	  r_poly.o \
	  r_polyse.o \
	  r_rast.o \
	  r_scan.o \
	  r_sprite.o \
	  r_surf.o \

ref_soft.so: $(OBJECTS)
	$(CC) $(SHLDFLAGS) $(OBJECTS) -o $@

clean:
	-rm *.o *~
