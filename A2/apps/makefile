maxchain :
	gcc -o max maxchain.c -lwordutils -ltrie
	./max

subwords :
	gcc -Wall -o sub subwords.c -lwordutils -ltrie
	./sub

clean :
	rm -f max sub

checkmaxchain :
	gcc -g -I../util -o maxchain maxchain.c -lwordutils -ltrie
	gdb ./maxchain
