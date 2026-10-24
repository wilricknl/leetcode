class Solution {
public:
    char getLetter(int index)
    {
        switch(index)
        {
            case 0:
                return 'A';
            case 1:
                return 'C';
            case 2:
                return 'G';
            default:
                return 'T';
        }
    }
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        std::unordered_set<std::string> seen;
        std::unordered_set<std::string> valid;
        for (const auto& gene : bank)
        {
            valid.insert(gene);
        }

        if (!valid.contains(endGene))
        {
            return -1;
        }

        if (startGene == endGene)
        {
            return 0;
        }

        std::queue<std::string> q;
        q.push(startGene);
        seen.insert(startGene);

        int distance = 0;
        while (!q.empty())
        {
            int qs = q.size();
            ++distance;

            for (int i = 0; i < qs; ++i)
            {
                auto gene = q.front();
                q.pop();

                for (int index = 0; index < 8; ++index)
                {
                    auto newGene = gene;
                    for (int letter = 0; letter < 4; ++letter)
                    {
                        char newLetter = getLetter(letter);
                        if (newLetter == newGene[index])
                        {
                            continue;
                        }

                        newGene[index] = newLetter;
                        if (!valid.contains(newGene))
                        {
                            continue;
                        }

                        if (newGene == endGene)
                        {
                            return distance;
                        }

                        if (!seen.contains(newGene))
                        {
                            q.push(newGene);
                            seen.insert(newGene);
                        }
                    }
                }
            }
        }

        return -1;
    }
};

