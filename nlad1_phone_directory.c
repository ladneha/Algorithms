#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct contacts{
 char firstname[20];
 char lastname[20];
 char phone[20];
}Contacts;

// function prototypes
int random_partition(Contacts *records, int start, int end);
void swap(Contacts *a, Contacts *b);
int getUpperBound(Contacts *records, char *fname, char *lname, int start, int end);
int getLowerBound(Contacts *records, char *fname, char *lname, int start, int end);
void Search(Contacts *records, int n, char *fname, char *lname);
void random_qsort(Contacts *records, int start, int end);

// functions
int getUpperBound(Contacts *records, char *fname, char *lname, int start, int end)
{
  int mid;
   if(start>end)
     {
       return start;
     }
   mid = start+((end-start)/2);
   if(strcmp(records[mid].firstname, fname)>0)
    {
      return getUpperBound(records, fname, lname, start, mid-1);
    }
   else
    {
      return getUpperBound(records, fname, lname, mid+1, end);
    }
}

int getLowerBound(Contacts *records, char *fname, char *lname, int start, int end)
{
  if(start>end)
  {
    return start;
  }
  int mid = start +((end-start)/2);
  if(strcmp(records[mid].firstname, fname)>=0 )
    {
      return getLowerBound(records, fname, lname ,start, mid-1);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
    }
  else
    {
      return getLowerBound(records, fname, lname, mid+1, end);
    }
}

void Search(Contacts *records, int n, char *fname, char *lname)
{
  int i;
  int left = getLowerBound(records, fname, lname, 0, n);
  int right = getUpperBound(records, fname,lname, 0, n);
  
  if(right==0)
   {
     printf("\n %s %s %s", records[right].firstname, records[right].lastname, records[right].phone);
   }
  else 
     {
     for(i=left; i<right; i++)
      {
         printf("\n %s %s %s", records[i].firstname, records[i].lastname, records[i].phone);
      }
   }
   if(right==left)
   {
      printf("\n Record not found...\n");
   }
}

void random_qsort(Contacts *records, int start, int end)
{
 if(start<end)
  {
    int mid = random_partition(records, start, end);
    random_qsort(records, start, mid-1);
    random_qsort(records, mid+1, end);
  }
}

int random_partition(Contacts *records, int start, int end)
{
  int j;
  srand(time(NULL));
  int pivotIdx = start + rand()%(end-start+1);
  char pivotFirst[20];
  char pivotLast[20];
  char pivotContact[20];
  strcpy(pivotFirst,records[pivotIdx].firstname);
  strcpy(pivotLast,records[pivotIdx].lastname);
  strcpy(pivotContact,records[pivotIdx].phone); 
  swap(&records[pivotIdx], &records[end]);
  pivotIdx = end;
  int i = start-1;
  for( j=start; j<=end-1; j++)
  {
    if(strcmp(records[j].firstname, pivotFirst)< 0)
    {
      i = i+1;
      swap(&records[i], &records[j] );
    }
    else if(strcmp(records[j].firstname, pivotFirst) == 0)
    {
            if(strcmp(records[j].lastname, pivotLast) < 0)
              {
                i = i+1;
                swap(&records[i], &records[j]);
              }
             else if(strcmp(records[j].lastname, pivotLast) == 0)
                   {
                      if(strcmp(records[j].phone, pivotContact) < 0)
                          {
                              i = i+1;
                              swap(&records[i], &records[j]);
                          } 
                    }
                  else
                   {
                     // do nothing
                   }
    }
    else
    {
       // do nothing
    }
  }
  swap(&records[i+1], &records[pivotIdx]);
  return i+1;
}

void swap(Contacts *a, Contacts *b)
{
  Contacts temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

int main(int argc, char *argv[])
{
  //variables
  int i,ch, number_of_lines=0, count, storeCount, choice;
  Contacts records[1000];
  char first[10], last[10], number[15], fname[10], lname[10];
  char new_first[10], new_last[10], new_contact[15];
  char dfirst[10], dlast[10];

  //-------------Start of the Program--------------
  FILE* myfile = fopen(argv[1], "r");
  do 
   {
      ch = fgetc(myfile);
      if(ch == '\n')
       {
          number_of_lines++;
       }
   } while (ch != EOF);
   if(ch != '\n' && number_of_lines != 0) 
        number_of_lines++;
  fclose(myfile);
    FILE* file = fopen(argv[1], "r");
    if(file != '\0')
      {
        storeCount=0;
         while(EOF != fscanf(file," %s %s %s ",first ,last, number))
            {
              strcpy(records[storeCount].firstname ,first);
              strcpy(records[storeCount].lastname ,last);
              strcpy(records[storeCount].phone ,number);
              storeCount++;
            }
      }
fclose(file);
count = number_of_lines-1;

//---------------------Calling the randomized quick sort on the array of structures-------------------------------------
  while(1)
  {
       printf("\n\n Select one of the following choice: \n 1. Sort \n 2. Search \n 3. Insert new record \n 4. Delete \n 0. Exit \n Enter your choice: ");
       scanf("%d", &choice);
       switch(choice)
        {
          case 1 :// sort
                   random_qsort(records, 0, count);
                   printf("\n------------------------Sorted list is :----------------------------------------");
                    for(i=0; i<=count; i++)
                        {
                          printf("\n  %s %s %s  ", records[i].firstname, records[i].lastname, records[i].phone);
                        }
                   printf("\n--------------------------------------------------------------------------------");

                    break;
          case 2: // search
                    random_qsort(records, 0, count);
                    printf("\n Enter the name: " );
                    scanf("%s %s", &fname, &lname);
                    printf("\n------------------------------------------------------------------------------");
                    Search(records, count, fname, lname);

                     break;
          case 3:   //insert
                    count++;
                    printf("\n Enter new record");
                    printf("\n Enter the name: ");
                    scanf("%s %s",&new_first, &new_last);
                    printf("\n Enter contact: ");
                    scanf("%s",&new_contact);
                    strcpy(records[count].firstname, new_first);
                    strcpy(records[count].lastname, new_last);
                    printf("\n record copied is %s",records[count].lastname );
                    strcpy(records[count].phone, new_contact);
                    printf("\n  %s %s %s  ", records[count].firstname, records[count].lastname, records[count].phone);
                    random_qsort(records, 0, count);
                    printf("\n---------------------List after adding new records is :------------------------------");
                    for(i=0; i<=count; i++)
                        {
                          printf("\n  %s %s %s  ", records[i].firstname, records[i].lastname, records[i].phone);
                        }
                    printf("\n------------------------------------------------------------------------------------"); 
                    break;
          case 4:   //delete
                    printf("\n Enter the name to delete: ");
                    scanf("%s %s",&dfirst, &dlast);
                    for(i=0; i<=count; i++)
                       {
                          if(strcmp(records[i].firstname, dfirst)==0 && strcmp(records[i].lastname, dlast)==0)
                          {
                             strcpy(records[i].firstname, records[count].firstname);
                             strcpy(records[i].lastname, records[count].lastname);
                             strcpy(records[i].phone, records[count].phone);
                             count--;
                           }
                       }
                    random_qsort(records, 0, count);
                    printf("\n--------------------List after deleting new record is :-----------------------------");
                    for(i=0; i<=count; i++)
                        {
                          printf("\n  %s %s %s  ", records[i].firstname, records[i].lastname, records[i].phone);
                        }
                    printf("\n------------------------------------------------------------------------------------");
                    break;
          case 0: 
                   exit(0);
          default:
                   printf("Invalid choice\n");
        }
  }
  return 0;
}
