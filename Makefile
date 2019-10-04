CC := gcc
CFL := -Wall -Werror -std=c99 -pedantic
OBJ := proc_tools.o io_tools.o
COBJ := main.o $(OBJ) 
TOBJ := test_main.o $(OBJ)



ifeq ($(mod),db)
	CFL += -O0 -g3
else
	CFL += -O3 -g0
endif


sun_tests: test.exe
	./run_pos_tests.sh
	$(RM) *.deleteme

test.exe: $(TOBJ)
	$(CC) -o $@ $^

app.exe: $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFL) $(OGFL) -c $< 

clean:
	$(RM) *.exe *.o

