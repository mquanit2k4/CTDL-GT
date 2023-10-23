#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
int main()
{
	vector <int> arr ={23,45,11,77,18};
	int k=3;
	vector <int> res;
    stack<int> st;
    for (int x : arr)
    {
      if (st.empty()==true || st.top() >= x || k==0)
      {
        st.push(x);
      }
      else if (st.top() < x && k > 0)
      {
        st.pop();
        k--;
        if (x > st.top())
        {
            st.pop();
            k--;
        }
        st.push(x);
      } 
    }
    while(!st.empty())
    {
        res.push_back(st.top());
        st.pop();
    }
    reverse(res.begin(), res.end());
    for (auto x : res)
    	cout<<x<<' ';

	return 0;	
}
