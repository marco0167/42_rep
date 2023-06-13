/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int numero = 0;

pthread_mutex_t mutex;

void    *process(void *arg)
{
    int num = *(int *)arg;
    int *result = malloc(sizeof(int));

    *result = num;
    int i;
    for (i = 0; i < 10000000; i++)
    {
        pthread_mutex_lock(&mutex);
        numero++;
        pthread_mutex_unlock(&mutex);
    }

    printf("Thread %d\n", num);
    return ((void *) result);
}

int main()
{
    pthread_t   th[2];
    int i;

    int *res;

    pthread_mutex_init(&mutex, NULL);

    for (i = 0; i < 2; i++)
    {
        int *num = malloc(sizeof(int));
        *num = i;
        if (pthread_create(&th[i], NULL, &process, num) != 0)
        {
            return (1);
        }
    }

    for (i = 0; i < 2; i++)
    {
        if(pthread_join(th[i], (void **) &res) != 0)
        {
            return (1);
        }
        printf("result %d\n", *res);
    }

    pthread_mutex_destroy(&mutex);
    printf("NUMERO %d\n", numero);

    return 0;
}
