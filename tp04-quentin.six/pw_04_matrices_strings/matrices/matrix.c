#include <stdio.h>

void print_matrix(char s[], double m[], size_t rows, size_t cols)
{
	printf("%s =\n",s );
    for (size_t i =0;i<rows;i++)
    {
    	printf(" ");
    	for(size_t j =0;j<cols;j++)
    	{
    		printf("%4g",m[i*cols+j]);
    	}
    	printf("\n");
    }
}

void transpose(double m[], size_t rows, size_t cols, double r[])
{
    for(size_t i =0;i<rows;i++)
    {
    	for(size_t j=0;j<cols;j++)
    	{
    		r[j*rows+i]=m[i*cols+j];
    	}
    }
}

void add(double m1[], double m2[], size_t rows, size_t cols, double r[])
{
    for(size_t i =0;i<rows;i++)
    {
    	for(size_t j=0;j<cols;j++)
    	{
    		r[i*cols+j]=m1[i*cols+j]+m2[i*cols+j];
    	}
    }
}

void mul(double m1[], double m2[], size_t r1, size_t c1, size_t c2, double r[])
{
    for(size_t i =0;i<c2;i++)
    {
    	for(size_t j=0;j<r1;j++)
    	{
            for(size_t k=0;k<c1;k++)
            {
                r[j*c2+i]+=(m1[j*c1+k]*m2[k*c2+i]);
            }
        }
    }
}
