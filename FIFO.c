#include<stdio.h>

int main(){
    int i,j,n,p[20],f[20],fn,found,ct=0,fault=0;

    printf("Enter the number of pages: ");
    scanf("%d", &n);

    printf("\nEnter the sequence: ");
    for(i=0;i<n;i++){
       scanf("%d", &p[i]); 
    }

    printf("Enter the number of frames:");
    scanf("%d", &fn);

    for(j=0;j<fn;j++){
        f[j] = -1;
    }

    for(i=0; i<n; i++){

        found=0;
        for(j=0; j<fn; j++){
            if(p[i]==f[j]){
                found=1;
                break;
            }
        }

        if(found==0){
            fault++;
            for(j=0;j<fn;j++){
                if(f[j]==-1)
                {
                    f[j]=p[i];
                    goto l1;
                }
            }
            f[ct] = p[i];
            ct = (ct+1) % fn;
        }
    l1:
        for(j=0;j<fn;j++){
            printf("%d\t", f[j]);
        }
        printf("\n");
    }
    printf("Total page fault: %d", fault);
    
}