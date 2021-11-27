#include "../headers/wjxHeaders.h"

int minMeetingRooms(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    if (n < 2)
    {
        return n;
    }
    sort(intervals.begin(), intervals.end(), [](vector<int> &t1, vector<int> &t2)
         { return t1.front() < t2.front(); });
    for_each(intervals.begin(), intervals.end(), [](auto x)
             { cout << x[0] << "," << x[1] << "\n"; });
    priority_queue<int, vector<int>, std::greater<int>> que;
    que.push(intervals[0][1]);

    for (int i = 1; i < n; ++i)
    {
        int startTime = intervals[i][0];
        int endTime = intervals[i][1];
        if (startTime > que.top())
        {
            que.pop();
            que.push(endTime);
        }
        else if (startTime < que.top())
        {
            que.push(endTime);
        }
    }

    return que.size();
}
int main()
{
    vector<vector<int>> nums{{26, 29}, {19, 26}, {19, 28}, {4, 19}, {4, 25}};
    minMeetingRooms(nums);
}