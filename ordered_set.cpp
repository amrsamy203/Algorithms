//For clarification:
//https://codeforces.com/blog/entry/11080
#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
	ordered_set<int>  s;
	s.insert(1); 
	s.insert(4);
	cout << s.order_of_key(2) << endl; // the number of elements in the s less than 2
	cout << *s.find_by_order(0) << endl; // print the 0-th smallest number in s(0-based)
}


/*
Note on using less_equal as comparison function to use it as a multiset:
_GLIBCXX_DEBUG must not be defined, otherwise some internal check will fail.
find will always return end.
lower_bound works like upper_bound in normal set (to return the first element > it)
upper_bound works like lower_bound in normal set (to return the first element >= it)
find_by_order and order_of_key works properly (unlike the 2 functions above).
*/
