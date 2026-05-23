#include<stdio.h>

int main(){
    int n,f,fault=0,front=0,found;
    printf("Enter number of reference string:");
    scanf("%d",&n);
    int pages[n];
    printf("Enter the reference strings:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&pages[i]);
    }
    printf("Enter number of page frames:");
    scanf("%d",&f);
    int frames[f];
    printf("===============================================\n");
    printf("Reference String  Status\n");
    for(int i=0;i<f;i++){
        frames[i]=-1;
    }
    for(int i=0;i<n;i++){
        found=0;
        for(int j=0;j<f;j++){
            if(frames[j]==pages[i]){
                found=1;
                
                printf("%d\t\t\t\t\tHit\n",pages[i]);
                break;
            }
        }
        if(!found){
            frames[front]=pages[i];
            front=(front+1)%f;
            fault++;
            printf("%d\t\t\t\t\tMiss\n",pages[i]);
        }
    }
    printf("Number of faults = %d",fault);
    
}
