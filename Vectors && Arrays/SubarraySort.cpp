#include<bits/stdc++.h>
using namespace std;

/*
Q. Given an array find the smallest subarray that needs to be sorted
in place so that entire input array becomes sorted.
*/

// Brute Force TC=O(NlogN)+O(N)~ O(NlogN);
vector<int> SubarraySort(vector<int> arr){
    int n=arr.size();
    vector<int> b=arr;
    sort(arr.begin(),arr.end());
    int i=0,j=n-1;
    while(i<n && arr[i]==b[i]){
        i++;
    }
    while(j>=0 && arr[j]==b[j]){
        j--;
    }
    return {i,j};
}


int main(){
    cout<<"Subarray Sort = ";
    vector<int> a={1,2,3,4,5,8,6,7,9,10,11};
    cout<<SubarraySort(a)[0]<<" "<<SubarraySort(a)[1];
}
