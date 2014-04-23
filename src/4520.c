#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct answer
{
    int best;
    struct answer *next;
};

double absolute(double average,double score)
{
    return (average - score) > 0 ? (average - score) : (score - average);
}

int main()
{
    int N;
    struct answer *ans_st,*head;
    ans_st = (struct answer *)malloc(sizeof(struct answer));
    memset(ans_st,0,sizeof(struct answer));
    head = ans_st;
    
    double pi,average;
    double *score;
    scanf("%d",&N);
    while(N != 0)
    {
        score = (double *)malloc(sizeof(double) * N);
        int i = 0;
        double sum = 0,minSub = 10.0;
        int minIndex,maxIndex;
        double minScore = 10,maxScore = 0;

        for(i = 0;i < N;i++)
        {
            scanf("%lf",&score[i]);
            if(score[i] > maxScore)
            {
                maxScore = score[i];
                maxIndex = i;
            }
            if(score[i] < minScore)
            {
                minScore = score[i];
                minIndex = i;
            }
//            printf("score = %lf\n",score[i]);
        }
//        printf("maxIndex = %d   minIndex = %d\n",maxIndex,minIndex);
        for(i = 0;i < N ;i++)
        {
            if((i != maxIndex) && (i != minIndex))
            {
//                printf("i = %d  ",i);
                sum += score[i];    
            }
        }
        average = sum / (N - 2);

//        printf("sum = %lf ,average = %lf\n",sum,average);
        for(i = 0;i < N ; i++)
        {
            if(minSub > absolute(average,score[i]))
            {
                minSub = absolute(average,score[i]);
                ans_st->best = i; 
            }
        }

        ans_st->next = (struct answer *)malloc(sizeof(struct answer));
        ans_st = ans_st->next;
        memset(ans_st,0,sizeof(struct answer));
        scanf("%d",&N);
    }
    ans_st = head;
    while(ans_st->next != NULL)
    {
        printf("%d\n",(ans_st->best)+1);
        ans_st = ans_st->next;
    }

}
