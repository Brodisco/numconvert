/*
 * numconvert.c
 *
 *  Created on: 29.10.2022
 *      Author: student
 */


/*
 * numconvert.c
 *
 *  Created on: 29.10.2022
 *      Author: student
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>

int validHexImput(char c)
{
	char *hex = "0123456789ABCDEF";

	int ret = 0;

	for (int i = 0; i < 16; i++)
	{
		if (c == hex[i])
		{
			ret = 1;
		}
	}

	return ret;
}

int convertHexToDec(int c)
{
	int ret = 0;
	if (c >= 48 && c <= 57)
	{
		ret = 0 + c - 48;
	}else{
		ret = 10 + c - 65;
	}

	return ret;
}

unsigned long importHexNumber(void)
{

	char string[16];
	scanf("%s", string);

	unsigned long decimal = 0;

	int stringleangh = strlen(string);

	int exp = 0;

	for (int i = (stringleangh - 1); i >= 0; i--)
	{

		printf("%d: %c ",i , string[i]);

		if (validHexImput(string[i]) == 1)
		{
			decimal += convertHexToDec(string[i]) * pow(16, exp++);
		}

		printf("\n");
	}



	printf("-> %ld  \n", decimal);

	return decimal;

}



int main(void)
{
	//printf("%b", importHexNumber());

	//long zahl1 = 0b11000111;
	//long zahl2 = 0b00001011;
	unsigned long zahl1 = 25;
	unsigned long zahl2 = 12;
			//	0b00000010

			//  0b00000010
			//  0b00000010
	unsigned long mask;
	unsigned long res;

	printf("%064b \n", zahl1);

	printf("%064b \n", zahl2);

	int ubertrag = 0;

	for (long i = 0; i < (8 * sizeof(long)); i++)
	{
		mask = (1<<i);
		if( !((zahl1 & mask) ^ (zahl2 & mask)) && ubertrag == 1 && (zahl1 & mask) >= 1  &&  (zahl2 & mask) >= 1 )
		{
			printf("True \n");
			res = res | (1<<i);
			ubertrag = 1;
		}
		else if(!((zahl1 & mask) ^ (zahl2 & mask)) && ubertrag == 0 && (zahl1 & mask) >= 1  &&  (zahl2 & mask) >= 1 )
		{
			printf("False \n");
			res = res | (0<<i);
			ubertrag = 1;
		}
		else if(((zahl1 & mask) ^ (zahl2 & mask)) && ubertrag == 1)
		{
			printf("False \n");
			res = res | (0<<i);
			ubertrag = 1;
		}
		else if(((zahl1 & mask) ^ (zahl2 & mask)) && ubertrag == 0)
		{
			printf("Bit: %d True %d %d \n",i,  (zahl1 & mask), (zahl2 & mask));
			res = res | (1<<i);
			ubertrag = 0;
		}
		else if( !((zahl1 & mask) ^ (zahl2 & mask)) && ubertrag == 1 && (zahl1 & mask) == 0  &&  (zahl2 & mask) == 0 )
		{
			printf("True \n");
			res = res | (1<<i);
			ubertrag = 0;
		}
		else{
			printf("False \n");
			res = res | (0<<i);
			ubertrag = 0;
		}
	}

	//          0b00000010
	printf("\n %064b %d \n", res, res);

	//int zahl3 = zahl1 ^ zahl2;

	//printf("%d", zahl3);

	return EXIT_SUCCESS;
}


