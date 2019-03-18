#include"tinycalc.h"
#include<stdio.h>

 /*  put your function implementations in here */

//Jack Hershey it works for multiplication, division, and exponents but for
// reason addition and subtraction wont work.

double numbernum;

int check_command(char op) {
 if (op == '/' || op == '*' || op == '+' || op == '-' || op == '^'){
   return TC_COMMAND_OK;
 }

 if (op == 'q'|| op == 'Q'){
   return TC_COMMAND_QUIT;
 }

  return TC_COMMAND_INVALID;
}

int read_command(char *op, double *num) {

   scanf("%c",op);
   scanf("%lf",num);
  
  if(op == "q" || op == "Q"){
    return TC_COMMAND_QUIT; 
   }
  
    
  return TC_COMMAND_OK;
}

void execute_calculation(char f_operator, double f_operand, double *p_result) {
  char op = f_operator;
  int u = 0;
       printf("here1\n"); 
    if(op=='*'){
      *p_result = *p_result * f_operand;
  }
    if(op=='/'){
      *p_result = *p_result / f_operand;
  }
    if(f_operator=='^'){
      u= *p_result;
      for(int i = 1; i < f_operand; i++){
          *p_result = *p_result * u;
      }

      }

    if(op=='+'){
      *p_result = f_operand + *p_result;
  }
    if(op=='-'){
      *p_result = *p_result - f_operand;
  }


    
 

}

double mem_read(tc_memory_t mem, int v) {
  if(v >= 0 && v <= 4){
  printf("%lf\n",mem.vals[v]);
  return mem.vals[v];
}
  else {
    printf("I don't remember that.\n");
    return 0;
  }

}

void mem_save(tc_memory_t *mem, double v) {
  

	for(int i = TC_MEM_SZ-1; i>0; i--){
		mem -> vals[i-1] = mem->vals[i];
	      
	}

	mem->vals[0] = v;
}
