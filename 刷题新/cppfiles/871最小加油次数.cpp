#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:
汽车从起点出发驶向目的地，该目的地位于出发位置东面 target 英里处。

沿途有加油站，每个 station[i] 代表一个加油站，它位于出发位置东面 station[i][0] 英里处，并且有 station[i][1] 升汽油。

假设汽车油箱的容量是无限的，其中最初有 startFuel 升燃料。它每行驶 1 英里就会用掉 1 升汽油。

当汽车到达加油站时，它可能停下来加油，将所有汽油从加油站转移到汽车中。

为了到达目的地，汽车所必要的最低加油次数是多少？如果无法到达目的地，则返回 -1 。

注意：如果汽车到达加油站时剩余燃料为 0，它仍然可以在那里加油。如果汽车到达目的地时剩余燃料为 0，仍然认为它已经到达目的地。


*/

/// <summary>
/// 刷题教程的解法
/// </summary>
/// <param name="target">目标距离</param>
/// <param name="startFuel">初始的时候油数量</param>
/// <param name="stations">加油站距离起点位置和加油站的油的数量</param>
/// <returns></returns>
int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
	std::priority_queue<int> Q;//存储油量的最大堆

	int result = 0;//记录加油次数

	stations.push_back({ 0,0 });//把终点也作为一个停靠点，添加到数组里面

	std::sort(stations.begin(), stations.end(), [](vector<int>& s1, vector<int>& s2)->bool {
		return s1.front() < s2.front();
		});//按照距离起点位置从小到大排序，也就是距离终点距离 从大到小排序

	for (int i = 0; i < stations.size(); ++i) {//遍历加油站
		int dis = target - stations[i].front();//当前要走的距离即为 当前距离终点的距离
		while (dis > startFuel && !Q.empty()) { //油不够走的时候，同时有可以加的油
			startFuel += Q.top();//加点油
			Q.pop();
			++result;
		}//如果加了以后还不够走，那就接着加
		if (Q.empty() && startFuel < dis)//距离不够走了，同时也没有 油可以加了
			return -1;
		startFuel -= dis;
		target = stations[i].front();//更新下距离为当前加油站到终点距离
		Q.push(stations[i].back());//将当前 加油站的汽油量 加到最大堆中
	}
	return result;
}
//这个是我按照思路写的，感觉好理解一点
int minRefuelStops2(int target, int startFuel, vector<vector<int>>& stations) {
	if (stations.empty() && startFuel < target)
		return -1;//无法加油,初始油不够到加油站
	if (!stations.empty() && startFuel < stations.front().front())
		return -1;//初始油到不了第一个加油站
	priority_queue<int> fuel_que;
	int size = stations.size();
	stations.push_back({ target,0 });
	//先到达第一个加油站,同时把第一个加油站的油加入到堆中
	startFuel -= stations.front().front();
	fuel_que.push(stations.front().back());
	int times = 0;
	for (int i = 1; i < stations.size(); i++) {
		int costFuel = stations[i].front() - stations[i - 1].front();
		//现在的油能够到达这个加油站,那么就减去开销的油,把加油站能加油的数量加入到堆
		if (startFuel >= costFuel) {
			startFuel -= costFuel;
			fuel_que.push(stations[i].back());
		}
		else {//当前的油到不了这个加油站
			if (fuel_que.empty())
				return -1;
			while (!fuel_que.empty()) {
				startFuel += fuel_que.top();
				fuel_que.pop();
				times++;
				if (startFuel >= costFuel) {
					break;
				}
			}
			if (startFuel >= costFuel) {
				startFuel -= costFuel;
				fuel_que.push(stations[i].back());
			}
			else
				return -1;
		}
	}
	return times;

}
//2021年5月16日复习,无法通过
/*
100
10
[[10,60],[20,30],[30,30],[60,40]]
*/
int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
	if (stations.empty() && startFuel < target)
		return -1;
	if (!stations.empty() && startFuel < stations.front().front())
		return -1;
	stations.push_back({ target,0 });
	int times = 0;
	priority_queue<int> que;//大顶堆
	//stations[i][0]是距离,[i][1]是汽油
	startFuel -= stations[0][0];
	que.push(stations[0][1]);
	for (int i = 1; i < stations.size();) {
		//到下一个加油站的距离
		int distance = stations[i][0] - stations[i - 1][0];
		if (startFuel >= distance) {
			startFuel -= distance;
			que.push(stations[i][1]);
			++i;

		}
		else {//油不够了
			if (que.empty())//没有油可以加了
				return -1;
			while (!que.empty() && startFuel < distance) {
				startFuel += que.top();
				que.pop();
				++times;
			}
			if (startFuel >= distance) {
				startFuel -= distance;
				que.push(stations[i][1]);
				++i;
			}
			else
				return -1;

		}
	}
	return times;
}
void test01()
{
	vector<vector<int> > stations{
		{10, 60},
		{ 20,30 },
		{ 30,30 },
		{ 60,40 },
		{ 100,0 }
	};
	cout << minRefuelStops2(100, 10, stations) << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif