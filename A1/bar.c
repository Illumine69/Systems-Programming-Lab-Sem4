#include <stdio.h>
#include <stdlib.h>
#include "bar.h"
#include "common.h"

void barprn(unsigned int n){

	unsigned int num = n;
	if(num == 0){
		printf("zero");
		return;
	}
	while(num>0){
		if(num >= 10000000){
			cmnprn(num/10000000);
			printf(" crore");
			num = num % 10000000;
			if(num != 0){
				printf(" ");
			}
		}
		else if(num >= 100000 && num < 10000000){
			cmnprn(num/100000);
			printf(" lakh");
			num = num % 100000;
			if(num != 0){
				printf(" ");
			}
		}
		else if(num >= 1000 && num < 100000){
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
