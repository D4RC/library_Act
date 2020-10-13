# Makefile library
CFLAGS=-Wall -I.

# a1 estatica a2 dinamica
all: a1 a2

a1: main.o liblibreria1.a
	cc -o a1 $(CFLAGS) main.o -L. -llibreria1

a2: main.o liblibreria1.so
	cc -o a2 $(CFLAGS) main.o -L. -Bdynamic -llibreria1

# Dependencias de la librería estática. La construcción se hace con la
# regla implicita de make.
liblibreria1.a: liblibreria1.a(print.o sum.o multiply.o)

# Construción de la librería dinámica.
liblibreria1.so: print.c sum.c multiply.c
	cc $(CFLAGS) -c -o print.o print.c
	cc $(CFLAGS) -c -o sum.o sum.c
	cc $(CFLAGS) -c -o multiply.o multiply.c
	ld -o liblibreria1.so print.o sum.o multiply.o -shared
	rm print.o sum.o multiply.o