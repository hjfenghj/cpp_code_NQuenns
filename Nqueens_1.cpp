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
		vector<vector<string>> record(n,vector<string>(n,"."));//record[i]��ʾ��i�еĻʺ�����˵�record[i]��
		return process(0, record, n);
	}
	//���[0,i-1]��
	bool isVaild(vector<vector<string>> record, int i, int j)
	{
		//�����
		for (int k = j - 1; k >= 0; k--)
		{
			if (record[i][k] == "Q")
				return false;
		}
		//�����
		for (int k = i - 1; k >= 0; k--)
		{
			if (record[k][j] == "Q")
				return false;
		}
		//���45��
		int c1, r1;
		for (c1 = i - 1, r1 = j - 1; c1 >= 0 && r1 >= 0; c1--, r1--)
		{
			if (record[c1][r1] == "Q")
				return false;
		}
		//���135��
		for (c1 = i - 1, r1 = j + 1; c1 >=0 && r1  < record.size(); c1--, r1++)
		{
			if (record[c1][r1] == "Q")
				return false;
		}
		return true;
	}
int process(int i, vector<vector<string>>& record, int n)//Ѱ�ҵ�i�еĻʺ�λ��
	{
		if (i == n)
		{
			for (int k1 = 0; k1 < record.size(); k1++)
			{
				for(int k2 = 0; k2 < record.size(); k2++)
				{
					cout << record[k1][k2] << " ";
				}
				cout << endl;
			}
			
			return 1;
		}
		int res = 0;
		for (int j = 0; j < n; j++)
		{
			if (isVaild(record, i, j))//�ж�λ��[i][j]�����ûʺ��Ƿ�Ϸ�
			{
				record[i][j] = "Q";
				res += process(i + 1, record, n);//Ѱ�ҵ�i+1�лʺ��λ��
				record[i][j] = ".";
			}
		}
		return res;
	}
};

int main()
{
	int N = 4;
	NQueeens NQ;
	vector<int> res;
	cout << NQ.num1(N) << endl;;
	return 0;
}