#File format
FFORMAT = win32
all:
	nasm readtsc.asm -o readtsc.o -f${FFORMAT}
test: 
	g++ -c tests.cpp -o tests.o
	g++ -o test.exe tests.o readtsc.o
	echo Running Tests...
	test
clean:
	rm *.o
	rm *.exe