#include<bits/stdc++.h>
using namespace std;

/*
1. Left array contains max of left elements of that current element.
2. Right array contains max of right elements of that current element.
3. water content is difference of min of left and right of current element and current element.
*/

int Rain(vector<int> arr){
    int n=arr.size(),left_max=0,right_max=0,rain=0;

    vector<int> left(n,0),right(n,0);
    left[0]=arr[0],right[n-1]=arr[n-1];
    for(int i=1;i<n;i++){
        left[i]=max(left[i-1],arr[i]);
        right[n-i-1]=max(right[n-i],arr[n-i-1]);
    }

    for(int i=0;i<n;i++){
        rain+=(min(left[i],right[i])-arr[i]);
    }

    return rain;
}

int main(){
    cout<<"Rain Tapping = ";
    vector<int> a={0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<Rain(a);
}
