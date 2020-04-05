MPICC = mpicc -Wall
RM = rm -i
TAR = tar -cvzf
srcdir = ./src/
bindir = ./bin/
SRC = $(wildcard $(srcdir)*.c)
HEAD = $(wildcard $(srcdir)*.h)
SRCP = $(wildcard $(srcdir)*)
OBJ = $(subst $(srcdir), $(bindir), $(SRC:.c=.o))
PROG = main

all : $(PROG)

$(PROG) : $(OBJ)
	$(MPICC) $(OBJ) -o $(PROG)

./bin/%.o : ./src/%.c
	$(MPICC) -c $^ -o $@

.PHONY : clean

clean :
	$(RM) $(OBJ)

.PHONY : give

give :
	$(TAR)
