#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

typedef struct item{
  int weight;
  int profit;
  int benefit;
}Item;
 
void printList(Item *item_array, int set_size)
{
  int i;
  for(i=0; i<set_size; i++)
  {
    printf("\n weight is %d and profit is %d", item_array[i].weight, item_array[i].profit);
  }
}
void CalculateGreedy1(Item *item_array, int set_size, int capacity)
{
	//variables
   int i, j;
   Item key;
   int maxProfit;
   int mWeight;
   // sorting in order of profit
   for(i=1; i<set_size; i++)
   {
      key = item_array[i];
      j = i-1;
      while(j>=0 && item_array[j].profit>key.profit)
      {
        item_array[j+1] = item_array[j];
        j = j-1;
      } 
      item_array[j+1] = key;
   }
   //calculating max profit
   maxProfit = item_array[set_size-1].profit;
   mWeight = item_array[set_size-1].weight;
   for(i=set_size-2; i>=0; i--)
   {
     if(mWeight < capacity)
     {
        if((mWeight+item_array[i].weight) <= capacity)
        {
          mWeight = mWeight + item_array[i].weight;
          maxProfit = maxProfit + item_array[i].profit;
        }
     }
   }
   printf("\n By the approach of Greedy1:");
   printf("\n max profit : %d \n max weight : %d", maxProfit, mWeight);
}

void CalculateGreedy2(Item *item_array, int set_size, int capacity)
{
  //variables
   int i, j;
   Item key;
   int maxProfit;
   int mWeight;
   // sorting list in order of weight
   for(i=1; i<set_size; i++)
   {
      key = item_array[i];
      j = i-1;
      while(j>=0 && item_array[j].weight>key.weight)
      {
        item_array[j+1] = item_array[j];
        j = j-1;
      } 
      item_array[j+1] = key;
   }
   // calculating max profit
   maxProfit = item_array[0].profit;
   mWeight = item_array[0].weight;
   for(i=1; i<set_size; i++)
   {
     if(mWeight < capacity)
     {
        if((mWeight+item_array[i].weight) <= capacity)
        {
          mWeight = mWeight + item_array[i].weight;
          maxProfit = maxProfit + item_array[i].profit;
        }
     }
   }
   printf("\n By the approach of Greedy2:");
   printf("\n max profit : %d \n max weight : %d", maxProfit, mWeight);
}
 
void CalculateGreedy3(Item *item_array, int set_size, int capacity)
{
  //variables
   int i, j;
   Item key;
   int maxProfit;
   int mWeight;
// sorting the list in order of weight
   for(i=1; i<set_size; i++)
   {
      key = item_array[i];
      j = i-1;
      while(j>=0 && item_array[j].weight>key.weight)
      {
        item_array[j+1] = item_array[j];
        j = j-1;
      } 
      item_array[j+1] = key;
   }
   // calculating maximum profit
   maxProfit = item_array[set_size-1].profit;
   mWeight = item_array[set_size-1].weight;
   for(i=set_size-2; i>=0; i--)
   {
     if(mWeight < capacity)
     {
        if((mWeight+item_array[i].weight) <= capacity)
        {
          mWeight = mWeight + item_array[i].weight;
          maxProfit = maxProfit + item_array[i].profit;
        }
     }
   }
   printf("\n By the approach of Greedy3:");
   printf("\n max profit : %d \n max weight : %d", maxProfit, mWeight);
}

void CalculateGreedy4(Item *item_array, int set_size, int capacity)
{
  //variables
   int i, j;
   Item key;
   int maxProfit;
   int mWeight;

   // calculating benefit = profit/weight
   for(i=0; i<set_size; i++)
   {
      item_array[i].benefit = item_array[i].profit/item_array[i].weight;
   }
   // sorting the list in order of benefit
   for(i=1; i<set_size; i++)
   {
      key = item_array[i];
      j = i-1;
      while(j>=0 && item_array[j].benefit>key.benefit)
      {
        item_array[j+1] = item_array[j];
        j = j-1;
      } 
      item_array[j+1] = key;
   }
   // finding the maximum benefit
   maxProfit = item_array[set_size-1].profit;
   mWeight = item_array[set_size-1].weight;
   for(i=set_size-2; i>=0; i--)
   {
     if(mWeight < capacity)
     {
        if((mWeight+item_array[i].weight) <= capacity)
        {
          mWeight = mWeight + item_array[i].weight;
          maxProfit = maxProfit + item_array[i].profit;
        }
     }
   }
   printf("\n By the approach of Greedy4:");
   printf("\n max profit : %d \n max weight : %d", maxProfit, mWeight);
}


int main(int argc , char *argv[])
{
    int capacity = 30;
    int n=3;
    char *token;
    char *token1;
    Item item_array[100];
    char weight[20];
    char profit[20];
    int i;
    const char s[2] = ",";

    FILE *myfile = fopen(argv[1], "r");
  //-------------Reading from the file-----------------
  if(myfile != '\0')
  {
    fscanf(myfile, "%d",&n);
    printf(" Input size is %d\n",n);
    fscanf(myfile, "%s", weight);
    printf(" Wieght list is %s \n",weight);
    token = strtok(weight, s);
        i = 0;
        while( token != NULL ) 
         {
            item_array[i].weight = atoi(token);
            i++;
            token = strtok(NULL, s);
         }
    fscanf(myfile, "%s", profit);
    printf(" Profit list is %s \n",profit);
    token1 = strtok(profit, s);
        i = 0;
        while( token1 != NULL ) 
         {
            item_array[i].profit = atoi(token1);
            i++;
            token1 = strtok(NULL, s);
         }
    fscanf(myfile, "%d", &capacity);
    printf(" knapsack capacity is %d\n",capacity);
  }
    CalculateGreedy1(item_array, n, capacity);
    CalculateGreedy2(item_array, n, capacity);
    CalculateGreedy3(item_array, n, capacity);
    CalculateGreedy4(item_array, n, capacity);
   // getchar();
    return 0;
}
