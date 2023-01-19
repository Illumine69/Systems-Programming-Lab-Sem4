#include <stdio.h>
#include <stdlib.h>
#include "foo.h"
#include "common.h"

void fooprn(unsigned int n){
	unsigned int num = n;
	if(num == 0){
		printf("zero");
		return;
	}
	while(num>0){
		if(num >= 1000000000){
			unsigned int n_temp = num/1000000000;
			switch(n_temp){
				case 1 : printf("one");
					 break;
				case 2 : printf("two");
					 break;
				case 3 : printf("three");
					 break;
   				case 4 : printf("four");
					 break;
			}
			printf(" billion");
			num = num % 1000000000;
			if(num != 0){
				printf(" ");
			}
		}
		else if(num >= 1000000 && num < 1000000000){
			cmnprn(num/1000000);
			printf(" million");
			num = num % 1000000;
			if(num != 0){
				printf(" ");
			}
		}
		else if(num >= 1000 && num < 1000000){
			cmnprn(num/1000);
			printf(" thousand");
			num = num % 1000;
			if(num != 0){
				printf(" ");
			}
		}
		else{
			cmnprn(num);
			num = 0;
		}
	}	
	return;
}
