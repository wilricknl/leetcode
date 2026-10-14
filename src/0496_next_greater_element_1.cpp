class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int> mapping(10001, -1);
        std::deque<int> d;

        for (int i = nums2.size() - 1; i >= 0; --i)
        {
            int value = nums2[i];
            while (!d.empty() && d.back() < value)
            {
                d.pop_back();
            }
            if (!d.empty())
            {
                mapping[value] = d.back();
            }
            d.push_back(value);
        }

        std::vector<int> answer;
        answer.reserve(nums1.size());
        for (auto num : nums1)
        {
            answer.push_back(mapping[num]);
        }

        return answer;
    }
};

