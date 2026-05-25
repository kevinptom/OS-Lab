#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,i,j,total=0;
    printf("Enter number of requests:");
    scanf("%d",&n);
    int req[n];
    int visited[100]={0};
    printf("Enter the requests:");
    for(i=0;i<n;i++){
        scanf("%d",&req[i]);
    }
    printf("Enter intial head:");
    int head;
    scanf("%d",&head);
    int pos=head;
    printf("Seek sequence: %d",pos);
    for(i=0;i<n;i++){
        int min=9999,index=-1;
        for(j=0;j<n;j++){
            if(!visited[j]){
                int dist=abs(pos-req[j]);
            
                if(dist < min){
                    min=dist;
                    index=j;
                }
            }
        }
        visited[index]=1;
        pos = req[index];
        total += min;
        printf(" -> %d",pos);
    }
    printf("Total Seek time = %d",total);
    return 0;
}
