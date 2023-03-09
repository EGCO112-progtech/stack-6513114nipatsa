#ifndef stack_h
#define stack_h
#include "node.h"
typedef struct {
  NodePtr top;
  int size;
} Stack;

typedef Stack * StackPtr;
void push(StackPtr s, char value)
{
  NodePtr new_node=(NodePtr)malloc(sizeof(Node));
  if(new_node)
  {
    new_node->data=value;
    new_node->nextPtr=s->top;
    s->top=new_node;
    s->size++;
  }
}

int pop(StackPtr s)
{
  NodePtr temp = s->top;
if(s->size>0)
  {
    int value=temp->data;
    s->top=temp->nextPtr;
    free(temp);
    s->size--;
    return value;
  }
  //printf("Empty Stack\n");
return 0;
  }

void pop_all(StackPtr s)
{
  while(s->size>0)
    {
      pop(s);
    }
  }
#endif