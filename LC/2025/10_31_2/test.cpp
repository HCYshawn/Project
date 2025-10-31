class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        int n = letters.size();
        int left = 0;
        int right = n - 1;
        char ret = letters[0];
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (letters[mid] == target)
            {
                left = mid + 1;
            }
            else if (letters[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                ret = letters[mid];
                right = mid - 1;
            }
        }
        return ret;
    }
};