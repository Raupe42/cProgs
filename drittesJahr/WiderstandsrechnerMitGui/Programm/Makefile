ZIEL=Widerstandsrechner
# GTKVERSION=gtk+-2.0
GTKVERSION=gtk+-3.0
CFLAGS=`pkg-config --cflags --libs $(GTKVERSION)` #-rdynamic

$(ZIEL): $(ZIEL).c #*.ui

	gcc -o Widerstandsrechner *.c $(CFLAGS)

run: $(ZIEL)
	Widerstandsrechner.exe

clean:
	rm *~ a.out