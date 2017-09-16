#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>
#define V 5

// Function to find the minimum distance
int mindistance(int distance[], bool set[])
{
   int min = INT_MAX, minIndex;
  
   for (int i = 0; i < V; i++)
   {
     if (set[i] == false && distance[i] <= min)
       {
         min = distance[i];
         minIndex = i;
       }
   }
   return minIndex;
}
  
void dijkstra(int matrix[V][V], int source)
{
     int distance[V];    
     bool set[V]; 
  // Initialising the output list to infinity
     for (int i = 0; i < V; i++)
     {
        distance[i] = INT_MAX;
        set[i] = false;
     }
     // assigning the distance from source to itself as zero
     distance[source] = 0;
  
     for (int cnt = 0; cnt < V-1; cnt++)
     {
       int u = mindistance(distance, set);
       set[u] = true;
  
       for (int v = 0; v < V; v++)
       {
         if (!set[v] && matrix[u][v] && distance[u] != INT_MAX  && distance[u]+matrix[u][v] < distance[v])
            {
                     distance[v] = distance[u] + matrix[u][v];
            }
        }
     }
  
     //printing the output 
      printf("Vertex   distance from source\n");
      for (int i = 0; i < V; i++)
         {
              printf("%d \t\t %d\n", i, distance[i]);
         }
}

int main(int argc, char *argv[])
{
	// ----variables----
   int matrix[5][5];
   char temp[50];
   char *token;
   int i,j;
   const char s[2] = ",";
    // ----start of the program----
    FILE *myfile = fopen(argv[1], "r");
    if(myfile != '\0')
    {   //row 0
       fscanf(myfile, "%s", temp);
	   printf(" Row 0 is %s \n",temp);
	   token = strtok(temp, s);
        i = 0;
        while( token != NULL ) 
         {
            printf( " %s\n", token );
            matrix[0][i] = atoi(token);
            i++;
            token = strtok(NULL, s);
         }
        // row 1
         fscanf(myfile, "%s", temp);
	   printf(" Row 1 is %s \n",temp);
	   token = strtok(temp, s);
        i = 0;
        while( token != NULL ) 
         {
            matrix[1][i] = atoi(token);
            i++;
            token = strtok(NULL, s);
         }
         //row2
         fscanf(myfile, "%s", temp);
	   printf(" Row 2 is %s \n",temp);
	   token = strtok(temp, s);
        i = 0;
        while( token != NULL ) 
         {
            matrix[2][i] = atoi(token);
            i++;
            token = strtok(NULL, s);
         }
         //row 3
         fscanf(myfile, "%s", temp);
	   printf(" Row 3 is %s \n",temp);
	   token = strtok(temp, s);
        i = 0;
        while( token != NULL ) 
         {
            matrix[3][i] = atoi(token);
            i++;
            token = strtok(NULL, s);
         }
          //row 4
         fscanf(myfile, "%s", temp);
	   printf(" Row 4 is %s \n",temp);
	   token = strtok(temp, s);
        i = 0;
        while( token != NULL ) 
         {
            matrix[4][i] = atoi(token);
            i++;
            token = strtok(NULL, s);
         }
    }
   //-------matrix updated with data--------------
    for (i=0; i<5; i++)
    {
      for (j=0; j<5; j++)
      {
        if(matrix[i][j] == -99)
        {
          matrix[i][j] = 10000000;
        }
      }
    }
    dijkstra(matrix, 0);
	return 0;
}