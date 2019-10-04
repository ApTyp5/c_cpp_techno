CC := gcc
CLF := -Wall -Werror -std=c99 -pedantic
OBJ := main.o


ifeq ($(mod),db)
	CFL += -O0 -g3
else
	CFL += -O3 -g0
endif




app.exe: $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFL) -c $< 

clean:
	$(RM) *.exe *.o

