#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a,b,n;
	while(scanf("%d%d%d",&a,&b,&n) != EOF)
	{
		if(a == 0 && b == 0 && n == 0)
			break;
		//the max combination of 2 number under 7 is 7*7=49. so the max cycle < 49;
		int cycle;
		int farray[50];
		int i = 2;
		farray[0] = 1;
		farray[1] = 1;
		a %= 7;
		b %= 7;
		int flag = 0;
		int prefix;
		while(i < 50)
		{
			farray[i] = (a * farray[i - 1] + b * farray[i-2]) % 7;
//			printf("%d ", farray[i]);

			int j = i - 2;
			while(j > 0)
			{
				if(farray[i-1] == farray[j - 1] && farray[i] == farray[j])
				{
					cycle = i - j;
					prefix = j - 1;
					flag = 1;
					break;
				}
				j --;
			}
			if(flag)
				break;
			i++;
		}
		//printf("cycle = %d\n", cycle);
		printf("%d\n",farray[(n - 1 - prefix) % cycle + prefix]);
	}
}