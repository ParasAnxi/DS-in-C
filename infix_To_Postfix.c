#include<stdio.h>
#include<ctype.h>
int top = -1;
char arr[100];

void push(char x){
    arr[++top] = x;
}
char pop(){
    if(top == -1){
        return -1;
    }
    else{
        return arr[top--];
    }
}
int precedence(char x){
    if(x == '('){
        return 0;
    }
    if(x == '+' || x == '-'){
        return 1;
    }
    if(x == '/' || x == '*'){
        return 2;
    }
    return 0;
}
int isANum(char x){
    if(x >= 'a' && x <= 'z' || x <='A' && x>='Z' || x>='0' && x<='9'){
        return 1;
    }
    return 0;
}
int main(){
    char exp[100];
    char *i ,x;
    printf("Enter a expression : ");
    scanf("%s",exp);
    printf("\n");
    i = exp;
    while(*i != '\0'){
        if(isANum(*i)){
            printf("%c",*i);
        }
        else if(*i == '('){
            push(*i);
        }
        else if(*i == ')'){
            while((x = pop()) != '('){
                printf("%c",x);
            }
        }
        else{
            while(precedence(arr[top])>=precedence(*i)){
                printf("%c",pop());
            }
            push(*i);
        }
        i++;
    }
    while(top!=-1){
        printf("%c ",pop());
    }
    return 0;
}