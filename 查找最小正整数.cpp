#include <iostream>
#include <vector>
#include <type_traits>
using namespace std;

int firstMissingPositive(vector<int> nums) {
	int n = nums.size();
	for (int& num : nums)
	{
		if (num <= 0)
			//���ǽ�����������С�ڵ���0�����޸�Ϊ4
			num = n + 1;
	}
	for (int i = 0; i < n; ++i)
	{
		int num = abs(nums[i]);
		if (num <= n)
		{
			nums[num - 1] = -abs(nums[num - 1]);
		}

	}
	for (int i = 0; i < n; ++i)
	{
		if (nums[i] > 0)
		{
			return i + 1;
		}
	}
	return n + 1;
}

int main()
{
	cout << firstMissingPositive({ -1,2,4 ,0}) << endl;
}