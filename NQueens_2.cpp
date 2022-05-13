#include<iostream>
#include<queue>
using namespace std;

class NQueeens
{
public:
	int num1(int n)
	{
		if (n < 1)
			return 0;
		vector<int> record(n,-1);//record[i]表示第i行的皇后放在了第record[i]列
		return process(0, record, n);
	}
	//检查[0,i-1]行
	bool isVaild(vector<int> record, int i, int j)
	{
		for (int k = 0; k < i; k++)
		{
			if (record[k]==j  || abs(i-k)==abs(j-record[k]))
			{
				return false;
			}
		}
		return true;
	}
	int process(int i, vector<int>& record, int n)//寻找第i行的皇后位置
	{
		if (i == n)
			return 1;
		int res = 0;
		for (int j = 0; j < n; j++)
		{
			if (isVaild(record, i, j))//判断位置[i][j]处安置皇后是否合法
			{
				record[i] = j;
				res += process(i + 1, record, n);//寻找第i+1行皇后的位置
			}
		}
		return res;
	}
};

int main()
{
	int N = 5;
	NQueeens NQ;
	vector<int> res;
	cout << NQ.num1(N) << endl;;
	return 0;
}