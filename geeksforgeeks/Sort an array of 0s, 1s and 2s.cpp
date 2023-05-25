// using dutch national flag algorithms
class Solution
{
public:
    void sort012(int a[], int n)
    {
        int low = 0, mid = 0, high = n - 1;
        while (mid <= high)
        {
            if (a[mid] == 0)
            {
                if (a[low] != 0) swap(a[mid], a[low]);
                mid++;
                low++;
            }
            else if (a[mid] == 1) mid++;
            else if (a[mid] == 2)
            {
                if (a[high] != 2) swap(a[mid], a[high]);
                high--;
            }
        }
    }
};

