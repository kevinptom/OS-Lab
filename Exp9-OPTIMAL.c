#include<stdio.h>

int main(){
    int n,f,k,faults=0;
    printf("Enter number of page reference string:");
    scanf("%d",&n);
    int pages[n];
    printf("Enter the reference string:");
    for(int i=0;i<n;i++){
        scanf("%d",&pages[i]);
    }
    printf("Enter number of Page frames:");
    scanf("%d",&f);
    int frames[f];
    printf("===================================================\n");
    printf("Reference String    Status\n");
    for(int i=0;i<f;i++){
        frames[i]=-1;
    }
    
    for(int i=0;i<n;i++){
        int found=0;
        for(int j=0;j<f;j++){
            if(frames[j]==pages[i]){
                found=1;
                printf("\t\t%d\t\t\tHit\n",pages[i]);
                break;
            }
        }
        if(!found){
            int idx=-1,farthest=i;
            for(int j=0;j<f;j++){
                for(k=i+1;k<n;k++){
                    if(frames[j]==pages[k]){
                        break;
                    }
                }
                if(k>farthest){
                    farthest=k;
                    idx=j;
                }
            }
            if(idx==-1){
                for(int j=0;j<f;j++){
                    if(frames[j]==-1){
                        idx=j;
                        break;
                    }
                }
            }
            frames[idx]=pages[i];
            faults++;
            printf("\t\t%d\t\t\tMiss\n",pages[i]);
        }
    }
    printf("Total number of page fault = %d",faults);
    return 0;
}
