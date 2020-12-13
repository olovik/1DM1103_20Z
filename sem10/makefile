all:
	cc baza.c main.c -o mydb -Wall --pedantic

test: all
	./mydb baza.csv list_students

test-ile: all
	./mydb baza.csv count_students

test-memory: all
	valgrind ./mydb baza.csv count_students

dodajs: all
	valgrind -s ./mydb baza.csv add_student Adrian Zackiewicz 231001 nic@gmail.com

dodajp: all
	valgrind -s ./mydb baza.csv add_course 1DE2103 "Metody numeryczne" 2020Z

dodajs2: all
	valgrind -s ./mydb baza.csv add_student Borys Syty 231003 nic2@gmail.com

ssortmal: all
	valgrind -s ./mydb baza.csv sort_descending

ssortros: all
	valgrind -s ./mydb baza.csv sort_ascending

psortrosk: all
	valgrind -s ./mydb baza.csv sort_by_code_ascending

psortmal: all
	valgrind -s ./mydb baza.csv sort_by_name_descending

psortros: all
	valgrind -s ./mydb baza.csv sort_by_name_ascending

filtroce: all
	valgrind -s ./mydb baza.csv szukaj_ocen 1DA1245