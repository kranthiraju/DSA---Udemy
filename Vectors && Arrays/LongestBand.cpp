#include<bits/stdc++.h>
using namespace std;

/*
Q. Given an array of N integers, find length of longest band.
Band --> a subsequence which can be reordered in such a manner all elements appear
consecutive.
*/
int LongestBand(vector<int> arr){
    // O(NlogN)+O(N)
    int n=arr.size(),ans=INT_MIN,c=1;
    sort(arr.begin(),arr.end());
    for(int i=1;i<n;i++){
        if(abs(arr[i]-arr[i-1])==1){
            c++;
        }
        else{
            c=1;
        }
        ans=max(ans,c);
    }
    return ans;
}

// TC = O(N)+O(N)
int LongestBandON(vector<int> arr){
    int n=arr.size(),c=0,ans=INT_MIN;
    unordered_set<int> st;
    for(int i=0;i<n;i++){
        st.insert(arr[i]);
    }
    for(auto i:st){
        c=0;
        if(st.find(i-1)==st.end()){
            // find entire band / chain starting from i.
            while(st.find(i++)!=st.end()){
                c++;
            }
        }
        ans=max(ans,c);
    }
    return ans;
}

int main(){
    cout<<"Longest Band = ";
    vector<int> a={1,9,3,0,18,5,2,4,10,7,12,6};
    cout<<LongestBandON(a);
}
