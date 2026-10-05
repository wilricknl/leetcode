class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        bool isJewel[128]{};

        for (auto jewel : jewels)
        {
            isJewel[jewel] = true;
        }

        int answer = 0;
        for (auto letter : stones)
        {
            if (isJewel[letter])
                ++answer;
        }

        return answer;
    }
};

