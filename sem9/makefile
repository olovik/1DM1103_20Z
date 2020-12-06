all:
	cc baza.c main.c -o mydb -Wall --pedantic

test: all
	./mydb baza.csv list_students

test-ile: all
	./mydb baza.csv count_students

test-memory: all
	valgrind ./mydb baza.csv count_students

dodajs: all
	valgrind -s ./mydb baza.csv add_student Wojciech Pachulski 231001 nic@gmail.com

dodajp: all
	valgrind -s ./mydb baza.csv add_course 1DE2103 "Metody numeryczne" 2020Z

dodajs2: all
	valgrind -s ./mydb baza.csv add_student Szymon Pachulski 231003 nic2@gmail.com
