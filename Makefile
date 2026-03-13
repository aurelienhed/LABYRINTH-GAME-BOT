# Modèle de fichier Makefile, à adapter pour le TP

# options de compilation
CC = gcc
CCFLAGS = -Wall -g #-O0 -fsanitize=address -fsanitize=undefined #-fsanitize=leak 
LIBS = 
LIBSDIR = 

# fichiers du projet
SRC = main.c labyrinthAPI.c clientAPI.c
OBJ = $(SRC:.c=.o)
EXEC = main


# règle initiale
all: $(EXEC)

# dépendance des .h
clientAPI.o: clientAPI.h
labyrinthAPI.o: labyrinthAPI.h
# règles de compilation
%.o: %.c
	$(CC) $(CCFLAGS) -o $@ -c $<
	
# règles d'édition de liens
$(EXEC): $(OBJ)
	$(CC) $(CCFLAGS) -o $@ $^ $(LIBS) $(LIBSDIR)

# règles supplémentaires
clean:
	rm -f *.o
mproper:
	rm -f $(EXEC) *.o