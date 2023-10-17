#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
// Duyet vector
void printElementsOfVector (vector <int> v)
{
	for (auto x : v)
		cout << x << ' ';
	cout<<endl;
}

// Duyet vector kieu string
void printElementsOfVectorString (vector <string> v)
{
	for (auto x : v)
		cout << x << ' ';
	cout<<endl;
}
// Hàm khai báo và trả về vector gồm n phần tử với các phần tử có giá trị từ 1 tới n
vector <int> initializeVector(int n)
{
	vector <int> res;
	for(int i=1; i<=n; i++)
		res.push_back(i);
	return res;
}

// Cho một vector kiểu số nguyên v là đầu vào của hàm, hãy trả về tổng các phần tử trong vector này
int sumOfVectorElements (vector <int> v)
{
	int res = 0;
	for (int i=0 ; i<v.size(); i++)
		res += v[i];
	return res;	
} 

// Cho một vector chứa các số nguyên, bạn hãy viết hàm trả về tổng của các phần tử lẻ trong vector đó
int sumOfOddElements ( vector <int> v)
{
	int result = 0;
	for (int i=0 ; i<v.size(); i++)
		if (v[i]%2 != 0 )
			result += v[i];
	return result;
}

// Cho trước một vector và một số tự nhiên n, hãy thay đổi kích thước của vector đó về n
// Để thay đổi kích thước của vector v về n, bạn có thể sử dụng hàm v.resize(n). Nếu n lớn hơn kích thước hiện tại của vector thì vector sẽ tự động thêm vào các phần tử có giá trị bằng 0 
// Ngược lại, nếu n nhỏ hơn kích thước của vector v thì các phần tử có chỉ số lớn hơn hoặc bằng n sẽ bị xóa đi

vector <int> resizeVector (vector <int> v , int n)
{
	v.resize(n);
	return v;
}

// Cho một vector các số nguyên v, hãy sắp xếp các số nguyên trong vector này theo thứ tự tăng dần.
vector <int> sortVector (vector <int> v)
{
	for( int i = 0 ; i<v.size(); i++)
		for( int j = i+1 ; j<v.size() ; j++)
			if (v[i] > v[j])
				swap(v[i],v[j]);
	return v;
}

// Cho một vector chứa các số nguyên, hãy tìm giá trị lớn nhất của tích của 2 số nguyên liên tiếp trong vector (đầu vào luôn đảm bảo vector có ít nhất 2 phần tử).
int maxProductOfAdjacentElements( vector <int> v)
{
	int max = v[0]*v[1];
	for( int i = 1 ; i < v.size()-1 ; i++)
	{
		int temp = v[i]*v[i+1];
		if (temp > max)
			max=temp;
	}
	return max;
}

// Cho một vector chứa các xâu kí tự, bạn hãy viết hàm tìm những xâu có độ dài lớn nhất trong vector ban đầu và trả về kết quả tương ứng.
vector <string> findLongestStrings ( vector <string> arr)
{
	int max = arr[0].size();
	for ( int i = 1; i<=arr.size() ; i++)
	{
		int temp = arr[i].size();
		if (temp > max)
			max=temp;
	}
	vector <string> result;
	for (int i = 0 ; i < arr.size() ; i++)
		if (arr[i].size() == max)
			result.push_back(arr[i]);
	return result;
}

// Cho trước một vector các số nguyên v, bạn hãy viết hàm xóa phần tử cuối cùng trong vector này và trả về vector tương ứng sau khi xóa.
vector <int> removeLastElement( vector<int> v )
{
	v.pop_back();
	return v;
}
// Cho vector gồm các số nguyên v. Bạn hãy viết hàm trả về tổng của phần tử đầu tiên và cuối cùng trong vector đó.
int sumOfFirstAndLastElement ( vector <int> v) 
{
	return v.front() + v.back();
}

// Cho trước vector v và hai số nguyên l, r. Bạn hãy viết hàm xóa đi các phần tử có chỉ số từ l tới r trong vector v và trả về vector kết quả tương ứng
// Để xóa các phần tử trong vector bạn có thể dùng hàm erase(first, last). Trong đó first và last là 2 iterator

vector<int> removeElements ( vector<int> v, int l, int r)
{
	v.erase(v.begin()+l , v.begin() + r + 1);
	return v;
}
int main()
{
	int n = 3;
	vector <int> v = {1,5,6,43,65,3,-6,-10,0};
	vector <string> arr = {"aba", "aa", "ad", "vcd", "aba"};
	printElementsOfVector(initializeVector(n));
	cout << sumOfVectorElements(initializeVector(n)) << endl;
	cout << sumOfOddElements(initializeVector(n)) << endl;
	printElementsOfVector(resizeVector(v, 5));
	printElementsOfVector(sortVector(v));
	cout << maxProductOfAdjacentElements(v) << endl;
	printElementsOfVectorString(findLongestStrings(arr));
	printElementsOfVector(removeLastElement(v));
	cout << sumOfFirstAndLastElement(v) <<endl;
	printElementsOfVector(removeElements(v,2,4));
	return 0;	
}
