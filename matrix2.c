#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void InputArray(float **a, int size);
void OutputArray(float **a, int size);
void Function3(float **a,int size);
int main(int argc, char *argv[]) {
	printf("---------------------------------\n");
	printf("-------------Lab10---------------\n");
	printf("---------------------------------\n");
	float **a = NULL;
	int size;
    int i;
    printf("+Size = ");
    scanf("%d", &size);
    // Cap phát mang các con tro cap 1
    a = (float **)malloc(size * sizeof(int *));
    for (i = 0; i < size; i++)
    {
        // Cap phát cho tung con tro cap 1
        a[i] = (float *)malloc(size * sizeof(int));
    }
    InputArray(a, size);
    OutputArray(a, size);
    Function3(a,size);
    // giai phóng tung hàng
    for (i = 0; i < size; i++)
    {
        free(a[i]);
    }
    // giai phong con tro quan lý các dòng
    free(a);
	return 0;
}
void InputArray(float **a, int size)
{
    int i, j;
    srand(time(NULL));
    for (i = 0; i < size; i++)
        for (j = 0; j < size; j++)
        {
        printf("A[%d][%d] = ", i, j);
         scanf("%f", &a[i][j]);
        }
}
void OutputArray(float **a, int size)
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        printf("%5.2f", a[i][j]);
        printf("\n");
    }
}
void Function3(float **a,int size)
{
	int i,j;
	float d[size];
	for ( i = 0; i < size; i++)
    {
        for ( j = 0; j < size; j++)
        {
            if (i == j) 
			d[i] = a[i][j];  
        }
    }
    float sum = 0;
    for ( i = 0; i < size; i++) 
	 {
	 	sum += d[i];
	 }
 
    for ( i = 0; i < size; i++)
    {
        for ( j = 0; j < size; j++)
        {
            if ((i+1)%2 == 0) 
			a[i][j] /= sum;
        }
    }
    printf("\nMatrix : \n");
     for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        printf("%5.2f", a[i][j]);
        printf("\n");
    }
}


