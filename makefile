all: signals.c
	gcc signals.c -o sigtest 

run: sigtest
	./sigtest

clean:
	rm ./sigtest
	rm *~