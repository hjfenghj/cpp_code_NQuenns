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
		vector<int> record(n,-1);//record[i]��ʾ��i�еĻʺ�����˵�record[i]��
		return process(0, record, n);
	}
	//���[0,i-1]��
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
	int process(int i, vector<int>& record, int n)//Ѱ�ҵ�i�еĻʺ�λ��
	{
		if (i == n)
			return 1;
		int res = 0;
		for (int j = 0; j < n; j++)
		{
			if (isVaild(record, i, j))//�ж�λ��[i][j]�����ûʺ��Ƿ�Ϸ�
			{
				record[i] = j;
				res += process(i + 1, record, n);//Ѱ�ҵ�i+1�лʺ��λ��
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