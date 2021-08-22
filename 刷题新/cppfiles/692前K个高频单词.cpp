#if 0
#include "../headers/wjxHeaders.h"
/*
leecode��Ŀ����:


*/
struct Qitem {
    string word;
    int time;
    Qitem(string _word, int _time) :word(_word), time(_time) {}
};
class cmp {
public:
    bool operator()(Qitem q1, Qitem q2) {
        if (q1.time == q2.time)
            return q1.word < q2.word;//���ִ���С����ǰ��,����come first �Ļ���ں���
        return q1.time > q2.time ;
    }
};
/*
["i", "love", "leetcode", "i", "love", "coding"]
2
��ȷ���:["i","love"]
ʵ�����:["love","i"]

*/
vector<string> topKFrequent(vector<string>& words, int k) {
    map<string, int> wordmap;
    priority_queue<Qitem, vector<Qitem>, cmp> que;;

    for (auto word : words) {
        wordmap[word]++;
    }
    for (auto word : wordmap) {
        if (que.size() < k)
            que.push(Qitem(word.first, word.second));
        else {
            if (word.second > que.top().time) {
                que.pop();
                que.push(Qitem(word.first, word.second));
            }
        }
    }
    vector<string> res;
    while (!que.empty()) {
        res.push_back(que.top().word);
        que.pop();
    }
    reverse(res.begin(), res.end());
    
    return res;
}
void test01()
{
    vector<string> words{ "i", "love", "leetcode", "i", "love", "coding"};
    auto res =topKFrequent(words, 2);
    printVector(res);
}
//�����vector<string> ���ֵ�������
void test02()
{
    vector<string> words{ "day","sunny","is","the" };
    //["the","is","sunny","day"]
    sort(words.begin(), words.end(), [](string w1, string w2)->bool
        {return w1 < w2; });
    printVector(words);
}
int main()
{
   test01();
   //test02();
	system("pause");
	return 0;
}
#endif