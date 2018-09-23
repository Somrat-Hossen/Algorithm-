#include<bits/stdc++.h>
#define size 100
char stk[size];
int top=-1;
using  namespace std;

void push(char item)
{
  if(top>=size-1)
     cout<<"Stack Overflow !"<<endl;
  else
  {
    stk[++top]=item;
  }

}

 int operatar(char symbol)
 {
 if(symbol=='^' || symbol=='*' || symbol=='/' || symbol=='+' || symbol=='-')
     return 1;
 else
    return 0;
 }

 char pop()
 {
     char item;
     item=stk[top];
      top--;
     return (item);
 }

 int precedence(char symbol)
 {
   if(symbol=='^') return 3;
   else if(symbol=='*' || symbol=='/') return 2;
   else if(symbol=='+' || symbol=='-') return 1;
   else  return 0;
 }


int main()
{
    freopen("in.txt","r",stdin);
    char infix[size],postfix[size],item,temp;
    int i=0,j=-1;
    cout<<"Enter an expression in infix notation:"<<endl;

    gets(infix);
    //cout<<infix<<endl;

  while(infix[i]!='\0')
    {
        item=infix[i];
        if(item=='(')
         {
            push(item);
         }
        else if((item>='a' && item<='z') || (item>='A' && item<='Z'))
         {
            postfix[++j]=item;
         }

        else if((item>='0' && item<='9'))
         {
            postfix[++j]=item;
         }

        else if(operatar(item)==1)
        {
          temp=pop();
          while((operatar(temp)==1) && (precedence(temp)>=precedence(item))) ///if stack top
          {
              postfix[++j]=temp;
              temp=pop();         ///   Next element to be checked until condition being false
          }
          push(temp); /// when top hold such item which is not big precedency than item then it will remain stack
          push(item);  /// and item also remain ,so outside the while loop two are push. compile and check
        }

       else if(item==')')
       {
           temp=pop();
           while(temp!='(')
           {
              postfix[++j]=temp;
              temp=pop();
           }
       }

      else
       {
         puts("Invalid input: ");
         exit(0);
       }
       i++;
   }        ///end of the execution

       while(top>-1)  ///it brackets are not used and stack are not empty.
       {
           postfix[++j]=pop();
       }

   postfix[++j]='\0';

  puts(postfix);


    return 0;
}
