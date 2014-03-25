analysis:main.o analysis.o
	gcc -o analysis main.o analysis.o
main.o:main.c include.h
	gcc -c main.c -I./
analysis.o:analysis.c include.h
	gcc -c analysis.c -I./
clean:
	rm -rf *.o analysis
