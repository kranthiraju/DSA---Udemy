#include<bits/stdc++.h>
using namespace std;

// Given an array containing N integers, and an number S denoting a target Sum.
// Find two distinct integers that can pair up to form target sum.
vector<pair<int,int>> paircode(vector<int> arr,int target){
    vector<pair<int,int>> vp;
    int n=arr.size();

    unordered_set<int> st;

    for(int i=0;i<n;i++){
        int x=target-arr[i];
        if(st.find(x)!=st.end()){
            vp.push_back({arr[i],x});
        }
        st.insert(arr[i]);
    }

    return vp;
}

int main(){
    vector<int> arr={10,5,2,3,6,9,11,8};

    for(pair<int,int> i:paircode(arr,16)){
        cout<<"("<<i.first<<" , "<<i.second<<")"<<endl;
    };
    return 0;
}
