#include<bits/stdc++.h>
using namespace std;

int main()
{
    int *ptr;
    int n,i,res=0;
    puts("Enter the number of Element:");
    cin>>n;

    ptr=(int*)malloc(n*sizeof(int));

    if(ptr==0)
    {
        puts("Memory not Allocated:");
    }
    else
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d",(ptr+i));
            res+=*(ptr+i);
        }
    }

    puts("Memory element are:");
    sort(ptr+1,ptr+n+1);
    for(i=1;i<=n;i++)
    {
     cout<<*(ptr+i)<<" ";

    }
    free(ptr);
   cout<<endl<<"Total summation is: "<<res<<endl;


    return 0;
}
