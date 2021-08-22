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
//		//���ҵ�ǰkey��Ӧ�����������
//		auto nodeiter = key_map[key];
//		int cur_freq = nodeiter->freq;//��ǰ��Ƶ��
//		int val = nodeiter->val;//��ǰ��value,��󷵻�ֵ
//		
//		//��Ҫ��������ɾ��,��Ϊfreq������
//		//���Խ��Ӧ�÷���freq+1��Ӧ������,ԭ��freq��Ӧ��������Ӧ��ɾ�����
//		//���ŵ������λ�ñ���,��ô���key��Ӧ�����������Ӧ��Ҳ����
//
//		//��freq_map-->��ǰ��Ƶ�ʶ�Ӧ��list��ɾ��node
//		freq_map[cur_freq].erase(nodeiter);
//		//�����ǰ����Ϊ��,Ҳ���ǵ�ǰƵ�ʵĽ���Ӧ�������Ѿ�û�н����
//		//������Ҫ��freq_map��ɾ�����freq
//		if (freq_map[cur_freq].empty()) {
//			freq_map.erase(cur_freq);//���Ƶ���Ѿ�û��,Ӧ��ɾ�����Ƶ�ʵļ���
//			//����min_freq
//			if (min_freq == cur_freq)
//				min_freq += 1;
//		}
//		//��freq+1�Ľ����뵽freq+1 ����Ӧ��˫������
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
//		if (key_map.find(key) == key_map.end()) {//û��������
//			//�Ѿ��ﵽ���������,ɾ��һ��
//			if (key_map.size() == _capacity) {
//				//��Ϊ���붼��push_front,����back()�����û�з��ʵ�
//				auto node = freq_map[min_freq].back();
//				key_map.erase(node.key);//ɾ��
//				freq_map[min_freq].pop_back();
//				if (freq_map[min_freq].empty())
//					freq_map.erase(min_freq);
//			}
//			freq_map[1].push_front(Node(key, value, 1));
//			key_map[key] = freq_map[1].begin();
//			min_freq = 1;
//		}
//		else {//�Ѿ�����
//			auto nodeiter = key_map[key];
//			int cur_freq = nodeiter->freq;//�����Ѿ����ڵ�key��Ӧ�Ľ���Ӧ��Ƶ��
//			
//			//��˫�����н���ɾ����ǰkey��Ӧ�Ľ��
//			freq_map[cur_freq].erase(nodeiter);
//			if (freq_map[cur_freq].empty()) {
//				freq_map.erase(cur_freq);//���Ƶ��û�ж�Ӧ��������û�н����,ֱ��ɾ�����Ƶ��
//				if (min_freq == cur_freq)//����freq
//					min_freq += 1;
//			}
//			//nodeiter->val = value;
//			//nodeiter->freq++;//put��Ƶ������
//			//�µĽ����뵽freq_map��
//			freq_map[cur_freq + 1].push_front(Node(key,value,cur_freq+1));
//			key_map[key] = freq_map[cur_freq + 1].begin();
//		}
//	}
//protected:
//	//freq_map��Ƶ��freqΪ����,ÿ���������˫������
//	//��������������freqƵ�ʵĻ���,����key,value,freq
//	unordered_map<int, list<Node> > freq_map;
//	//��keyΪ����
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