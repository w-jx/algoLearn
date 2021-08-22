#if 0
#include "../headers/wjxHeaders.h"

struct vNode {
    string val;
    int tstamp;
    vNode(string _val,int _tstamp):val(_val),tstamp(_tstamp){}
};
//超时,感觉vector扩容超时,查询次数达到120000次
class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {

    }

    void set(string key, string value, int timestamp) {
        key2time[key].push_back(timestamp);
        time2val.insert({ timestamp,value });
    }

    string get(string key, int timestamp) {
        if (key2time.find(key) == key2time.end())
            return "";
        auto timevec = key2time[key];//得到时间戳数组
        //>=timestamp   --->
        auto pos = lower_bound(timevec.begin(), timevec.end(), timestamp);
        //找不到大于等于timestamp的
        if (pos == timevec.end())//所有的都小于timestamp,所以返回最大的
            return time2val[timevec.back()];
        if (*pos == timestamp)
            return time2val[timestamp];
        int idx = pos - timevec.begin()-1;
    
        if (idx >= 0 && timevec[idx] <= timestamp)
           return time2val[timevec[idx]];
        return "";
        
    }
private:
    unordered_map<string,vector<int> > key2time;//从key找到time时间戳
    unordered_map<int, string > time2val;//从时间戳得到value
};
//想办法,进行避免超时

class TimeMap2 {
public:
    /** Initialize your data structure here. */
    TimeMap2() {

    }

    void set(string key, string value, int timestamp) {
        key2time[key][timestamp] = value;
    }

    string get(string key, int timestamp) {
        if (key2time.find(key) == key2time.end())
            return "";
        //找大于等于timestamp,没找到,,所有的都小于
        if (key2time[key].lower_bound(timestamp) == key2time[key].end()) {
            return key2time[key].rbegin()->second;
        }
        else {//说明找到了大于等于的
            if (key2time[key].begin()->first > timestamp)
                return "";
            auto iter = key2time[key].lower_bound(timestamp);
            if (iter->first == timestamp)
                return key2time[key][timestamp];
            else {
                return (--iter)->second;
            }
        }


    }
private:
    unordered_map<string, map<int,string> > key2time;//从key找到time时间戳
};
void test01()
{
    TimeMap tm;
    tm.set("1", "1", 1);
    tm.set("2", "2", 2);
    //cout << tm.get("1", 3) << endl;
    //cout << tm.get("1", 2) << endl;
    cout << tm.get("1", 1) << endl;
}
int main()
{
	test01();
}
#endif