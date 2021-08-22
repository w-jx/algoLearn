#if 0
#include "../headers/wjxHeaders.h"
/*
哈希链表
哈希表查找快,数据没有顺序
链表有顺序,插入删除快,查找很慢


C++ list是双链表
C++ unordered_map是哈希表
哈希表的值存储list的迭代器

*/
class LRUCache {
public:
    LRUCache(int capacity) :_capacity(capacity),_size(0){

    }

    int get(int key) {
        if (cachemap.find(key) == cachemap.end())
            return -1;
        /*
        cachemap里面存储的是某个key在链表中的迭代器,而链表中存储的又是键和值
        *cachemap[key] ,先是cachemap[key]得到链表迭代器,再解引用得到pair<int,int>
        直接利用cachemap[key]迭代器,利用erase方法进行链表结点的删除
        然后再头插到链表中,此时这个键值对的位置已经在链表头了
        因此更新cachemap中key对应的位置
        */
        //有这个元素,得到键值对
        auto key_pair = *cachemap[key];//直接解引用,参数2的pair
        cachelist.erase(cachemap[key]);//直接利用迭代器删除链表结点
        cachelist.push_front(key_pair);//链表的元素都是pair,插入到头部

        cachemap[key] = cachelist.begin();
        return key_pair.second;

        
    }

    void put(int key, int value) {
        //里面没有这个元素
        if (cachemap.find(key) == cachemap.end()) {
            //已经达到最大容量了
            if (cachelist.size() == _capacity) {
                //把末尾的删除
                cachemap.erase(cachelist.back().first);
                cachelist.pop_back();
            }
        }
        else {//已经有这个元素了,要更新值
            //只需要在链表中删除那个值,map直接更新下迭代器位置就彳亍
            cachelist.erase(cachemap[key]);//后面还会重新插入的
        }
        cachelist.push_front({ key,value });
        cachemap[key] = cachelist.begin();

    }
private:
    //存储键值对的,key就是具体的键,value是当前键在链表中的迭代器位置
    unordered_map<int, list<std::pair<int,int> >::iterator> cachemap;
    int _size;//链表中容量的大小,没用到,因为直接可以调用cachelist.size();
    int _capacity;//LRU 缓存初始化的容量
    list<std::pair<int,int> > cachelist;
};
//练习
class LRUCache2 {
public:
    LRUCache2(int capacity) :_capacity(capacity) {

    }

    int get(int key) {
        if (hash.find(key) == hash.end())
            return -1;
#if false
        迭代器失效啊, 我靠!!!
            //auto key_iter = hash[key];
            //kv_pair.erase(key_iter);//从list 删除
            //kv_pair.push_front(*key_iter);//添加到队头
            //hash[key] = kv_pair.begin();//更新位置
#endif
        std::pair<int,int>  kvpairitem = *hash[key];
        kv_pair.erase(hash[key]);
        kv_pair.push_front(kvpairitem);
        hash[key] = kv_pair.begin();
        return kvpairitem.second;
    }

    void put(int key, int value) {
        if (hash.find(key) == hash.end()) {
            if (kv_pair.size() == _capacity) {
                hash.erase(kv_pair.back().first);
                kv_pair.pop_back();//删除最后的
            }
            kv_pair.push_front({ key,value });
        }
        else {
            auto kv_iter = *hash[key];
            kv_pair.erase(hash[key]);
            kv_iter.second = value;
            kv_pair.push_front(kv_iter);
        }
        hash[key] = kv_pair.begin();
    }
private:
    unordered_map<int, list<std::pair<int, int> >::iterator> hash;
    list< std::pair<int, int> > kv_pair;
    int _capacity;
};
void test01()
{
    LRUCache2 lru(3);
    lru.put(2, 20);
    lru.put(3, 30);
    lru.put(4, 40);
    cout << lru.get(2) << endl;
    cout << lru.get(3) << endl;
    cout << lru.get(4) << endl;
    lru.put(5, 50);
    cout << lru.get(5) << endl;
    cout << lru.get(2) << endl;
    cout << lru.get(3) << endl;
    cout << lru.get(4) << endl;

}
int main()
{
    test01();
	return 0;
}
#endif