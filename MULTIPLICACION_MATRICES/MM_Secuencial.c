#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

/* gcc -osecuencial MatMulSecuencial.c
   ./secuencial
*/


int row, col;
int** A;
int** B;
int** C;

//Funciones seriales
void read_mat(int col, int row);
void matmul(int col, int row);
void print_result();

int main(int argc, char* argv[]){

  int tamano = strtol(argv[1], NULL, 10);
  int i, j;
  row = tamano;
  col = tamano;

  A = (int **)malloc(row*sizeof(int *));
      for(i=0;i<row;i++)
        A[i]=(int *)malloc(col*sizeof(int));

  B = (int **)malloc(row*sizeof(int *));
      for(i=0;i<row;i++)
        B[i]=(int *)malloc(col*sizeof(int));

  C = (int **)malloc(row*sizeof(int *));
      for(i=0;i<row;i++)
        C[i]=(int *)malloc(col*sizeof(int));

  srand(time(NULL));
  //Lectura de matrices
  read_mat(col,row);

  struct timeval start;
  struct timeval end;
  double milisecs;
  long seconds, useconds;

  gettimeofday(&start, 0);

  //Realizar la multiplicacion
  matmul(col, row);

  gettimeofday(&end, 0);

  //Impresión de resultado
 /* print_result(A);
  printf("\n-----------------------------------------------------------------------------------------------------------------------");
  print_result(B);
  printf("\n-----------------------------------------------------------------------------------------------------------------------");
  print_result(C);*/

  seconds  = end.tv_sec  - start.tv_sec;
  useconds = end.tv_usec - start.tv_usec;
  milisecs = ((seconds) * 1000 + useconds/1000.0);
  printf("%.8g;", milisecs );

  //Liberación de memoria
  free(A);
  free(B);
  free(C);

  return 0;
}


//-------------------------------------------

void matmul(int col, int row){
  int i,j,k, n;
  for(i=0;i<row;i++){
   for(j=0;j<col;j++){
    C[i][j]=0;
    for(k=0;k<col;k++){

      C[i][j] += A[i][k]*B[k][j];
    }
   }
  }

}
//----------------------------------------
void read_mat(int col, int row){
  int i,j;

  for(i = 0; i < row; i++){
      for(j = 0; j < col; j++){
             A [i][j]= rand()%11;
             B [i][j]= rand()%11;
       }

   }

}

void print_result(int **Matriz){
  int i,j;
  printf("\n");
  for(i = 0; i < row; i++){
      for(j = 0; j < col; j++){
         printf("%d ", Matriz[i][j]);
       }
      printf("\n");
   }

}
