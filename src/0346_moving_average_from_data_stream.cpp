class MovingAverage {
public:
    MovingAverage(int size) {
        maxSize = size;
    }

    double next(int val) {
        if (q.size() == maxSize)
        {
            total -= q.front();
            q.pop();
        }

        total += val;
        q.push(val);

        return static_cast<double>(total) / static_cast<double>(q.size());
    }

private:
    int total = 0;
    int maxSize = 0;
    std::queue<int> q;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */

