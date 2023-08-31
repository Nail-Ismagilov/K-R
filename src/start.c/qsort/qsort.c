// Online C compiler to run C program online
#include <stdio.h>

void print_arr(int v[], int intSize);

// init Array
int arr[] = {3,2, 4,1};
//Size of Array
int intSize = ((sizeof(arr))/sizeof(int)) - 1;

int main() {
    
    
    
    // Print array before sort
    print_arr(arr, intSize);
    
    // Quicksort
    printf("\nSTART QSORT\n");
    qsort(arr, 0, intSize);
    
    // Print Array after Sort
    printf("\nArray after Sort:\n");
    print_arr(arr, intSize);
    return 0;
}


void qsort (int v[], int left, int right)
{

    int i, last = 0;
    static count = 0;
    void swap(int v[], int, int);
    printf("Parameteres in qsort:\n");
    printf("     left:  =  %d\n", left);
    printf("     right: =  %d\n", right);
    printf("     count: =  %d\n", count);
    
    printf("sorting array: ");
    print_arr(v, right);
    printf("\n");
    
    if (left >= right)
        return;
    printf("!!!!!!!!! start sort !!!!!!!!!\n");
    
    swap(v, left, (left + right)/2);
    
    
    printf("    array after swap left, (left + right)/2: ");
    print_arr(v, right);
    
    
    last = left;
    
    for (i = left + 1; i <= right; i++)
    {
        
        if (v[i] < v[left]){
                printf("\n    ############# SWAP_IN #############\n");
                swap(v, ++last, i);
                printf("    arr: ");
                print_arr(v, right);
                printf("    ############# SWAP_OUT ############\n");
        }
    }

    count++;

    printf("Parameteres in qsort:\n");
    printf("     left:  =  %d\n", left);
    printf("     right: =  %d\n", right);
    printf("     last: =  %d\n", last);
    printf("     swap v[%d] and v[%d]\n", left, last);

    swap(v, left, last);

    printf("!!!!!!!!! end sort !!!!!!!!!\n");
    printf("\n");
    printf("array after sort: ");
    print_arr(v, right);
    printf("Parameteres in qsort:\n");
    printf("     left:  =  %d\n", left);
    printf("     right: =  %d\n", right);
    printf("     last:  =  %d\n\n", last);
    printf("*****************end of function*****************\n\n");

    qsort(v, left, last -1);
    qsort(v, last+1, right);
}


void print_arr(int v[], int intSize)
{
    printf("[");
    for (int i = 0; i <= intSize; i++)
    {   if (i != intSize)
            printf("%3d,", (v[i]));
        else
            printf("%3d", (v[i]));
    }
    printf("]\n");
}

void swap(int v[], int a, int b)
{
    //printf("swap last: %d\nswap i: %d\n", a,b);
    print_swap_sort(v,a,b);
    int temp;
    temp = *(v+a);
    *(v+a) = *(v+b);
    *(v+b) = temp;
}

void print_swap_sort(int v[], int a, int b)
{

    print_gui(a);
    printf(" v[a]\n");
    print_gui(a);
    printf("   |\n    ");
    
    print_arr(v, intSize);
    
    print_gui(b);
    printf("   |\n");
    print_gui(b);
    printf(" v[b]\n\n");
    
}

void print_gui(int a)
{
    printf("    ");
    for(int i = 0; i < a; i++)
            printf("    ");
}