#if 0
#include "../headers/wjxHeaders.h"

struct vNode {
    string val;
    int tstamp;
    vNode(string _val,int _tstamp):val(_val),tstamp(_tstamp){}
};
//��ʱ,�о�vector���ݳ�ʱ,��ѯ�����ﵽ120000��
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
        auto timevec = key2time[key];//�õ�ʱ�������
        //>=timestamp   --->
        auto pos = lower_bound(timevec.begin(), timevec.end(), timestamp);
        //�Ҳ������ڵ���timestamp��
        if (pos == timevec.end())//���еĶ�С��timestamp,���Է�������
            return time2val[timevec.back()];
        if (*pos == timestamp)
            return time2val[timestamp];
        int idx = pos - timevec.begin()-1;
    
        if (idx >= 0 && timevec[idx] <= timestamp)
           return time2val[timevec[idx]];
        return "";
        
    }
private:
    unordered_map<string,vector<int> > key2time;//��key�ҵ�timeʱ���
    unordered_map<int, string > time2val;//��ʱ����õ�value
};
//��취,���б��ⳬʱ

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
        //�Ҵ��ڵ���timestamp,û�ҵ�,,���еĶ�С��
        if (key2time[key].lower_bound(timestamp) == key2time[key].end()) {
            return key2time[key].rbegin()->second;
        }
        else {//˵���ҵ��˴��ڵ��ڵ�
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
    unordered_map<string, map<int,string> > key2time;//��key�ҵ�timeʱ���
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