#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "bar.h"
#include "foo.h"
#include <time.h>

int main(){
	unsigned int n;
	#ifdef INTERACTIVE
	printf("Enter n: ");
	scanf("%u",&n);
	printf("\n");
	#else
	srand(time(0));
	n = rand() % 4294967296;
	#endif
	while(n >= 0){

		printf("%u\n",n);
		printf("foo: \"");
		fooprn(n);
		printf("\"\n");

		printf("bar: \"");
		barprn(n);
		printf("\"\n\n");
		 
		if(n==0){
			break;
		}

		n = n/10;
	}
	return 0;
}
