progs: solitaire


solitaire: solitaire solitaire.o graphics.o cards.o
	gcc -o solitaire solitaire.o cards.o graphics.o -lpg

solitaire.c: solitaire.c cards.c graphics.c
	gcc -Wall -c solitaire.c cards.c graphics.c -lpg


graphics.o: graphics.c
	gcc -Wall -c graphics.c -lpg


cards.o: cards.c
	gcc -Wall -c cards.c -lpg
	
