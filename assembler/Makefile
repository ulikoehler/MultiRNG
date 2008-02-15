#File format
FFORMAT = win32
COPTIONS = 

ifdef DEBUG
	COPTIONS += -g
else
	COPTIONS += -O3 -fomit-frame-pointer
endif	
all:
	nasm readtsc.asm -o readtsc.o -f${FFORMAT}
test: 
	g++ -c tests.cpp -o tests.o $(COPTIONS)
	g++ -o test.exe tests.o readtsc.o $(COPTIONS)
	echo Running Tests...
	./test
clean:
	rm *.o
	rm *.exe