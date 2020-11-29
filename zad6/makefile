
DEPS=zzzzad3.o zapis.o dzialania.o

# main: clean $(DEPS)
main: $(DEPS)
	cc $(DEPS) -o $@ -Wall --pedantic -lm

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

sum: main
	./main sum A.txt B.txt
