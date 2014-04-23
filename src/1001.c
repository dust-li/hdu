///  if the sequence is  5 -5 2 3 4
///  I should  output    9  1  5  instead of 9 3 5
///
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int T;
	scanf("%d",&T);
	int i = 0;
	int best_start,best_end;
	int start = 0,end = 0;
	int max;
	int sum = 0;
	int num;
	for(i = 0;i < T;i++)
	{
		scanf("%d",&num);
		int *a = (int *)malloc(sizeof(int) * num);
		int j = 0;
		for(j = 0;j < num;j++)
			scanf("%d",&a[j]);

		sum = 0;
		start = 0;
		end = 0;
		max = a[start];
		best_start = start;
		best_end = end;
		int start_flag = 0;
		while(end < num && a[end] <= 0){
			if(a[end] > max)
			{
				max = a[end];
				best_end = end;
				best_start = end;
			}
			end++;
		}
		if(end < num && a[end] > 0){
			start = end;
			start_flag = 1;
		}
		while(start > 0 && a[start-1] == 0)
			start--;
		while(end < num && a[end] >= 0)
			sum += a[end++];
		if(start_flag)
		{
			max = sum;
			best_start = start;
			best_end = end;
			while(a[best_end - 1] == 0)
				best_end--;
			best_end --;
		}

		while(end < num)
		{
			while(end < num && a[end] <= 0)
				sum += a[end++];
			if(sum < 0)
			{
				start = end;
				sum = 0;
				while(a[start] >= 0)
					start--;
				start++;
			}
			while(end < num && a[end] >= 0)
				sum += a[end++];
			if(sum > max)
			{
				max = sum;
				best_start = start;
				best_end = end;
				while(a[best_end - 1] == 0)
					best_end--;
				best_end --;
			}
		}


		printf("Case %d:\n", i+1);
		printf("%d %d %d\n", max,best_start + 1,best_end + 1);
//		printf("best_start = %d   best_end = %d\n", best_start,best_end);
//		printf("a[best_start-1] = %d, a[best_end-1] = %d\n", a[best_start-1],a[best_end-1]);
		if(i != T-1)
			printf("\n");
	}
}