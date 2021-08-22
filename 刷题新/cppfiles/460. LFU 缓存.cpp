#if 0
#include "../headers/wjxHeaders.h"

//#if 0
//struct Node {
//	int key, val, freq;
//	Node(int _key, int _val, int _freq) :key(_key), val(_val), freq(_freq) {}
//};
//class LFUCache {
//public:
//
//	LFUCache(int capacity):_capacity(capacity),min_freq(0){
//
//	}
//
//	int get(int key) {
//		if (_capacity == 0)
//			return -1;
//		if (key_map.find(key) == key_map.end())
//			return -1;
//		//查找当前key对应的链表迭代器
//		auto nodeiter = key_map[key];
//		int cur_freq = nodeiter->freq;//当前的频率
//		int val = nodeiter->val;//当前的value,最后返回值
//		
//		//需要进行两次删除,因为freq增加了
//		//所以结点应该放在freq+1对应的链表,原来freq对应的链表中应该删除结点
//		//结点放的链表的位置变了,那么结点key对应的链表迭代器应该也变了
//
//		//在freq_map-->当前的频率对应的list中删除node
//		freq_map[cur_freq].erase(nodeiter);
//		//如果当前链表为空,也就是当前频率的结点对应的链表已经没有结点了
//		//我们需要在freq_map中删除这个freq
//		if (freq_map[cur_freq].empty()) {
//			freq_map.erase(cur_freq);//这个频率已经没了,应该删除这个频率的键了
//			//更新min_freq
//			if (min_freq == cur_freq)
//				min_freq += 1;
//		}
//		//把freq+1的结点插入到freq+1 键对应的双链表中
//		freq_map[cur_freq + 1].push_front(Node(key,val, cur_freq +1));
//		key_map[key] = freq_map[cur_freq + 1].begin();
//
//		return val;
//
//	}
//
//	void put(int key, int value) {
//		if (_capacity == 0)
//			return;
//		if (key_map.find(key) == key_map.end()) {//没有这个结点
//			//已经达到最大容量了,删除一个
//			if (key_map.size() == _capacity) {
//				//因为插入都是push_front,所以back()是最久没有访问的
//				auto node = freq_map[min_freq].back();
//				key_map.erase(node.key);//删除
//				freq_map[min_freq].pop_back();
//				if (freq_map[min_freq].empty())
//					freq_map.erase(min_freq);
//			}
//			freq_map[1].push_front(Node(key, value, 1));
//			key_map[key] = freq_map[1].begin();
//			min_freq = 1;
//		}
//		else {//已经有了
//			auto nodeiter = key_map[key];
//			int cur_freq = nodeiter->freq;//保存已经存在的key对应的结点对应的频率
//			
//			//从双链表中进行删除当前key对应的结点
//			freq_map[cur_freq].erase(nodeiter);
//			if (freq_map[cur_freq].empty()) {
//				freq_map.erase(cur_freq);//这个频率没有对应的链表中没有结点了,直接删除这个频率
//				if (min_freq == cur_freq)//更新freq
//					min_freq += 1;
//			}
//			//nodeiter->val = value;
//			//nodeiter->freq++;//put后频率增加
//			//新的结点加入到freq_map中
//			freq_map[cur_freq + 1].push_front(Node(key,value,cur_freq+1));
//			key_map[key] = freq_map[cur_freq + 1].begin();
//		}
//	}
//protected:
//	//freq_map以频率freq为索引,每个索引存放双向链表
//	//链表结点里存放所有freq频率的缓存,包括key,value,freq
//	unordered_map<int, list<Node> > freq_map;
//	//以key为索引
//	unordered_map<int, list<Node>::iterator> key_map;
//	int const _capacity;
//	int min_freq;
//};
//
//#endif 

struct Node {
	int key, value, freq;
	Node(int _key, int _val, int _freq) :key(_key), value(_val), freq(_freq) {}
};
class LFUCache {
public:
	LFUCache(int capacity) :_capacity(capacity) {
		this->min_freq = 0;
	}
	int get(int key) {
		if (_capacity == 0)
			return -1;
		if (key_map.find(key) == key_map.end())
			return -1;
		auto listNode_iter = key_map[key];
		auto listNode = *key_map[key];
		int cur_freq = listNode_iter->freq;
		int retval = listNode_iter->value;

		freq_map[cur_freq].erase(listNode_iter);
		if (freq_map[cur_freq].empty()) {
			freq_map.erase(cur_freq);
			if (min_freq == cur_freq)
				min_freq += 1;
		}
		listNode.freq++;
		freq_map[cur_freq + 1].push_front(std::move(listNode));
		key_map[key] = freq_map[cur_freq + 1].begin();

		return retval;
	}

	void put(int key, int value) {
		if (_capacity == 0)
			return;
		if (key_map.find(key) == key_map.end()) {
			if (key_map.size() == _capacity) {
				auto node = freq_map[min_freq].back();
				freq_map[min_freq].pop_back();
				key_map.erase(node.key);
				if (freq_map[min_freq].empty()) {
					freq_map.erase(min_freq);
				}
			}
			freq_map[1].push_front(Node(key, value, 1));
			key_map[key] = freq_map[1].begin();
			min_freq = 1;
		}
		else {
			auto listNode_iter = key_map[key];
			auto listNode = *key_map[key];
			auto cur_freq = listNode_iter->freq;

			freq_map[cur_freq].erase(listNode_iter);
			if (freq_map[cur_freq].empty()) {
				freq_map.erase(cur_freq);
				if (min_freq == cur_freq)
					min_freq += 1;
			}
			listNode.freq++;
			listNode.value = value;

			freq_map[cur_freq + 1].push_front(listNode);
			key_map[key] = freq_map[cur_freq + 1].begin();
		}
	}
private:
	const int _capacity;
	int min_freq;
	unordered_map<int, list<Node> > freq_map;
	unordered_map<int, list<Node>::iterator > key_map;
};












void test01()
{

	LFUCache lfu(5);
	lfu.put(1,10);
	lfu.put(2, 20);
	lfu.put(3, 30);
	cout << lfu.get(3) << endl;

	
	
}
int main()
{
	test01();
}


#endif