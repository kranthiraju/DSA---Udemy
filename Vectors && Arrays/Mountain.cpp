#include<bits/stdc++.h>
using namespace std;

// write a function that takes input an array of distinct integers,
// and returns the length of highest mountain.

/*
Tricks :
1. Identify peaks (arr[i-1] < arr[i] > arr[i+1]).
2. From peak traverse back until arr[i] < arr[i-1] (while(arr[i-1]<arr[i]) {i--;}).
3. From peak traverse forward until arr[i] < arr[i+1] (while(arr[i+1]<arr[i]) {i++;}).
*/

int heightMountain(vector<int> mountain){
    int n=mountain.size(),peak=mountain[0],ans=0;
    for(int i=1;i<=n-2;i++){
        int j=i,x=1;
        if((mountain[i-1]<mountain[i]) && (mountain[i]>mountain[i+1])){
            // backward
            while(j>=1 && mountain[j]>mountain[j-1]){
                j--;
                x++;
            }
            // forward
            while(i<=n-2 && mountain[i]>mountain[i+1]){
                i++;
                x++;
            }
        }
        ans=max(ans,x);
    }

    return ans;
}

int main(){
    cout<<"Highest Mountain = ";
    vector<int> a={5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4};
    cout<<heightMountain(a);
}
