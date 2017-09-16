#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

void CalculateSolution(int weight[], int profit[], int set_size, int maxWeight)
{
	int maxProfit = 0;
	int sum = 0;
	int psum = 0;
	int count = 0;
	int mWeight;
	int item1, item2, itema, itemb;
    
    //---------calculating the power set size-----------
    unsigned int pow_set_size = pow(2, set_size);
    int counter, j;
 
    for(counter = 0; counter < pow_set_size; counter++)
    {
      for(j = 0; j < set_size; j++)
       {
          if(counter & (1<<j))
          {
          	item1 = sum;
          	item2 = weight[j];
            sum = sum + weight[j];
            psum = psum + profit[j];
           }
       }
       if(sum <= maxWeight)
       {
       	  mWeight=sum;
       	  itema = item1;
       	  itemb = item2;
        
          if(psum > maxProfit)
          {
             maxProfit = psum;
          } 
       }
       sum = 0;
       psum = 0;
    }
    printf("\nMax weight is %d with item of weights %d and %d \n",mWeight, itema, itemb );
    printf("Max profit is %d\n",maxProfit);
}
 
int main(int argc, char * argv[])
{
	//variables
    int n, i, j;
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
	// ---------Reading from the file-----------
	if(myfile != '\0')
	{
		fscanf(myfile, "%d",&n);
		printf(" Input size is %d\n",n);
		fscanf(myfile, "%s", weight);
		printf(" Wieght list is %s \n",weight);
		token = strtok(weight, s);
   /* walk through other tokens */
        i = 0;
        while( token != NULL ) 
         {
            //printf( " %s\n", token );
            fweight[i] = atoi(token);
            i++;
            token = strtok(NULL, s);
         }
		fscanf(myfile, "%s", profit);
		printf(" Profit list is %s \n",profit);
		token1 = strtok(profit, s);
   /* walk through other tokens */
        i = 0;
        while( token1 != NULL ) 
         {
            //printf( " %s\n", token1 );
            fprofit[i] = atoi(token1);
            i++;
            token1 = strtok(NULL, s);
         }
		fscanf(myfile, "%d", &capacity);
		printf(" knapsack capacity is %d\n",capacity);
	}
	 //-------------Call to the Brute force method--------------
	  CalculateSolution(fweight, fprofit, n, capacity);
	fclose(myfile);

	return 0;
}