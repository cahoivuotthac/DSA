// sum formula
class Solution
{
public:
    int missingNumber(vector<int> &array, int n)
    {
        // size of array is n - 1
        // n is the largest num in array, cause this one has the missing element so its size is n - 1
        int sum = n * (n + 1) / 2;
        int s = 0;
        for (int i = 0; i < n - 1; i++) // time complexity: o(n)
            s += array[i];
        return sum - s; // space: o(1)
    }
    // However, this method can cause overflow if each num of the array is large enough.
};

// XOR method can solve this overflow problem, x^x=0
class Solution
{
public:
    int missingNumber(vector<int> &array, int n)
    {
        int missingnum = 0;
        for(int i = 1; i < n; i++)
            missingnum = i ^ array[i];
        return missingnum;
    }
};