#include<stdio.h>
#include<conio.h>
int max(int a,int b)
{

     if(a>b)
     {
        return a;
     }
     else
     {
        return b;
     }
}
void backtracking(int table[20][20],int n,int W,int w[]) // backtracking(table,n,W,w);

{
    int np[10],k=0,i=n,j=W;
    while(i>=0 || j>=0)
    {
        if(table[i][j]=table[i-1][j])
        {
           i--;
           k++;

        }
        else
        {
            np[k]=w[i];
            i=i-1;
            j=j-w[i];
            k++;
            i--;

        }

    }
    for(int i=1;i<k;i++)
    {
         printf("%d",np[i]);
    }
}
void knapsack(int v[],int w[],int W,int n)
{
    int table[20][20],q;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=W;j++)
        {
            if(i==0 || j==0)
            {
                table[i][j]=0;
            }
            else if(w[i]<=j)
            {
                q=max(table[i-1][j],table[i-1][j-w[i]]+v[i]);
                table[i][j]=q;
            }
            else
            {

                table[i][j]=table[i-1][j];
            }

        }

    }

     for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=W;j++)
        {
            printf(" %d",table[i][j]);
        }
        printf("\n");
    }
    backtracking(table,n,W,w);

}

void main()
{
    int i,j,w[100],v[100],W,n;
    printf("enter the size of weight & value");
    scanf("%d",&n);
    printf("Enter the weight\n");
    for(i=1;i<=n;i++)
    {
    scanf("%d",&w[i]);
    }
    printf("Enter the value\n");
    for(i=1;i<=n;i++)
    {
    scanf("%d",&v[i]);
    }
    printf("Enter the max weight");
    scanf("%d",&W);
    knapsack(v,w,W,n);
}
