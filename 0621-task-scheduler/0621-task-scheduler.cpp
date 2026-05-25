class Solution {
public:
    int leastInterval(std::vector<char>& tasks, int n) {
        std::unordered_map<char, int> counts;
        int max_freq = 0;
        for (char task : tasks) {
            counts[task]++;
            max_freq = std::max(max_freq, counts[task]);
        }

        int max_freq_tasks = 0;
        for (const auto& [task, count] : counts) {
            if (count == max_freq) {
                max_freq_tasks++;
            }
        }

        int intervals = (max_freq - 1) * (n + 1) + max_freq_tasks;

        return std::max(intervals, static_cast<int>(tasks.size()));
    }
};