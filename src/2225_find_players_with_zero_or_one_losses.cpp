class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        static int players[100001]; // -1 means not played
        std::fill(players, players + 100001, -1);

        int maxId = 0;
        for (const auto& match : matches)
        {
            int winner = match[0];
            int loser = match[1];
            
            if (players[winner] == -1)
                players[winner] = 0;
            if (players[loser] == -1)
                players[loser] = 1;
            else
                players[loser]++;

            maxId = std::max({maxId, winner, loser});
        }

        std::vector<std::vector<int>> answer(2);
        for (int i = 1; i <= maxId; ++i)
        {
            if (players[i] == 0 || players[i] == 1)
                answer[players[i]].push_back(i);
        }

        return answer;
    }
};

