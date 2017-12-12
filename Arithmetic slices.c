#include<stdio.h>
#include<stdlib.h>


int numberOfArithmeticSlices(int* A, int ASize);

int main(void)
{
    int N;
    scanf("%d",&N);
    int arr[N];
    for(int i=0;i<N;i++)
        scanf("%d",&arr[i]);
    printf("%d\n",numberOfArithmeticSlices(arr,N));
    return 0;

}

int numberOfArithmeticSlices(int* A, int ASize) {
    int i,j,result;
    i=result=0;
    j=1;
    while(i<ASize-2)
    {

        while(j<ASize-1 && A[j+1]-A[j]==A[j]-A[j-1])
        {
            j++;
        }
        if(j<ASize-1)
        {
            result+=(j-i-1)*(j-i-2)/2;
            i=j;
            j=i+1;
        }
        else
        {
            result+=(ASize-i-2)*(ASize-i-1)/2;
            break;
        }
    }

    return result;
}
