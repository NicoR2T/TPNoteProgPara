CC = gcc -Wall
RM = rm -i
CP = cp
TCH = touch
TAR = tar -cvzf
readme = README
srcdir = ./src/
bindir = ./bin/
docdir = ./doc/
savedir = ./save/
SAV = $(wildcard $(savedir)*)
SRC = $(wildcard $(srcdir)*.c)
HEAD = $(wildcard $(srcdir)*.h)
SRCP = $(wildcard $(srcdir)*)
OBJ = $(subst $(srcdir), $(bindir), $(SRC:.c=.o))
PROG = main

all : $(PROG)

$(PROG) : $(OBJ)
	$(CC) $(OBJ) -o $(PROG)

./bin/%.o : ./src/%.c
	$(CC) -c $^ -o $@

.PHONY : save

save :
	$(CP) $(SRCP) $(savedir)

.PHONY : clean

clean :
	$(RM) $(OBJ)

.PHONY : doc

doc :
	$(TCH) $(docdir)$(readme)

.PHONY : restore

restore :
	$(CP) $(SAV) $(srcdir)

.PHONY : give

give :
	$(TAR) ../tirel_nicolas.tgz ./
