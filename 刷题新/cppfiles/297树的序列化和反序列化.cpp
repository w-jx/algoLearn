#if 0
#include "../headers/wjxHeaders.h"
#include <string>
#include <sstream>
/*
leecode��Ŀ����:


*/
//�ⷨ1:leetcodeӢ�İ� �ⷨ
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)
            return "#";
        return to_string(root->val) + ',' + serialize(root->left) + ',' +
            serialize(root->right);
    }

    // Decodes your encoded data to tree.
    //1,2,#,#,3,4,#,#,5,#,#
    TreeNode* deserialize(string data) {
        return _deserialize(data);
    }
private:
    TreeNode* _deserialize(string &data) {
 /*       cout << "data.size()=" << data.size() << endl;
        cout << "cur data=" << data << endl;*/
        if (data[0] == '#') {
            if (data.size() > 1)//һ�δ�������,����п�������dataֻ��1#�����
                data = data.substr(2);//��Ϊ����"#",�϶�����,����#,��������Ҫ��
            return nullptr;//��Ȼ��#,˵���ǿս��
        }
        else {
            TreeNode* node = new TreeNode(helper(data));
            node->left = _deserialize(data);
            node->right = _deserialize(data);
            return node;

        }
    }
    int helper(string& data) {
        int pos = data.find(',');//pos���±�
        int val = stoi(data.substr(0, pos));//pos�Ǹ���,˵��������,
        data = data.substr(pos + 1);//pos��, ǰ��Ĳ�Ҫ��
        return val;
    }
};

//�ⷨ2:leetcodeӢ�İ� �ⷨ1�Ľ���
class Codec1 {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)
            return "#";
        return to_string(root->val) + ',' + serialize(root->left) + ',' +
            serialize(root->right);
    }

    // Decodes your encoded data to tree.
    //1,2,#,#,3,4,#,#,5,#,#
    TreeNode* deserialize(string data) {
        if (data == "#")
            return nullptr;
        stringstream s(data);
        return makeDeserialize(s);

    }
private:
    TreeNode* makeDeserialize(stringstream& s) {
        string str;
        getline(s, str, ',');
        if (str == "#")
            return nullptr;
        else {
            cout << str << endl;
            TreeNode* root = new TreeNode(stoi(str));
            root->left = makeDeserialize(s);
            root->right = makeDeserialize(s);
            return root;
        }
    }
};

void addNum(int val, string& str) {
    vector<int> num;
    while (val > 0) {
        num.push_back(val % 10);
        val /= 10;
    }
    for (int i = num.size() - 1; i >= 0; --i) {
        str.push_back(i + '0');
    }

}

string _serialize(TreeNode* root) {
    if (!root)
        return "#";
    return to_string(root->val) + ',' + _serialize(root->left) + ',' +
        _serialize(root->right);
}

//2021��5��20�� ��ϰ ��̫��
    // Encodes a tree to a single string.
string serialize(TreeNode* root) {
    if (!root)
        return "#";
    return to_string(root->val) + '#' + serialize(root->left) + '#' + serialize(root->right);
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    if (data == "#")
        return nullptr;
    stringstream s(data);
    return helper(s);
}
TreeNode* helper(stringstream s) {
    string str;
    getline(s, str, '#');

    if (str == "#")
        return nullptr;
    TreeNode* root = new TreeNode(stoi(str));

    root->left = helper(s);
    root->right = helper(s);
    return root;
}
void test01()
{

    string str = "012345abc";
    auto str1 = str.substr(5);//ǰ5����Ҫ��
    cout << str1 << endl;

    auto str2 = str.substr(0, 5);//���±�0��ʼ,��ȡ5��,�����±�0
    cout << str2 << endl;

 int pos = str.find('5');
    cout << pos << endl;
    cout << str.substr(0, pos) << endl;

    string str3 = "#";
    //cout << str3.substr(1) << endl;//���ַ���
    //cout << str3.substr(2)<<endl;//�쳣

    cout << str3.substr(0, 1) << endl;//#
    cout << str3.substr(1, 1) << endl;//��
    cout << str3.substr(0,3) << endl;//��Ȼ��#��
    cout << str3.substr(1, 4) << endl;//��Ȼ�ǿ��ַ���

    TreeNode* root = new TreeNode(1, new TreeNode(2), new TreeNode(3, 4, 5));
    cout << _serialize(root) << endl;
    auto str4 = _serialize(root);

    //Codec c;
    //TreeNode * root1 = c.deserialize(str1);

}

//�ⷨ2 ��stringstream����
void test02()
{
    TreeNode* root = new TreeNode(1, new TreeNode(2), new TreeNode(3, 4, 5));
    //cout << _serialize(root) << endl;
    //auto str4 = _serialize(root);

    //stringstream s(str4);
    //string str;
    //getline(s, str, ',');

    //Codec1 c;
    //auto str = c.serialize(root);
   
    //TreeNode * root1 = c.deserialize(str);



    //recursionTree(root1);
  

}
void test03()
{
    string str("1,2,#,#,3,4,#,#,5,#,#");
    stringstream s(str);
    while (getline(s, str, ',')) {
        cout << str <<" ";
        
    }
    cout << endl;
}
int main()
{
    //test01();
    //test02();
    test03();
	system("pause");
	return 0;
}
#endif