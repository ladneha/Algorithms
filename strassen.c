#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

// defining structure
typedef struct matrix
{
	float m[50][50];
}Matrix;

// prototypes of functions
void displayMatrix(int n, Matrix M);
Matrix subMatrix11(int n, Matrix M);
Matrix subMatrix12(int n, Matrix M);
Matrix subMatrix21(int n, Matrix M);
Matrix subMatrix22(int n, Matrix M);
void standardMultiplication(int n, Matrix a, Matrix b);
Matrix strassenMultiplication(int n, Matrix a, Matrix b);                     
Matrix addition(int n, Matrix one, Matrix two);
Matrix subtraction(int n, Matrix one, Matrix two);
void strassen(int n, Matrix a, Matrix b);
int IsPowerOfTwo(int n);
Matrix combineMatrix(int n, Matrix c11, Matrix c12, Matrix c21, Matrix c22);
Matrix Padding(int n, Matrix temp, int pad);

// Function definations
Matrix subMatrix11(int n, Matrix M)     // Extracting the first quadrant of the n*n matrix
{
	int i,j;
	Matrix a11;
	for(i=0; i<n/2; i++)
	{
		for(j=0; j<n/2; j++)
		{
			a11.m[i][j] = M.m[i][j];
		}
	}
	return a11;
}

Matrix subMatrix12(int n, Matrix M)   // Extracting the second quadrant of the n*n matrix
{
	Matrix a12;
	int i, j, p, q;
	for(i=0, p=0; i<n/2 && p<n/2; i++, p++)
	{
		for(j=n/2, q=0; j<n && q<n/2; j++, q++)
		{
                   a12.m[p][q] = M.m[i][j];
				
		}
	}
	return a12;
}

Matrix subMatrix21(int n, Matrix M)     // Extracting the third quadrant of the n*n matrix
{
   Matrix a21;
	int i, j, p, q;
	for(i=n/2, p=0; i<n && p<n/2; i++, p++)
	{
		for(j=0, q=0; j<n/2 && q<n/2; j++, q++)
		{
                   a21.m[p][q] = M.m[i][j];
				
		}
	}
	return a21;
}

Matrix subMatrix22(int n, Matrix M)    // Extracting the fourth quadrant of the n*n matrix
{
   Matrix a22;
	int i, j, p, q;
	for(i=n/2, p=0; i<n && p<n/2; i++, p++)
	{
		for(j=n/2, q=0; j<n && q<n/2; j++, q++)
		{
                   a22.m[p][q] = M.m[i][j];
				
		}
	}
	return a22;
}

void displayMatrix(int n, Matrix M)    // Printing the matrix
{
   int i, j;
   printf("\n");
   for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			printf("  %.2f", M.m[i][j]);
			if(j == n - 1)
				printf("\n\n");
		}
	}
}

int IsPowerOfTwo(int n)      // checking if the number is power of two
{
	while(n!=1)
	{
		if(n%2 != 0)
			return 0;
		n = n/2;
	}
	return 1;
}
Matrix addition(int n, Matrix one, Matrix two)   // performs addition of two matrices
{
	Matrix sum;
	int i, j;
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			sum.m[i][j]= one.m[i][j] + two.m[i][j];
		}
	}
	return sum;
}

Matrix subtraction(int n, Matrix one, Matrix two)   // performs subtraction of two matrices
{
	Matrix sum;
	int i, j;
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			sum.m[i][j]= one.m[i][j] - two.m[i][j];
		}
	}
	return sum;
}

Matrix combineMatrix(int n, Matrix c11, Matrix c12, Matrix c21, Matrix c22)  // combines the divided 4 matrices to a single matrix
{
	int i, j, p, q;
	Matrix CM;
   for(i=0; i<n/2; i++)
   {
   	  for(j=0; j<n/2; j++)
   	  {
           CM.m[i][j] = c11.m[i][j];
   	  }
   }

   for(i=0, p=0; i<n/2 && p<n/2; i++, p++)
   {
   	for(j=n/2, q=0; j<n && q<n/2; j++, q++)
   	{
   		CM.m[i][j] = c12.m[p][q];
   	}
   }

   for(i=n/2, p=0; i<n && p<n/2; i++, p++)
   {
   	 for(j=0, q=0; j<n/2 && q<n/2; j++, q++)
   	 {
   	 	CM.m[i][j] = c21.m[p][q];
   	 }
   }

   for(i=n/2, p=0; i<n && p<n/2; i++, p++)
   {
   	 for(j=n/2, q=0; j<n && q<n/2; j++, q++)
   	 {
   	 	CM.m[i][j] = c22.m[p][q];
   	 }
   }
   return CM;
}

Matrix Padding(int n, Matrix temp, int pad)   //Performs padding for n not equal to two to the power of k
{
	int i, j, p;

	i=0;
	for(p=1; p<=pad; p++)
	{
		temp.m[i][n] = 0;
		i++;
	}
	j=0;
	for(p=1; p<=pad; p++)
	{
		temp.m[n][j] = 0;
		j++;
	}
	return temp;
}

