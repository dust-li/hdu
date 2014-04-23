#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int N;
	scanf("%d",&N);
	while(N)
	{
		char **colors = (char **)malloc(sizeof(char *) * N);
		int *count = (int *)malloc(sizeof(int) * N);
		memset(count,0,sizeof(int)*N);
		char *temp = (char *)malloc(sizeof(char) * 20);
		int color_count = 0;
		int max = 0;
		int max_index;
		int i = 0,j = 0;
		for(i = 0;i < N;i++)
		{
			scanf("%s",temp);
			for(j = 0;j < color_count;j++)
			{
				if(0 == strcmp(temp,colors[j]))
				{
					count[j]++;
					if(count[j] > max){
						max_index = j;
						max = count[j];
					}
					break;
				}
			}
			if(j == color_count)
			{
				colors[color_count] = (char *)malloc(sizeof(char) * 20);
				strcpy(colors[color_count],temp);
				count[color_count]++;
				if(count[color_count] > max){
					max_index = color_count;
					max = count[color_count];
				}
				color_count++;
			}
		}
		scanf("%d",&N);
		//printf("count[max_index] = %d\n", count[max_index]);
		printf("%s\n", colors[max_index]);
	}
}