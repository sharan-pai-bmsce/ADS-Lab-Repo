#include<bits/stdc++.h>

using namespace std;

int find(int arr[],int k){
    int m=k;
    while(arr[m]!=-1){
        // cout<<arr[m]<<endl;
        m=arr[m];
    }
    return m;
}

void unionOp(int arr[],int k,int l){
    int o=find(arr,k);
    int p=find(arr,l);
    if(o==p){
        return;
    }
    arr[o]=p;
}

int main(){
    int m=5,n=5;
    // cin >> m >> n;
    // int island[m][n];
    // for(int i=0;i<m;i++){
    //     for(int j=0;j<n;j++){
    //         cin >> island[i][j];
    //     }
    // }
    int island[5][5] = {
        {1,1,0,0,0},
        {0,1,0,0,1},
        {1,0,0,1,1},
        {0,0,0,0,0},
        {1,0,1,0,1}
    };
    int arr[m*n];
    int k=0;
    int zc=0,mc=0;
    // memset(arr,-1,sizeof(arr));
    for(int i=0;i<m*n;i++){
        arr[i]=-1;
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(island[i][j]==1){
                k=i*m+j;
                if(i==0&&j==0){
                    if(island[i+1][j+1]==1){
                        unionOp(arr,k,(i+1)*m+j+1);
                    }else if(island[i+1][j]==1){
                        unionOp(arr,k,(i+1)*m+j);
                    }else if(island[i][j+1]==1){
                        unionOp(arr,k,(i)*m+j+1);
                    }
                }else if(i==m-1&&j==0){
                    if(island[i-1][j+1]==1){
                        unionOp(arr,k,(i-1)*m+j+1);
                    }else if(island[i-1][j]==1){
                        unionOp(arr,k,(i-1)*m+j);
                    }else if(island[i][j+1]==1){
                       unionOp(arr,k,(i)*m+j+1);
                    }
                }else if(i==0&&j==n-1){
                    if(island[i+1][j-1]==1){
                        unionOp(arr,k,(i+1)*m+j-1);
                    }else if(island[i][j-1]==1){
                        unionOp(arr,k,(i)*m+j-1); 
                    }else if(island[i+1][j]==1){
                       unionOp(arr,k,(i+1)*m+j);
                    }
                }else if(i==m-1&&j==n-1){
                    if(island[i-1][j-1]==1){
                        unionOp(arr,k,(i-1)*m+j-1);
                    }else if(island[i-1][j]==1){
                        unionOp(arr,k,(i-1)*m+j);
                    }else if(island[i][j-1]==1){
                        unionOp(arr,k,(i)*m+j-1);
                    }
                }else if(i==0){
                    if(island[i][j-1]==1){
                        unionOp(arr,k,(i)*m+j-1);
                    }else if(island[i][j+1]==1){
                        unionOp(arr,k,(i)*m+j+1);
                    }else if(island[i+1][j-1]==1){
                        unionOp(arr,k,(i+1)*m+j-1);
                    }else if(island[i+1][j+1]==1){
                        unionOp(arr,k,(i+1)*m+j+1);
                    }else if(island[i+1][j]==1){
                        unionOp(arr,k,(i+1)*m+j);
                    }
                }else if(j==0){
                    if(island[i-1][j]==1){
                        unionOp(arr,k,(i-1)*m+j);
                    }else if(island[i+1][j]==1){
                        unionOp(arr,k,(i+1)*m+j);
                    }else if(island[i+1][j+1]==1){
                        unionOp(arr,k,(i+1)*m+j+1);
                    }else if(island[i-1][j+1]==1){
                        unionOp(arr,k,(i-1)*m+j+1);
                    }else if(island[i][j+1]==1){
                        unionOp(arr,k,(i)*m+j+1);
                    }
                }else if(j==n-1){
                    if(island[i-1][j]==1){
                        unionOp(arr,k,(i-1)*m+j);
                    }else if(island[i+1][j]==1){
                        unionOp(arr,k,(i+1)*m+j);
                    }else if(island[i+1][j-1]==1){
                        unionOp(arr,k,(i+1)*m+j-1);
                    }else if(island[i-1][j-1]==1){
                        unionOp(arr,k,(i-1)*m+j-1);
                    }else if(island[i][j-1]==1){
                        unionOp(arr,k,(i)*m+j-1);
                    }
                }else if(i==m-1){
                    if(island[i][j-1]==1){
                        unionOp(arr,k,(i)*m+j-1);
                    }else if(island[i][j+1]==1){
                        unionOp(arr,k,(i)*m+j+1);
                    }else if(island[i-1][j-1]==1){
                        unionOp(arr,k,(i-1)*m+j-1);
                    }else if(island[i-1][j+1]==1){
                        unionOp(arr,k,(i-1)*m+j+1);
                    }else if(island[i-1][j]==1){
                        unionOp(arr,k,(i-1)*m+j);
                    }
                }else{
                    int p=i-1,q=j-1;
                    for(int p=i-1;p<i+2;p++){
                        for(int q=j-1;q<j+2;q++){
                            if(!(p==i&&q==j)&&island[p][q]==1){
                                unionOp(arr,k,p*m+q);
                            }
                        }
                    }
                }
            }else{
                arr[i*m+j]=0;
            } 
        }
    }
    for(int i=0;i<m*n;i++){
        if(arr[i]==-1){
            mc++;
        }
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<mc<<" "<<zc<<endl;
    return 0;
}