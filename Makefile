CC = g++
INCLUDES = -I"include"
LIBS = -L"lib"
CFLAGS = -std=c++17 -Wall-Wl, -subsystem,windows
LFLAGS = -lmingw32 -lSDL2main -lSDL2

build/bin/out.exe: src/main.cc
	$(CC) $(INCLUDES) $(LIBS) $(CFLAGS) src/main.cc -o build/out.exe $(LFLAGS)

%.o: %.c
    $(CC) -c $(CFLAGS) $<

run: build/bin/out.exe
	./build/out.exe

clean:
	rm build/*
	mkdir build/bin/
	mkdir build/obj/