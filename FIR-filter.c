#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int inputarray(int *array, int arraysize){
  int i =0;
  for (i=0; i<arraysize; i++){
    if(scanf("%i",&array[i]) == 1){
    //printf("Ok\n");
    }
    else{
      printf("Not an integer!\n");
      return 1;
    }
  }//Enter arrayx
  return 1;
};

int inputarraysize(){
  int arraysize;
  if(scanf("%i",&arraysize) == 1){
  //printf("Ok\n");
  }
  else{
  printf("Not an integer!\n");
  return 1;
  }//size of arrayx
  return arraysize;
};

int arrayswap(int *array,int arraysize){
  int i;
  int arraytemp[arraysize+1];
  for (i=0; i<(sizeof(array) / sizeof(int)); i++){
    arraytemp[i]=array[i];
  }
  for (i=(sizeof(array) / sizeof(int))+1; i<(arraysize+1); i++){
    arraytemp[i]=0;
  }
  return *arraytemp;
}

int filter(int *arrayx, int *arrayh, int N, int Maxh, int xsize, int hsize){
    int n=0;
    int m=0;
    int i;
    int TypeN;
    int Y=0;

    printf("Starting paramenters zero or not\n");
    if(scanf("%i",&TypeN) == 1){
    //printf("Ok\n");
    }
    else{
      printf("Not an integer!\n");
      return 1;
    }
    if (TypeN == 0){
      printf("Starting params not zeros\n");
      return 1;
    }


    printf("-----Output------\n");
      for (n=0;n<xsize;n++)
          {
            for(m=0;m<=xsize;m++){
              if (m>hsize-1){
                break;
              }
                  if (m<n+1){
                        Y+=arrayh[m]*arrayx[n-m];
                        printf("Y[%i]=\t arrayh[%i]:%i\t * \t arrayx[%i]:%i\t >%i\n",(m+1),m,arrayh[m],m,arrayx[n-m] , Y);
                      }
                  else{
                        Y+=0*arrayx[n-m];
                        printf("Y[%i]=\t 0\t\t * \t arrayx[%i]:%i\t >%i\n",(m+1),m,arrayx[n-m] , Y);
                      }
            }
            printf("Y[%i]:%i\n",(n),Y);
            Y=0;
            printf("-----------\n");
          }
    return 0;
    };

int main(int argc, char *argv[]){
    int TypeN=0;
    int arrayxsize=5; //default
    int arrayhsize=4; //default
    int i; //Step

    //int arrayx[5]={2,3,1,5,6};//arrayx
    //int arrayh[4]={1,-1,2,3};//arrayh

    int arrayx[arrayxsize];
    int arrayh[arrayhsize];

    printf("While answering the questions answer 1 if yes and 0 if no\n");

    printf("Enter arrayx size!\n");
    arrayxsize=inputarraysize();

    printf("Enter arrayh size!\n");
    arrayhsize=inputarraysize();

    printf("Enter arrayX!\n");
    inputarray(arrayx, arrayxsize);

    printf("Enter arrayH\n");
    inputarray(arrayh, arrayhsize);

    int Maxh=0;
    for (i=0; i<arrayhsize; i++)
        {
           if (arrayh[i]>Maxh)
            Maxh=arrayh[i];
        }

    if (arrayxsize < arrayhsize + 1) {
      printf("Array X < Array H + 1, fill left with 0's?\n");
      scanf("%i", &TypeN);
        if (TypeN == 1){
          *arrayx=arrayswap(arrayx, arrayhsize);
        }
        else {
          printf("Breaking with error!\n");
          return 1;
        }
    }//fill rest of the arrayx with 0's
    int N =1;

    filter(arrayx,arrayh,N,Maxh,arrayxsize, arrayhsize);

    //system("pause");
    return 0;
}
