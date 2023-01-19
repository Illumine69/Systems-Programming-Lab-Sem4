# Name: Sanskar Mittal
# Roll no.: 21CS10057

1. Build the static library 
	gcc -Wall -c common.c bar.c foo.c
	ar rcs libnumprn.a common.o bar.o foo.o

2. Compile application program using the statc library
	gcc -Wall -L. app.c -lnumprn				//Un-INTERACTIVE mode
	gcc -Wall -L. app.c -DINTERACTIVE -lnumprn  //INTERACTIVE mode

3. Build the shared library
	gcc -Wall -fPIC -c common.c foo.c bar.c
	gcc -shared -o libnumprn.so common.o foo.o bar.o

4. Compile the application program using the shared library
	export LD_LIBRARY_PATH=~/A1
	gcc -Wall -L. app.c -lnumprn				//Un-INTERACTIVE mode
	gcc -Wall -L. app.c -DINTERACTIVE -lnumprn  //INTERACTIVE mode
