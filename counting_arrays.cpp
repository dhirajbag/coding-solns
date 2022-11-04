/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
const int E = 100001;
const long long mod = 1000000007;
long long sum(vector<long long>::iterator start, vector<long long>::iterator end){
    long long res = 0;
    while(start != end){
        res += *start;
        res %= mod;
        start++;
    }
    
    return res;
}

long long naive(vector<int> arr){
    int n  = arr.size();
    sort(arr.begin(), arr.end());
    
    vector<long long> dp(E+1, 0);
    
    for(int num=arr.back(); num>= 0; num--)
        dp[num] = 1ll;
        
    for(int i=n-2; i>=0; i--){
        if(arr[i] == arr[i+1])
            continue;
        vector<long long> new_dp(E+1, 0);
        for(int k=0; k<=arr[i]; k++){
            new_dp[arr[i]-k] = sum( dp.begin()+arr[i]-k, dp.begin()+arr[i+1]-k+1);
        }
        
        dp = move(new_dp);
    }
    
    
    long long res = 0;
    
    for(int num = arr.front(); num >= 0; num--)
        res += dp[num];
        
    return res;
}

long long optimal(vector<int> arr){
    long long res = 1ll;
    sort(arr.begin(), arr.end());
    
    for(int i=1; i<arr.size(); i++){
        res *= (long long)((arr[i]-arr[i-1]+1)%mod);
        res %= mod;
    }
    
    return res;
}


int main()
{
    
    vector<int> input = {0, 100, 4344, 10000, 367, 7895};
    
    cout << naive(input) << " and " << optimal(input) <<endl;
   

    return 0;
}
