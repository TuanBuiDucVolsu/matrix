#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void InputArray(int **a, int row, int col);
void OutputArray(int **a, int row, int col);
int Function1(int **a,int row,int col);
int Function2(int **a,int row,int col);
void Function3(int **a,int row,int col);
int main(int argc, char *argv[]) {
	printf("---------------------------------\n");
	printf("-------------Lab10---------------\n");
	printf("---------------------------------\n");
	int **a = NULL, row, col;
    int i;
    printf("+Row = ");
    scanf("%d", &row);
    printf("+Col = ");
    scanf("%d", &col);
    // Cap phát mang các con tro cap 1
    a = (int **)malloc(row * sizeof(int *));
    for (i = 0; i < row; i++)
    {
        // Cap phát cho tung con tro cap 1
        a[i] = (int *)malloc(col * sizeof(int));
    }
    InputArray(a, row, col);
    OutputArray(a, row, col);
    Function1(a, row, col);
    Function2(a, row, col);
    Function3(a, row, col);
    // giai phóng tung hàng
    for (i = 0; i < row; i++)
    {
        free(a[i]);
    }
    // giai phong con tro quan lý các dòng
    free(a);
	return 0;
}
void InputArray(int **a, int row, int col)
{
    int i, j;
    srand(time(NULL));
    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++)
        {
            int dau = rand()&1 ?  -1 : 1;
            a[i][j]= dau * rand()%19 +1;
            
        }
}
void OutputArray(int **a, int row, int col)
{
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
            printf("%5d", a[i][j]);
        printf("\n");
    }
}

int Function1(int **a,int row,int col)
{
    int sum,i,j;
    int p = 0;
    for ( i = 0; i < col; i++) {
        sum = 0;
        p = 0;
        for ( j = 0; j < row; j++) {
            if (a[j][i] < 0) {
                continue;
            }
            sum += a[j][i];
        }
		printf("\nSum = %d",sum);
    }
return sum;
}
int Function2(int **a,int row,int col)
{
	int i,j;
printf("\n \n Minimum sredi summ elementov diagonalej,parallelnyh pobochnoy diagonali matricy: ");
int summin = abs(a[0][0]),t;
for(i = 1; i < col-1; i++)
{
    t = 0;
    for(j = 0; j <= i && j < row; j++)
        t += abs(a[j][i-j]);
    if(t < summin)
        summin = t;
}
for(i = 1; i < row; i++)
{
    t = 0;
    for(j = 0; j < row-i && j < col; j++)
        t += abs(a[i+j][col-1-j]);
    if(t < summin)
        summin=t;
}
printf("%d\n", summin);
return summin;
}
void Function3(int **a,int row,int col)
{
	int t,i,j;
    for( i = 0; i < col; i++)
    {
        for( j = 0; j < row; j++)
        {
         printf("%5d", a[j][i]);
        }
        printf("\n");
    }

}
