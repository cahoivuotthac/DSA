class Solution
{
public:
    // Function to find a continuous sub-array which adds up to a given number.
    //  use two - pointer technique
    vector<int> subarraySum(vector<int> arr, int n, long long s)
    {
        int l = 0, r = 0, sum = 0;
        vector<int> ss;
        if (s == 0)
        {
            ss.push_back(-1);
            return ss;
        }
        for (; r < n; r++)
        {
            sum += arr[r];
            while (sum > s)
            {
                sum -= arr[l];
                l++;
            }
            if (sum == s)
            {
                ss.push_back(l + 1);
                ss.push_back(r + 1);
                return ss;
            }
        }
        if (ss.size() == 0)
        {
            ss.push_back(-1);
            return ss;
        }
    }
};
