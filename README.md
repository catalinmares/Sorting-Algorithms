Proiectul contine urmatoarele fisiere si directoare:
* *algo.h* - Header-ul in care sunt scrise antetele celor 3 functii de 
				 sortare pentru cei 3 algoritmi
* *algo.cpp* - Contine implementarea pentru Heap Sort, realizata de mine pe
	               baza algoritmului prezentat la curs de Traian
* *algo2.cpp* - Contine implementarea pentru Counting Sort, realizata 
	                pornind de la algoritmii prezentati in sursele [0] si [1]
* *algo3.cpp* - Contine implementarea pentru Tree Sort, realizata pornind 
	                de la algoritmii prezentati in sursele [2] si [3]
* *Makefile* - Contine reguli de build pentru fiecare algoritm (build-heap,
				   build-count, build-tree) si pentru generatorul de teste 
				   (make test), de run (run pentru rularea algoritmilor si 
				   run-test pentru rularea generatorului de teste) si clean 
				   pentru stergerea executabilelor, a fisierelor obiect si a 
				   fisierelor de test
* *in/* - Contine fisierele de intrare pentru fiecare test (test0.in, 
			  test1.in, ...) - acestea sunt generate de fiecare data prin 
		  rularea comenzilor make test si make run-test
* *out/* - Contine fisierele de iesire in urma rularii testelor pe un 
	           algoritm anume
* *ref/* - Contine fisierele de referinta pentru fiecare test. Astfel, in 
			   main se citeste din fisierul de intrare (testX.in), se aplica 
			   algoritmul de sortare si se scrie in fisierul de iesire 
			   rezultatul obtinut (testX.out) si in acelasi timp se testeaza 
			   corectitudinea prin compararea continutului fisierului de iesire 
			   cu cel de referinta
* *testbuilder.cpp* - Contine implementarea generatorului de teste. Acesta 
						  genereaza atat fisierele de intrare, cat si cele de 
						  referinta
* *includes/* - Contine header-ele folosite in compilarea fisierelor sursa
* *utils1.h* - Header-ul in care sunt implementate functiile auxiliare 
				   folosite de algoritmul Heap Sort
* *utils2.h* - Header-ul in care sunt implementate functiile auxiliare 
				   folosite de algoritmulTree Sort
						  
						  
**Utilizare Makefile**

Pentru rularea algoritmilor pe setul de teste procedam astfel:

*make test* (pentru generarea executabilului generatorului de teste)

*make build-heap / build-count / build-tree* (pentru generarea executabilului 
										   checkerului)
*make run* (pentru rularea checkerului)

*make clean* (pentru stergerea executabilelor, fisierelor obiect, respectiv a 
		   fisierelor de test)


**Descriere teste**
* Test 0 - Vectorul contine acelasi element de 100 de ori
* Test 1 - Vectorul contine 100 de elemente deja sortate
* Test 2 - Vectorul contine 10 elemente dintr-un interval foarte mare
* Test 3 - Vectorul contine 100 de elemente dintr-un interval restrans
* Test 4 - Vectorul contine 100 de elemente sortate descrescator
* Test 5 - Vectorul contine 100 de elemente generate random
* Test 6 - Vectorul contine 5000 de elemente partial sortate pe alocuri
				 si generate random pe alocuri

**Surse**

[0] - https://www.reddit.com/r/learnprogramming/comments/66nngq/algorithms_counting_sort_for_negative_numbers_java/
	- data ultimei accesari: 02.12.2018, 01:16
	
[1] - https://www.geeksforgeeks.org/counting-sort/
	- data ultimei accesari: 02.12.2018, 01:17
	
[2] - https://www.geeksforgeeks.org/tree-sort/
	- data ultimei accesari: 02.12.2018, 01:18
	
[3] - http://www.cplusplus.com/forum/beginner/179430/
	- data ultimei accesari: 02.12.2018, 01:19
