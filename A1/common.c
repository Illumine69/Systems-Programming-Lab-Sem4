#include <stdio.h>
#include <stdlib.h>
#include "common.h"

void cmnprn(unsigned int n){
	unsigned int num = n;
	if(num == 0){
		printf("zero");
		return;
	}
	while(num > 0){
		if(num > 999){
			printf("big");
			return;
		}
		else if(num>99 && num<=999){
			unsigned int n_temp = num/100;
			switch(n_temp){
				case 1 : printf("one");
					 break;
				case 2 : printf("two");
					 break;
				case 3 : printf("three");
					 break;
				case 4 : printf("four");
					 break;
				case 5 : printf("five");
					 break;
				case 6 : printf("six");
					 break;
				case 7 : printf("seven");
					 break;
				case 8 : printf("eight");
					 break;
				case 9 : printf("nine");
					 break;
			}
			printf(" hundred");
			num = num % 100;
			if(num != 0){
				printf(" ");
			}
		}
		else if(num >= 20 && num <= 99){
			unsigned int n_temp = num/10;
			switch(n_temp){
				case 2 : printf("twenty");
					 break;
				case 3 : printf("thirty");
                                         break;
                                case 4 : printf("forty");
                                         break;
                                case 5 : printf("fifty");
                                         break;
                                case 6 : printf("sixty");
                                         break;
                                case 7 : printf("seventy");
                                         break;
                                case 8 : printf("eighty");
                                         break;
                                case 9 : printf("ninety");
                                         break;
			}
			num = num % 10;
			if(num!=0){
				printf(" ");
			}
		}
		else{
			switch(num){
				case 1 : printf("one");
					 break;
				case 2 : printf("two");
					 break;
				case 3 : printf("three");
                                         break;
                                case 4 : printf("four");
                                         break;
                                case 5 : printf("five");
                                         break;
                                case 6 : printf("six");
                                         break;
                                case 7 : printf("seven");
                                         break;
                                case 8 : printf("eight");
                                         break;
                                case 9 : printf("nine");
                                         break;
				case 10 : printf("ten");
                                          break;
                                case 11 : printf("eleven");
                                          break;
                                case 12 : printf("twelve");
                                          break;
                                case 13 : printf("thirteen");
                                          break;
                                case 14 : printf("fourteen");
                                          break;
                                case 15 : printf("fifteen");
                                          break;
                                case 16 : printf("sixteen");
                                          break;
				case 17 : printf("seventeen");
					  break;
				case 18 : printf("eighteen");
					  break;
				case 19 : printf("nineteen");
					  break;
			}
			num = 0;
		}
	}	
	return;
}
