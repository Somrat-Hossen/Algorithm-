#include<bits/stdc++.h>

using namespace std;

int main()
    {
        int num1[100],num2[100],sum[100],l1,l2,l;
        char str1[100],str2[100];
        scanf("%s",str1);
        scanf("%s",str2);

        for(l1=0;str1[l1]!='\0';l1++)
        {
            num1[l1]=str1[l1]-'0';
        }

        for(l2=0;str2[l2]!='\0';l2++)
        {
            num2[l2]=str2[l2]-'0';
        }

        int i=l1-1,j=l2-1,c=0,k=0;
        for(;i>=0&&j>=0;i--,j--,k++)
        {
         sum[k]=(num1[i]+num2[j]+c)%10;  //Adding last bit with carry then mod 10 means (if sum=13 ,mod=3)
         c= (num1[i]+num2[j]+c)/10; //Adding last bit with carry then mod 10 means (if sum=13/10 ,c=1)
        }

        if(l1>l2)
        {
          while(i>=0)
          {
         sum[k++]=(num1[i]+c)%10;
         c=(num1[i--]+c)/10;
          }
        }

        else if(l1<l2)
        {
          while(j>=0)
          {
         sum[k++]=(num2[j]+c)%10;
         c=(num2[j--]+c)/10;
          }
        }

         else
         {
             if(c>0)
             {
                 sum[k++]=c;
             }
         }

        printf("Sum is: ");
        for(k--;k>=0;k--)
        {
            cout<<sum[k];
        }
      cout<<endl;
        return 0;
    }
