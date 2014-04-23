#include <stdio.h>
#include <stdlib.h>
#include <string.h>

inline char int2char(int i)
{
    return i + '0';
}

inline int char2int(char c)
{
    if(c == 0)
        return 0;
    return c - '0';
}


int main(void)
{
    char (*a)[1000],(*b)[1000],(*c)[1100];
    char sum;
    int T,i = 0,j = 0;
    scanf("%d",&T);
    c = (char (*)[1100])malloc(sizeof(char) * 1100 * T);
    a = (char (*)[1000])malloc(sizeof(char) * 1000 * T);
    b = (char (*)[1000])malloc(sizeof(char) * 1000 * T);

    for(i = 0 ;i < T;i++)
    {
        memset(a[i],0,sizeof(a[i]));
        memset(b[i],0,sizeof(b[i]));
        memset(c[i],0,sizeof(c[i]));

        scanf("%s",a[i]);
        scanf("%s",b[i]);

        int len_a,len_b;
        len_a = strlen(a[i]);
        len_b = strlen(b[i]);
        int carry = 0;
        j = 0;
        while(len_a > j || len_b > j)
        {
            if(j < len_a && j < len_b)
                c[i][j] = char2int(a[i][len_a -1 - j]) + char2int(b[i][len_b -1 - j]) + carry;
            else if(j < len_b && j >= len_a)
                c[i][j] = char2int(b[i][len_b -1 - j]) + carry;
            else if(j < len_a && j >= len_b)
                c[i][j] = char2int(a[i][len_a -1 - j]) + carry;
            else
                break;
            carry = c[i][j] / 10;
            c[i][j] = c[i][j] % 10;
            c[i][j] = int2char(c[i][j]);
            j++;
        }
         if(carry)
             c[i][j] = int2char(carry);
    }
    for(i = 0;i < T ;i++)
    {
         printf("Case %d:\n", i+1);
         printf("%s + %s = ", a[i],b[i]);

         for(j = strlen(c[i]) - 1;j >= 0;j--)
             printf("%c", c[i][j]);
         if(i != T -1)
             printf("\n");
         printf("\n");
    }
    free(a);
    free(b);
    free(c);
}
