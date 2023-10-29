#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
// {key, value}
// Khai bao map: map <datatype1, datatype2> tên_map;
// Mỗi phần tử trong map là 1 pair tức 1 {key, value} đi kèm với nhau
// Các phần tử trong map sắp xếp tăng dần theo key
// Áp dụng map vào bài toán đếm số lần xuất hiện của các phần tử trong mảng
// Có thể đếm số lần xuất hiện của cả xâu bằng cách khai báo map < string , int > mp
// Có cả multimap và unordered_map như kiểu dữ liệu set

int main()
{
	map <int, int> mp;
	// Cach them mot phan tu vao map 
	
	mp[100] = 200; // (100, 200)
	mp[200] = 300; // (200, 300)
	mp.insert({300, 400});
	mp.insert({400, 500});
	cout<<mp.size()<<endl;
	mp[100]=300; // thay the (100,200) = (100,300) , key is unique
	cout<<mp.size()<<endl; // size cua map van khong doi
	
	
	// Duyet qua map
//	for (pair<int, int> x : mp)
//	{
//		cout<< x.first << " " << x.second << endl;
//	}
	
	// Dung auto (recommend vi nhanh)
	for (auto it : mp)
	{
		cout << it.first << " " << it.second << endl;
	}
		
	
	// Dung iterator
//	for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
//	{
//		cout << (*it).first << " " << (*it).second <<endl;
//	}

	// Ham count va find trong map ( tim kiem tren key chu khong tim kiem tren value)
	if (mp.count(200) != 0)
		cout<<"Found! \n";
	else
		cout<<"Not Found! \n";
	
	// Ham erase mp.erase(key) se xoa ca {key, value} cua 1 phan tu trong map
	mp.erase(100);
	for (auto it : mp)
	{
		cout << it.first << " " << it.second << endl;	
	}		
		
	return 0;
}
