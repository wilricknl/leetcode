class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms)
    {
        std::vector<char> unlocked(1000, false);
        std::queue<int> q;

        q.push(0);
        int roomCounter = 1;
        unlocked[0] = true;

        while (!q.empty())
        {
            auto key = q.front();

            for (auto room : rooms[key])
            {
                if (!unlocked[room])
                {
                    unlocked[room] = true;
                    ++roomCounter;
                    q.push(room);
                }
            }

            q.pop();
        }

        return roomCounter == rooms.size();    
    }
};

