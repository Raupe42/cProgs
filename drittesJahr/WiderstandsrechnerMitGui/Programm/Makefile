ZIEL=eigenesUI2
# GTKVERSION=gtk+-2.0
GTKVERSION=gtk+-3.0
CFLAGS=`pkg-config --cflags --libs $(GTKVERSION)` #-rdynamic

$(ZIEL): $(ZIEL).c #*.ui

	gcc $(CFLAGS) $(ZIEL).c $(CFLAGS)

run: $(ZIEL)
	./$(ZIEL)

clean:
	rm *~ a.out