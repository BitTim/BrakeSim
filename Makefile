CC = g++
CFLAGS = -std=c++17 -I"include" -L"lib" -Wall
LINKER = -lmingw32 -lSDL2main -lSDL2

build/out.exe: src/main.cc
	$(CC) $(CFLAGS) src/main.cc -o build/out.exe $(LINKER)

run: build/out.exe
	./build/out.exe

clean:
	rm build/*