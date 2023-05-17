#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<stdlib.h>

#define MAX 100

int top = -1;
char stack[MAX];


int isFull (){
  return top == MAX - 1;
}

int isEmpty (){
  return top == -1;
}

void push (char item){
  if (isFull ())
    return;
  top++;
  stack[top] = item;
}
int pop (){
  if (isEmpty ())
    return -1;

  return stack[top--];
}

int peek (){
  if (isEmpty ())
    return -1;
  return stack[top];
}

int checkIfOperand (char ch){
  return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
 
int precedence (char x){
  if(x == '('){
        return 0;
    }
    if(x == '+' || x == '-'){
        return 1;
    }
    if(x == '/' || x == '*'){
        return 2;
    }
    if(x == '^'){
        return 3;
    }
    return 0;
}

int getPostfix (char *exp){
  int i, j;

  for (i = 0, j = -1; exp[i]; ++i){

      if (checkIfOperand (exp[i]))
	exp[++j] = exp[i];
    
      else if (exp[i] == '(')
	push (exp[i]);
 
      else if (exp[i] == ')'){
	  while (!isEmpty (stack) && peek (stack) != '(')
	    exp[++j] = pop (stack);
	  if (!isEmpty (stack) && peek (stack) != '(')
	    return -1;             
	  else
	    pop (stack);
	}
      else{
	  while (!isEmpty (stack)
		 && precedence (exp[i]) <= precedence (peek (stack)))
	    exp[++j] = pop (stack);
	  push (exp[i]);
	}
    }

  while (!isEmpty (stack))
    exp[++j] = pop (stack);

  exp[++j] = '\0';

}

void reverse (char *exp){

  int size = strlen (exp);
  int j = size, i = 0;
  char temp[size];

  temp[j--] = '\0';

  while (exp[i] != '\0'){
      temp[j] = exp[i];
      j--;
      i++;
    }
  strcpy (exp, temp);
}

void brackets (char *exp){
  int i = 0;
  while (exp[i] != '\0'){
      if (exp[i] == '(')
	exp[i] = ')';
      else if (exp[i] == ')')
	exp[i] = '(';
      i++;
    }
}

void InfixtoPrefix (char *exp){
  int size = strlen (exp);
  reverse (exp);
  brackets (exp);
  getPostfix (exp);
  reverse (exp);
}

int main (){

  printf ("The infix is: ");

  char expression[] = "((a/b)+c)-(d+(e*f))";
  printf ("%s\n", expression);
  InfixtoPrefix (expression);

  printf ("The prefix is: ");
  printf ("%s\n", expression);

  return 0;
}