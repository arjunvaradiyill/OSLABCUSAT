#include<stdio.h>
int main()
{
    int p[20],f[20],n,fn,found,i,j,k,ct,max,pos;
    printf("\n enter the number of pages");
    scanf("%d",&n);
    printf("\n enter the sequence:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&p[i]);
    }
    printf("\nenter the number of frames");
    scanf("%d",&fn);
        for(j=0;j<fn;j++)
        {
            f[j]=-1;
        }
    for(i=0;i<n;i++)
    {
        found=0;
        {
            for(j=0;j<fn;j++)
            {
                if(f[j]==p[i])
                {
                    found =1;
                    break;
                }
            }
            
        }
        if(found==0)
        {   max=-1;
            pos=-1;
           for(j=0;j<fn;j++)
           {
               if(f[j]==-1)
               {
                   f[j]=p[i];
                   goto l1;
               }
           }
           for(j=0;j<fn;j++)
           {
               ct=0;
               for(k=i-1;k>=0;k--)
               {
                   if(p[k]==f[j])
                   {
                       ct++;
                       break;
                   }
               }
               if(ct>max)
               {
                   max=ct;
                   pos=j;
               }
               
           }
          f[pos]=p[i];
        }
         l1:
            printf("\n");
            for(j=0;j<fn;j++)
            {
                printf("%d\t",f[j]);
            }
    }
}
