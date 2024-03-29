
#include "exercise.h"
//void printArr( void * v[], int size);

void qsort (void * v[], int left, int right, int (*comp)(void *, void*), int reverse)
{
    //int size = (sizeof(v));
    int i, last;
    void swap(void *v[], int, int);
    
    if (left >= right)                  /* do nothing if array contains */
        return;                         /* fewer than two elements */
    
    swap(v, left, (left + right)/2);    /* get pivot*/

    last = left;
    
    for (i = left + 1; i <= right; i++)
        if(reverse)
        {    if((*comp)(v[i],  v[left]) > 0 )
                swap(v, ++last, i);
        }
        else
        {
            if((*comp)(v[i], v[left]) < 0 )
                swap(v, ++last, i);
        }

    swap(v, left, last);
    qsort(v, left, last -1, comp, reverse);
    qsort(v, last+1, right, comp, reverse);
}

int numcmp (char * s1, char * s2)
{
    double v1, v2;
    v1 = atof(s1);
    v2 = atof(s2);
    return (v1 - v2);
}

void swap (void * v[], int i, int j)
{
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}