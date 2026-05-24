#include<stdio.h>

int main(){
    int n,f,faults=0,time=0;
    printf("Enter number of page reference string:");
    scanf("%d",&n);
    int pages[n];
    printf("Enter the reference string:");
    for(int i=0;i<n;i++){
        scanf("%d",&pages[i]);
    }
    printf("Enter number of Page frames:");
    scanf("%d",&f);
    int frames[f],used[10];
    printf("===================================================\n");
    printf("Reference String    Status\n");
    for(int i=0;i<f;i++){
        frames[i]=-1;
        used[i]=0;
    }
    
    for(int i=0;i<n;i++){
        int found=0;
        for(int j=0;j<f;j++){
            if(frames[j]==pages[i]){
                found=1;
                used[j]=++time;
                printf("\t\t%d\t\t\tHit\n",pages[i]);
                break;
            }
        }
        if(!found){
            int min=9999,idx=0;
            for(int j=0;j<f;j++){
                if(frames[j]==-1){
                    idx=j;
                    break;
                }
                if(used[j]<min){
                    min=used[j];
                    idx=j;
                }
            }
            frames[idx]=pages[i];
            used[idx]=++time;
            printf("\t\t%d\t\t\tMiss\n",pages[i]);
            faults++;
        }
    }
    printf("Total number of page fault = %d",faults);
    return 0;
}
