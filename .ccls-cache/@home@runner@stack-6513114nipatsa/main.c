#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "node.h"
#include "stack.h"
/*
void push(NodePtr* top,int x);
int pop(NodePtr* top);
*/

void checking(int error, int i)
{
  if (error == 0) {
    printf("argv %d: incorrect: mismatch\n", i);
  } else if (error == 2)
    printf("argv %d: incorrect: too many open parenthesis\n", i);
  else if (error == 3)
    printf("argv %d: incorrect: too many closed parenthesis\n", i);
  else
    printf("argv %d: correct\n", i);
}

int main(int argc, char **argv){
 
  int i,N,j,error=1,counter = 0;;
  Stack s;
  s.top=NULL;
  s.size=0;
  
  for(i=1;i<argc;i++){
    error=1;
    char k;
    for(j=0;j<strlen(argv[i]);j++){
     switch(argv[i][j]){  
       case '{':
       case '[':  push(&s,argv[i][j]); 
                  break;
     
       case ']':   k = pop(&s);
                  if (k == 'a')
                   {
                  error = 3;
                  counter++;
                   }
        else if (k != '{') error = 0;
        break;
       case '}':  k = pop(&s);
                  if (k == 'a')
                  {
                  error = 3;
                  counter++;
                  }
        else if (k != '[') error= 0;
        break;
      //if(error==1) break;
    }
 }
    if (s.size - counter > 0) error = 2;
    else if (s.size - counter < 0) error = 3;

    checking(error, i);
    pop_all(&s);
  }
  pop_all(&s);
   return 0;
}

    
    /*if(s.size>0){
      printf("argv %d: Incorrect too many open parenthesis\n",i);
      pop_all(&s);
    }
      if(s.size>){
      printf("argv %d: Incorrect too many close parenthesis\n",i);
      pop_all(&s);
    }
    else if(error==0) printf("argv %d: Correct\n",i);
      else printf("argv %d : Incorrect\n",i);
  }*/




 /* pop_all(&s); 
 
  
  push(&top,5);
  printf("%d\n",pop(&top));
  push(&top,7);
  push(&top,8);
  printf("%d\n",pop(&top));
  printf("%d\n",pop(&top));
  printf("%d\n",pop(&top));
*/
 
 
 

 /*
 Stack s;
 printf("Checking the parentheses in argv arguments\n");
  for(i=1;i<argc;i++){
   
     for(j=0;j<strlen(argv[i]);j++){
       /* Use stack to help with the parentheses*/


    /* }*/


 /* } */




