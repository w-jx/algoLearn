#if 0
#include "../headers/wjxHeaders.h"
/*
��ϣ����
��ϣ����ҿ�,����û��˳��
������˳��,����ɾ����,���Һ���


C++ list��˫����
C++ unordered_map�ǹ�ϣ��
��ϣ���ֵ�洢list�ĵ�����

*/
class LRUCache {
public:
    LRUCache(int capacity) :_capacity(capacity),_size(0){

    }

    int get(int key) {
        if (cachemap.find(key) == cachemap.end())
            return -1;
        /*
        cachemap����洢����ĳ��key�������еĵ�����,�������д洢�����Ǽ���ֵ
        *cachemap[key] ,����cachemap[key]�õ����������,�ٽ����õõ�pair<int,int>
        ֱ������cachemap[key]������,����erase���������������ɾ��
        Ȼ����ͷ�嵽������,��ʱ�����ֵ�Ե�λ���Ѿ�������ͷ��
        ��˸���cachemap��key��Ӧ��λ��
        */
        //�����Ԫ��,�õ���ֵ��
        auto key_pair = *cachemap[key];//ֱ�ӽ�����,����2��pair
        cachelist.erase(cachemap[key]);//ֱ�����õ�����ɾ��������
        cachelist.push_front(key_pair);//�����Ԫ�ض���pair,���뵽ͷ��

        cachemap[key] = cachelist.begin();
        return key_pair.second;

        
    }

    void put(int key, int value) {
        //����û�����Ԫ��
        if (cachemap.find(key) == cachemap.end()) {
            //�Ѿ��ﵽ���������
            if (cachelist.size() == _capacity) {
                //��ĩβ��ɾ��
                cachemap.erase(cachelist.back().first);
                cachelist.pop_back();
            }
        }
        else {//�Ѿ������Ԫ����,Ҫ����ֵ
            //ֻ��Ҫ��������ɾ���Ǹ�ֵ,mapֱ�Ӹ����µ�����λ�þ���ء
            cachelist.erase(cachemap[key]);//���滹�����²����
        }
        cachelist.push_front({ key,value });
        cachemap[key] = cachelist.begin();

    }
private:
    //�洢��ֵ�Ե�,key���Ǿ���ļ�,value�ǵ�ǰ���������еĵ�����λ��
    unordered_map<int, list<std::pair<int,int> >::iterator> cachemap;
    int _size;//�����������Ĵ�С,û�õ�,��Ϊֱ�ӿ��Ե���cachelist.size();
    int _capacity;//LRU �����ʼ��������
    list<std::pair<int,int> > cachelist;
};
//��ϰ
class LRUCache2 {
public:
    LRUCache2(int capacity) :_capacity(capacity) {

    }

    int get(int key) {
        if (hash.find(key) == hash.end())
            return -1;
#if false
        ������ʧЧ��, �ҿ�!!!
            //auto key_iter = hash[key];
            //kv_pair.erase(key_iter);//��list ɾ��
            //kv_pair.push_front(*key_iter);//��ӵ���ͷ
            //hash[key] = kv_pair.begin();//����λ��
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
                kv_pair.pop_back();//ɾ������
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