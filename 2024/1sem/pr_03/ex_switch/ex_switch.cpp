#include<stdio.h>
int main()
{
	int k;
	printf("Vvedite nomer vashey karti\n ");
	scanf_s("%d", &k);
	printf("Pozdravlyau!!! \n");
	switch (k)
	{
		case 6: 
			printf("U vas 6-ka\n "); break;
		case 7: 
			printf("U vas 7-ka\n "); break;
		case 8: 
			printf("U vas 8 - ka\n "); break;
		case 9: 
			printf("U vas 9-ka\n "); break;
		case 10: 
			printf("U vas 10-ka\n "); break;
		case 11: 
			printf("U vas Valet\n "); break;
		case 12: 
			printf("U vas Dama\n "); break;
		case 13: 
			printf("U vas Korol\n "); break;
		case 14: 
			printf("U vas Tuz\n "); break;
		default: 
			printf("Neverniy vvod nomera\n ");
	}
	return 0;
}
