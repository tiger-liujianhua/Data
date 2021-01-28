/*#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i, j;
	for (i = 1; i <= 9; i++)
	{
		for (j = 1; j <= 9; j++)
		{
			printf("%dx%d=%2d  ", i, j, i * j);

		}
		putchar('\n');
	}
	putchar('\n');
	//вСоб╫г
	for (i = 1; i <= 9; i++)
	{
		for (j = 1; j <= 9; j++)
		{
			if(i>=j)
			printf("%dx%d=%2d  ", i, j, i * j);

		}
		putchar('\n');
	}putchar('\n');
	//срио╫г
	for (i = 1; i <= 9; i++)
		{
		
			for (j = 1; j <= 9; j++)
			{
				if (i <= j)
					printf("%dx%d=%2d  ", i, j, i * j);
				else
					printf("        ");

			}
			putchar('\n');
			
		}putchar('\n');
		//вСио╫г
	for (i = 1; i <= 9; i++)
		{
		
			for (j = 1; j <= 9; j++)
			{
				if (i <= j)
					printf("%dx%d=%2d  ", i, j, i * j);
				
			}
			putchar('\n');
			
		}putchar('\n');
		//сроб╫г
	for (i = 1; i <= 9; i++)
			{
		for (int k = 1; k <= 9 - i; k++)
		{
			printf("        ");
		}
				for (j = 1; j <= 9; j++)
				{
					if (i >= j)
						printf("%dx%d=%2d  ", i, j, i * j);
				
				}
				putchar('\n');
			
			}putchar('\n');
	system("pause");
	return 0;

}*/