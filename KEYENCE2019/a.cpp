#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> nums(4);
    for (int i = 0; i < 4; i++)
    {
        scanf("%d", &nums[i]);
    }
    sort(nums.begin(), nums.end());

    printf("%s\n", nums[0] == 1 && nums[1] == 4 && nums[2] == 7 && nums[3] == 9 ? "YES" : "NO");

    return 0;
}