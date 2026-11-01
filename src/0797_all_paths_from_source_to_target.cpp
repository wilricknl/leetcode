class Solution {
public:
    void backtrack(
        std::vector<std::vector<int>>& answer,
        std::vector<int>& state,
        int index,
        vector<vector<int>>& graph)
    {
        if (index == graph.size() - 1)
        {
            answer.push_back(state);
            return;
        }

        for (auto node : graph[index])
        {
            state.push_back(node);
            backtrack(answer, state, node, graph);
            state.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)
    {
        std::vector<std::vector<int>> answer;
        std::vector<int> state{ 0 };
        backtrack(answer, state, 0, graph);
        return answer;
    }
};

