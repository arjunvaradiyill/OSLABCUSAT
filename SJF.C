#include<stdio.h>
int main()
{
  int p[20],bt[20],at[20],wt,tat,i,j,n,cpu=0,cbt=0,temp,t,x=0;
  float swt=0,stat=0;
  printf("\n enter the number of processes");
  scanf("%d",&n);
  printf("\n enter the process_no,bt,at:");
  for(i=0;i<n;i++)
  {
    scanf("%d",&p[i]);
    scanf("%d",&bt[i]);
    scanf("%d",&at[i]);
    cbt+=bt[i];
  }
  printf("\npr\tbt\tat\twt\ttat");
  while(x<n)
  {  temp=100;
      for(i=0;i<n;i++)
      {
        if(at[i]<=cpu&&p[i]!=0)
        {
            if(bt[i]<temp)
            {
                temp=bt[i];
                t=i;
            }
        }
      }
      cpu=cpu+bt[t];
      tat=cpu-at[t];
      stat=stat+tat;
      wt=tat-bt[t];
      swt=swt+wt;
      printf("\n%d\t%d\t%d\t%d\t%d",p[t],bt[t],at[t],wt,tat);
      p[t]=0;
      x++;
  }
  swt=swt/n;
  stat=stat/n;
  printf("\navgwt:%f\navgtat:%f",swt,stat);
return 0;
}