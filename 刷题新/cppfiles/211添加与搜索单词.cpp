#if 0
#include "../headers/wjxHeaders.h"
//第一次提交的正确版本
//class WordDictionary {
//public:
//    /** Initialize your data structure here. */
//    WordDictionary() {
//
//    }
//    ~WordDictionary() {
//        for (auto nodeptr : node_vec)
//            delete nodeptr;
//    }
//    void addWord(string word) {
//        TrieNode* ptr = &(this->root);
//        int idx = 0;
//        while (idx < word.size()) {
//            int pos = word[idx] - 'a';
//            if (!ptr->child[pos])
//                ptr->child[pos] = new_node();
//            ptr = ptr->child[pos];
//            ++idx;
//        }
//        ptr->isend = true;
//    }
//
//    bool search(string word) {
//        return _search(&root, word, 0);
//    }
//private:
//    struct TrieNode {
//        TrieNode* child[26];
//        bool isend;
//        TrieNode() :isend(false) {
//            memset(child, 0, sizeof(TrieNode*) * 26);
//        }
//
//    };
//
//    TrieNode root;
//    vector<TrieNode*> node_vec;
//    TrieNode* new_node() {
//        TrieNode* node = new TrieNode;
//        node_vec.push_back(node);
//        return node;
//    }
//
//    bool _search(TrieNode* node, string  word, int idx) {
//        if (idx >= word.size())
//            return node->isend;
//        else if (word[idx] == '.') {
//            for (int i = 0; i < 26; ++i) {
//                if (node->child[i] && _search(node->child[i], word, idx + 1))
//                    return true;
//            }
//        }
//        else {
//            int pos = word[idx] - 'a';
//            if (node->child[pos] && _search(node->child[pos], word, idx + 1))
//                return true;
//        }
//        return false;
//    }
//};
//第二次提交
class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {

    }

    void addWord(string word) {
        TrieNode* ptr = &_root;
        int idx = 0;
        while (idx < word.size()) {
            if (ptr->child.find(word[idx]) == ptr->child.end()) {
                TrieNode* node = new TrieNode;
                ptr->child.insert({ word[idx],node });
                node_vec.push_back(node);
            }
            ptr = ptr->child[word[idx]];
            ++idx;
        }
        ptr->isend = true;
    }

    bool search(string word) {
        return _search(&_root, word, 0);
    }

private:
    struct TrieNode {
        unordered_map<char, TrieNode*> child;
        bool isend;
        TrieNode() :isend(false) {

        }
    };
    vector<TrieNode*> node_vec;
    TrieNode _root;
    bool _search(TrieNode* ptr, string word, int idx) {
        if (idx >= word.size())
            return ptr->isend;
        else if (idx < word.size()) {
            if (word[idx] == '.') {
                for (auto iter : ptr->child) {
                    if (_search(iter.second, word, idx + 1))
                        return true;
                }
            }
            else {
                if (ptr->child.find(word[idx]) != ptr->child.end() && _search(ptr->child[word[idx]], word, 1 + idx))
                    return true;
            }
        }
        return false;
    }
};
void test01()
{

}
int main()
{
	system("pause");
	return 0;
}


#endif