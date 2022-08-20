#include<bits/stdc++.h>
using namespace std;

// Given an array containing N intergers and an number S denoting a target sum.
// Find all distinct integers that can add up to form target sum.
// The numbers in each triplets should be ordered too.

vector<vector<int>> Triplet(vector<int> arr,int target){
    vector<vector<int>> vv;
    sort(arr.begin(),arr.end());
    for(int i=0;i<=arr.size()-3;i++){
        int low=i+1,high=arr.size()-1,sum=target-arr[i];
        while(low<high){
            if(arr[low]+arr[high]>sum){
                high--;
            }
            else if(arr[low]+arr[high]<sum){
                low++;
            }
            else{
                vv.push_back({arr[i],arr[low],arr[high]});
                low++;
                high--;
            }
        }
    }
    return vv;
}

int main(){
    vector<int> a={2,5,4,3,6,1,7,8,9,15};

    cout<<"Triplets"<<endl;
    for(auto i :Triplet(a,18)){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
