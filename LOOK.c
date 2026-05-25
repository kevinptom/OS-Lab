#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,total=0,i,j,head;
    printf("Enter number of requests:");
    scanf("%d",&n);
    int req[n];
    printf("Enter the requests:");
    for(i=0;i<n;i++){
        scanf("%d",&req[i]);
    }
    printf("Enter initial head:");
    scanf("%d",&head);
    int pos = head;
    int right[100],left[100];
    int l=0,r=0;
    for(i=0;i<n;i++){
        if(req[i] < head) left[l++]=req[i];
        else right[r++]=req[i];
    }
    for(i=0;i<l-1;i++){
        for(j=i+1;j<l;j++){
            if(left[i]>left[j]){
                int t=left[i];left[i]=left[j];left[j]=t;
            }
        }
    }
    for(i=0;i<r-1;i++){
        for(j=i+1;j<r;j++){
            if(right[i]>right[j]){
                int t=right[i];right[i]=right[j];right[j]=t;
            }
        }
    }
    printf("Seek Sequence: %d",pos);
    for(i=0;i<r;i++){
        total += abs(pos-right[i]);
        pos = right[i];
        printf(" %d ->",pos);
        
    }
    for(i=l-1;i>=0;i--){
        total += abs(pos-left[i]);
        pos = left[i];
        printf(" -> %d ",pos);
        
    }
    printf("\nTotal sek time = %d",total);
    return 0;
}
