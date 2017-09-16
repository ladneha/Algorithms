#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int max(int a, int b)
 { 
 	if(a > b)
 	{
 		return a;
 	}
 	else
 	{
 		return b;
 	}
 }
 
int knapSack(int W, int weight[], int profit[], int n)
{
   int k, w;
   int B[n+1][W+1];
 
   for (k = 0; k <= n; k++)
   {
       for (w = 0; w <= W; w++)
       {
           if (k==0 || w==0)
               B[k][w] = 0;
           else if (weight[k-1] <= w)
                 B[k][w] = max(profit[k-1] + B[k-1][w-weight[k-1]],  B[k-1][w]);
           else
                 B[k][w] = B[k-1][w];
       }
   }
   return B[n][W];
}

int main(int argc, char *argv[])
{
	 int n, i, j, result;
    const char s[2] = ",";
    char *token;
    char *token1;
    char weight[20];
    int fweight[20];
    int fprofit[20];
    char profit[20];
    int profit1[20];
    int capacity;

	//-------Start of the Program-------
	FILE *myfile = fopen(argv[1], "r");
	// -----------Reading from file-----------
	if(myfile != '\0')
	{
		//printf("\n reading from the file" );
		fscanf(myfile, "%d",&n);
		printf(" Input size is %d\n",n);
		fscanf(myfile, "%s", weight);
		printf(" Wieght list is %s \n",weight);
		token = strtok(weight, s);
        i = 0;
        while( token != NULL ) 
         {
            fweight[i] = atoi(token);
            i++;
            token = strtok(NULL, s);
         }
		fscanf(myfile, "%s", profit);
		printf(" Profit list is %s \n",profit);
		token1 = strtok(profit, s);
        i = 0;
        while( token1 != NULL ) 
         {
            fprofit[i] = atoi(token1);
            i++;
            token1 = strtok(NULL, s);
         }
		fscanf(myfile, "%d", &capacity);
		printf(" knapsack capacity is %d\n",capacity);
	}
	//---------call to the knapsack function--------------------
	result = knapSack(capacity, fweight, fprofit, n);
	//---------printing the final result------------------------
	printf("\n Result of 0/1 knapsack with maximum profit : %d\n",result);
	return 0;
}