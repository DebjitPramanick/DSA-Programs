// Sorting a vector using Merge Sort

class Solution
{
public:
    vector<int> merge(vector<int> left, vector<int> right)
    {
        vector<int> result;
        while ((int)left.size() > 0 || (int)right.size() > 0)
        {
            if ((int)left.size() > 0 && (int)right.size() > 0)
            {
                if ((int)left.front() <= (int)right.front())
                {
                    result.push_back((int)left.front());
                    left.erase(left.begin());
                }
                else
                {
                    result.push_back((int)right.front());
                    right.erase(right.begin());
                }
            }

            else if ((int)left.size() > 0)
            {
                for (int i = 0; i < (int)left.size(); i++)
                    result.push_back(left[i]);
                break;
            }

            else if ((int)right.size() > 0)
            {
                for (int i = 0; i < (int)right.size(); i++)
                    result.push_back(right[i]);
                break;
            }
        }
        return result;
    }

    vector<int> mergeSort(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return nums;

        vector<int> left, right, result;
        int middle = ((int)nums.size() + 1) / 2;

        for (int i = 0; i < middle; i++)
            left.push_back(nums[i]);

        for (int i = middle; i < (int)nums.size(); i++)
            right.push_back(nums[i]);

        left = mergeSort(left);
        right = mergeSort(right);
        result = merge(left, right);

        return result;
    }

    vector<int> sortArray(vector<int> &nums)
    {
        nums = mergeSort(nums);
        return nums;
    }
};