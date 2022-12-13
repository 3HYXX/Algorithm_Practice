#include<iostream>

#define MAX_LENGTH 20

using namespace std;

int main()
{
    //输入样例
    int W = 8, B = 7;
    int n = 5;
	int a[5][3] = { {3,2,6},{4,1,5},{6,4,7},{1,1,3},{2,4,8}};

    int m[MAX_LENGTH][MAX_LENGTH][MAX_LENGTH] = {0};

    //边界条件初始化
    int wn = a[n-1][0], bn = a[n-1][1], vn = a[n-1][2];

    for(int j = 0; j <= W; j++)
    {
        for(int k = 0; k <= B; k++)
        {
            if(j >= wn && k >= bn)
                m[n][j][k] = vn;
            else 
                m[n][j][k] = 0;
        }
    }

    
    for(int i = n-1; i > 0 ; i--)
    {
        for(int j = 1; j <= W; j++)
        {
            for(int k = 1; k <= W; k++)
            {
                int wi = a[i-1][0];
                int bi = a[i-1][1];
                int vi = a[i-1][2];
                if(j >= wi && k >= bi)
                    m[i][j][k] = max(m[i+1][j][k], m[i+1][j-wi][k-bi] + vi);
                else
                    m[i][j][k] = m[i+1][j][k];
            }
        }
    }

    
    //输出
    cout  << "Max Value: "<<m[1][W][B] << endl;
	cout <<"Object Number: ";

	for (int i = 1, j = W, k = B; i <= n;i++) 
    {
		if (m[i][j][k] != m[i + 1][j][k]) {
			cout << i << " ";
			j -= a[i-1][0];
			k -= a[i-1][1];
		}
	}
	cout << endl;

	return 0;
}