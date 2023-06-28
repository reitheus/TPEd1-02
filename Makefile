all: main.o labirinto.o percurso.o posicao.o
	@gcc main.o labirinto.o percurso.o posicao.o -o exe
	rm -r *.o
main.o: main.c
	@gcc main.c -c -Wall
labirinto.o: labirinto.c
	@gcc labirinto.c -c -Wall
percurso.o: percurso.c
	@gcc percurso.c -c -Wall
posicao.o: posicao.c
	@gcc posicao.c -c -Wall
run:
	@./exe
