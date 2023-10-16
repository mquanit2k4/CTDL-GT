#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
int x[9][9];
bool check(int v, int r, int c) {
    for (int i = 0; i <= r - 1; i++) {
        if (x[i][c] == v) {
            return false;
        }
    }

    for (int j = 0; j <= c - 1; j++) {
        if (x[r][j] == v) {
            return false;
        }
    }

    int I = r / 3;
    int J = c / 3;
    int i = r - 3 * I;
    int j = c - 3 * J;

    for (int i1 = 0; i1 <= i - 1; i1++) {
        for (int j1 = 0; j1 <= 2; j1++) {
            if (x[3 * I + i1][3 * J + j1] == v) {
                return false;
            }
        }
    }

    for (int j1 = 0; j1 <= j - 1; j1++) {
        if (x[3 * I + i][3 * J + j1] == v) {
            return false;
        }
    }

    return true;
}
void printSolution()
{
	for (int i = 0 ; i < 9 ; i++)
	{
		for (int j = 0 ; j < 9 ; j++)
			cout << x[i][j] << ' ';
		cout<<endl;
	}
	cout << "------------------------"<<endl;
	exit(1);
}

void TRY (int r , int c)
{
	for (int v = 1 ; v <= 9 ; v++)
	{
		if (check(v,r,c))
		{
			x[r][c] = v;
			if (r == 8 && c == 8)
			{
				printSolution();
			}
			else
			{
				if ( c == 8)
					TRY(r+1,0);
				else
					TRY(r,c+1);
			}
		}
	}
}
int main()
{
	TRY(0,0);
	return 0;	
}
