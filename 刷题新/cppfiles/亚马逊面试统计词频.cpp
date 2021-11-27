#include "../headers/wjxHeaders.h"

//leetcode  692 前k个高频单词，类似

struct Word
{
    string word;
    int time;
    Word(string _word, int _time) : word(_word), time(_time) {}
};
class Cmp
{
public:
    bool operator()(Word word1, Word word2)
    {
        if (word1.time == word2.time)
        {
            return word1.word > word2.word;
        }
        return word1.time < word2.time;
    }
};
vector<string> FrequentWord(vector<string> &words, int k)
{
    int n = words.size();
    priority_queue<Word, vector<Word>, Cmp> que;

    unordered_map<string, int> mp;
    for (const string &word : words)
    {
        mp[word]++;
    }
    for (const auto &iter : mp)
    {
        que.push(Word(iter.first, iter.second));
    }
    int len = que.size();
    vector<string> ret(len);

    for (int i = 0; i < len; ++i)
    {
        ret[i] = que.top().word;
        que.pop();
    }
    return ret;
}

//现在改进版，如果给你的输入是一个字符串，你应该怎么处理 例如 I love the word,and I am a chinese.

vector<string> FrequentWord(string words) {
    //相当于要截取下单词。。。。
    return {};
}

int main()
{
}