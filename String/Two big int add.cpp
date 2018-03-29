#include<bits/stdc++.h>
using namespace std;
int main()
{
    char ch1[2000],ch2[2000],ch3[2001],re[2001];int ne=0,c=0,n=-1,l1=-1,l2=-1,i=1;

    scanf("%s%s",ch1,ch2);
    while(ch1[++l1]!='\0'){}cout<<l1<<endl;
    while(ch2[++l2]!='\0'){}cout<<l2<<endl;
    if(l1>l2)
    {
        while(ch2[++n]!='\0')
        {
                if((ch1[l1-i] -48 + ch2[l2-i] -48 +c)>9)
                {
                    ch3[ne++] = (ch1[l1-i] -48 + ch2[l2-i] -48 +c) -10 +48;
                    c=1;
                }
                else{
                    ch3[ne++] = (ch1[l1-i] -48 + ch2[l2-i] -48 +c)+48;
                    c=0;
                }
              i++;
        }
        }
    while(ch1[n++]!='\0')
        {
            if((ch1[l1-i] -48  +c)>9)
                {
                    ch3[ne++] = (ch1[l1-i] -48 +c) -10 +48;
                    c=1;
                }
            else{
                    ch3[ne++] = ch1[l1-i] +c;
                    c=0;
                }
            i++;
        }
    if(c==1)
        ch3[ne++]='1';
    i=0;
    while(--ne>=0)
    {
        re[i++] = ch3[ne];
    }
    re[i]='\0';
    printf("Sum :%s",re);
    return 0;
}
