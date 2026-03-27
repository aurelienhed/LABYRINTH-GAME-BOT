# Modèle de fichier Makefile, à adapter pour le TP

# options de compilation
CC = gcc
CCFLAGS = -Wall -g #-O0 -fsanitize=address -fsanitize=undefined #-fsanitize=leak 
LIBS = 
LIBSDIR = 

# fichiers du projet
SRC = main.c APIS/labyrinthAPI.c APIS/clientAPI.c Data/data.c
OBJ = $(SRC:.c=.o)
EXEC = main


# règle initiale
all: $(EXEC)

# dépendance des .h
clientAPI.o: APIS/clientAPI.h
labyrinthAPI.o: APIS/labyrinthAPI.h
data.o: Data/data.h
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
	rm -f APIS/*.o