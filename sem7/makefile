
DEPS=main.o studenci.o dziekanat.o

# main: clean $(DEPS)
main: $(DEPS)
	cc $(DEPS) -o $@ -Wall --pedantic

%.o:%.c
	cc -c $^ -o $@

#main.o:main.c
#	cc -c $^ -o $@

#main_dodaj.o:main_dodaj.c
#	cc -c $^ -o $@

#main_liczydlo.o:main_liczydlo.c
#	cc -c $^ -o $@

clean:
	rm -f main
	rm -f *.o

test: main
	./main studenci.txt najlepszy_student

test2: main
	./main studenci.txt najtrudniejszy_przedmiot

test3: main
	./main studenci.txt najlatwiejszy_przedmiot
