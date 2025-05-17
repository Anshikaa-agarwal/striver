#include <iostream>
#include <vector>
using namespace std;

int second(vector<int> &nums)
{
    int largest = INT32_MIN;
    int slargest = INT32_MIN;
    int i = 0;

    for (i = 0; i < nums.size(); i++)
    {
            if (nums[i] > largest)
            {
                slargest = largest;
                largest = nums[i];
            }
            else if(nums[i] > slargest && nums[i] != largest)
            {
                slargest = nums[i];
            }
    }
    if(slargest == INT32_MIN) return -1;
    else return slargest;
}
int main() {
    vector<int> arr = {8};
    cout << second(arr);
}