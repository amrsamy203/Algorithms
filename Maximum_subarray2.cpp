// C++ implementation of the approach 
#include<bits/stdc++.h> 
using namespace std; 
  
struct Node { 
      
    // To store the maximum sum  
    // for a sub-array 
    long long _max; 
      
    // To store the maximum prefix  
    // sum for a sub-array 
    long long _pre; 
      
    // To store the maximum suffix  
    // sum for a sub-array 
    long long _suf; 
      
    // To store the total sum  
    // for a sub-array  
    long long _sum; 
  
}; 
  
  
// Function to create a node 
Node getNode(long long x){ 
    Node a; 
    a._max = x; 
    a._pre = x; 
    a._suf = x; 
    a._sum = x; 
    return a; 
} 
  
// Function to merge the 2 nodes left and right 
Node merg(const Node &l, const Node &r){ 
      
    // Creating node ans 
    Node ans ; 
  
    // Initializing all the variables: 
    ans._max = ans._pre = ans._suf = ans._sum = 0; 
      
    // The max prefix sum of ans Node is maximum of 
    // a) max prefix sum of left Node 
    // b) sum of left Node + max prefix sum of right Node 
    // c) sum of left Node + sum of right Node 
    ans._pre = max({l._pre, l._sum+r._pre, l._sum+r._sum}); 
  
    // The max suffix sum of ans Node is maximum of 
    // a) max suffix sum of right Node 
    // b) sum of right Node + max suffix sum of left Node 
    // c) sum of left Node + sum of right Node 
    ans._suf = max({r._suf, r._sum+l._suf, l._sum+r._sum}); 
      
    // Total sum of ans Node = total sum of left Node + total sum of right Node  
    ans._sum = l._sum + r._sum; 
      
    // The max sum of ans Node stores the answer which is the maximum value among: 
    // prefix sum of ans Node 
    // suffix sum of ans Node 
    // maximum value of left Node 
    // maximum value of right Node 
    // prefix value of left Node + suffix value of right Node 
    ans._max = max({ans._pre, ans._suf, ans._sum,l._max, r._max, l._suf+r._pre}); 
  
    // Return the ans Node 
    return ans; 
} 
  
// Function for calculating the  
// max_sum_subArray using divide and conquer 
Node getMaxSumSubArray(int l, int r, vector<long long> &ar){ 
  
    if (l == r) return getNode(ar[l]); 
  
    int mid = (l + r) >> 1; 
      
    // Call method to return left Node: 
    Node left = getMaxSumSubArray(l, mid, ar); 
      
    // Call method to return right Node: 
    Node right = getMaxSumSubArray(mid+1, r, ar); 
      
    // Return the merged Node: 
    return merg(left, right); 
  
} 
  
// Driver code 
int main(){ 
  
    vector<long long> ar = {-2, -5, 6, -2, -3, 1, 5, -6}; 
    int n = ar.size(); 
    Node ans = getMaxSumSubArray(0, n-1, ar); 
    cout << "Answer is " << ans._max << "\n"; 
  
    return 0; 
} 