void strassen(int n, Matrix a, Matrix b)   // function for strassen's multiplication
{
	Matrix result, PA, PB;
	if(IsPowerOfTwo(n) == 0)
    {
    	printf("\n Case where n is not in power of two\n");
    	int i=0;
    	while(n > pow(2, i))
    	{
    		i++;
    	}
    	int highest_power = i;
    	int new_n = pow(2, i);
    	int pad = new_n - n;

        PA = Padding(n, a, pad);
        PB = Padding(n, b, pad);
        printf("\n Strassens Multiplication Output: ");
        result = strassenMultiplication(new_n, PA, PB);
        displayMatrix(new_n, result);
    }
    else
    {
    	printf("\n Strassen's Multiplication Output : ");
    	result = strassenMultiplication(n, a, b);
    	displayMatrix(n, result);
    }
}

Matrix strassenMultiplication(int n, Matrix a, Matrix b)   // recursive function for strassen multiplication
{
    Matrix C, unit;
    if(n>1)
    {
        Matrix A11, A12, A21, A22, B11, B12, B21, B22, M1,M2,M3, M4, M5, M6, M7, C11, C12, C21, C22;
        Matrix A11plusA22, B11plusB22, A21plusA22, A11plusA12, B11plusB12, B21plusB22, B12subB22, B21subB11, A21subA11, A12subA22;

        // dividing the matix into 4 blocks
        A11 = subMatrix11(n, a);
        A12 = subMatrix12(n, a);
        A21 = subMatrix21(n, a);
        A22 = subMatrix22(n, a);
        B11 = subMatrix11(n, b);
        B21 = subMatrix21(n, b);
        B22 = subMatrix22(n, b);
        B12 = subMatrix12(n, b);
        
        //performing calculations
        A11plusA22 = addition(n/2, A11, A22);
        B11plusB22 = addition(n/2, B11, B22);
        A21plusA22 = addition(n/2, A21, A22);
        A11plusA12 = addition(n/2, A11, A12);
        B11plusB12 = addition(n/2, B11, B12);
        B21plusB22 = addition(n/2, B21, B22);
        B12subB22 = subtraction(n/2, B12, B22);
        B21subB11 = subtraction(n/2, B21, B11);
        A21subA11 = subtraction(n/2, A21, A11);
        A12subA22 = subtraction(n/2, A12, A22);
        
        // calculating M1, M2...M7
        M1 = strassenMultiplication(n/2, A11plusA22, B11plusB22);
        M2 = strassenMultiplication(n/2, A21plusA22, B11);
        M3 = strassenMultiplication(n/2, A11, B12subB22);
        M4 = strassenMultiplication(n/2, A22, B21subB11);
        M5 = strassenMultiplication(n/2, A11plusA12, B22);
        M6 = strassenMultiplication(n/2, A21subA11, B11plusB12);
        M7 = strassenMultiplication(n/2, A12subA22, B21plusB22);
    
        // calculating values for C11, C12, C21, C22
        C11 = addition(n, subtraction(n, M1, M5), addition(n, M4, M7));
        C12 = addition(n, M3, M5);
        C21 = addition(n, M2, M4);
        C22 = addition(n, subtraction(n, M1, M2), addition(n, M3, M6));
        
        // combining C11, C12, C21, C22
        C = combineMatrix(n, C11, C12, C21, C22);
        return C;
    }
    else
    {
        unit.m[0][0] = a.m[0][0] * b.m[0][0];
        return unit; 
    }
}


void standardMultiplication(int n, Matrix a, Matrix b)     // function for standard multiplication
{
   Matrix multMatrix;
   float sum;
   int i, j, k;
   
   //initialising mult matrix to 0
   for(i=0; i<n; i++)
   {
   	  for(j=0; j<n; j++)
   	  {
   	  	multMatrix.m[i][j]=0;
   	  }
   }  
   //performing the multiplication
   for(i=0; i<n; i++)
   {
   	  for(j=0;j<n; j++)
   	  {
   	  	sum=0;
   	  	for(k=0; k<n; k++)
   	  	{
   	  		sum = sum + a.m[i][k] * b.m[k][j];
   	  	}
   	  	multMatrix.m[i][j] = sum;
   	  }
   }
   printf("\n Standard Multiplication matrix is : \n");
   displayMatrix(n, multMatrix);
}

int main(int argc, char *argv[])    // main function
{
    // variables
    Matrix result, result1;
    int i, j;
    float number;
    printf("\n Value of n is %d", atoi(argv[1]));
    int n = atoi(argv[1]);
    Matrix A, B;

    //enter data A
    printf("\n Elements in matrix A are: ");
    for(i=0; i<n; i++)
    {
    	for(j=0; j<n; j++)
    	{
            number = 10.0*((float)rand())/(float)RAND_MAX + (-5.0);   //generating random float numbers
            A.m[i][j] = number;
    	}
    }
    printf("\n");
    displayMatrix(n, A);
    //enter data for B
    printf("\n Elements in matix B are: ");
     for(i=0; i<n; i++)
    {
    	for(j=0; j<n; j++)
    	{
            number = 10.0*((float)rand())/(float)RAND_MAX + (-5.0);   //generating random float numbers
            B.m[i][j] = number;
    	}
    } 
    displayMatrix(n, B);
    standardMultiplication(n, A, B);
    strassen(n, A, B);
	return 0;
}
