all: posicao.o percurso.o fila.o pilha.o labirinto.o main.o
	@gcc posicao.o percurso.o fila.o pilha.o labirinto.o main.o -o exe
	@rm -r *.o
posicao.o: posicao.c
	@gcc posicao.c -c -Wall
percurso.o: percurso.c
	@gcc percurso.c -c -Wall
fila.o: fila.c
	@gcc fila.c -c -Wall
pilha.o: pilha.c
	@gcc pilha.c -c -Wall
labirinto.o: labirinto.c
	@gcc labirinto.c -c -Wall
main.o: main.c
	@gcc main.c -c -Wall
run:
	@./exe
