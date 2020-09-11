#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <vector>
#include <fstream>
#include <sstream>
#include <string.h>
#include <memory>
#include <limits>
#include <list>
#include <regex>
#include <functional>
#include <math.h>
#include <unordered_set>
using namespace std;

/*
begin:
end:
Time Complexity:
Space Complexity:
Method:
*/
class Solution
{
    int cnt = 0;
public:
    void merge(vector<int> &nums, int l, int mid, int r, vector<int> &temp)
    {
        int i = l, j = mid + 1, k = l;
        while (i <= mid && j <= r)
        {
            if (nums[i] <= nums[j])
                temp[k++] = nums[i++];
            else
            {
                temp[k++] = nums[j++];
                cnt += (mid - i + 1) % 1000000007;
            }
        }
        while (i <= mid)
            temp[k++] = nums[i++];
        while (j <= r)
            temp[k++] = nums[j++];
        for (int i = l; i <= r; i++)
            nums[i] = temp[i];
    }

    void mergesort(vector<int> &nums, int l, int r, vector<int> &temp)
    {
        if (l < r)
        {
            int mid = (l + r) >> 1;
            mergesort(nums, l, mid, temp);
            mergesort(nums, mid + 1, r, temp);
            merge(nums, l, mid, r, temp);
        }
    }

    int InversePairs(vector<int> data)
    {
        if (data.empty())
            return 0;
        vector<int> temp(data.size());
        mergesort(data, 0, data.size() - 1, temp);
        return cnt;
    }
};

int main()
{
    vector<int> vec;
    Solution s;
    cout << s.InversePairs(vec) << endl;
    return 0;
}
