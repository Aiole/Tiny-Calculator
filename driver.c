#include<stdio.h>
#include"tinycalc.h"

//Jack Hershey it works for multiplication, division, and exponents but for
// reason addition and subtraction wont work.

int main(void) {
 
  int newi= 0;
   int m = 0;
   int opsize= 0;
   double x,dnum,newresult;
  printf("\nWelcome to TinyCalc!\n\n Enter an operation <+, - , *, /, ^>");
  printf(" followed by operand\n\n Enter 'q' or 'Q' to quit.\n\n");
  printf(" Enter 'm' or 'M' followed by location (0-4) to load a previous\n");
  printf(" result from memory.");
  printf("\n>");

 tc_memory_t mem;
  
  for (m=0; m<5; m++){
    mem.vals[m] = 0;
  }
  
  struct _tc_mem *mm;
  newresult = 0;
   char op;
   int i = 0;
   char* p = &op;
   double* f = &dnum;
   double* result = &newresult;

  
  while(1==1){
     
   read_command(p,f);
   //printf("scans= %d\n",opsize); 

      
    if (check_command(op)){
      /*  printf("%d\n", TC_MEM_SZ-1);
      printf("valid operator\n");
      printf("operator=%c\n", op);
	printf("dnum= %lf\n",dnum);
      */
	mem_save(&mem,dnum);
     
      // printf("print mem= %lf\n", mem.vals[0]);
      execute_calculation(op,dnum,result);
      printf("%lf\n",newresult);
    } 

     opsize++;

  
  }

  return 0;


}
