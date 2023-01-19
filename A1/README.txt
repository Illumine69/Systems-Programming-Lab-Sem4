Name: Sanskar Mittal
Roll no.: 21CS10057

(i)
	gcc -Wall -c common.c bar.c foo.c
	ar rcs libnumprn.a common.o bar.o foo.o

(ii)
	gcc -Wall -L. app.c -lnumprn (Un-INTERACTIVE mode)
	gcc -Wall -L. app.c -DINTERACTIVE -lnumprn (INTERACTIVE mode)

(iii)
	gcc -Wall -fPIC -c common.c foo.c bar.c
	gcc -shared -o libnumprn.so common.o foo.o bar.o
(iv)
	export LD_LIBRARY_PATH=~/A1
	gcc -Wall -L. app.c -lnumprn (Un-INTERACTIVE mode)
	gcc -Wall -L. app.c -DINTERACTIVE -lnumprn (INTERACTIVE mode)
