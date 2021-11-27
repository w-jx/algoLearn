#if true
#include "../headers/wjxHeaders.h"

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        stk.reserve(5);
    }
    
    void push(int val) {
        if (stk.empty()) {
            stk.push_back({val,val});
        }
        else {
            int pre_min = stk.back().second;
            if (val<pre_min) {
                stk.push_back({val,val});
            }
            else {
                stk.push_back({val,pre_min});
            }
        }
    }
    
    void pop() {
        stk.pop_back();
    }
    
    int top() {
        return stk.back().first;
    }
    
    int getMin() {
        return stk.back().second;
    }
private:
    vector<std::pair<int,int> > stk;//curnum,minnum;
    
};

void test01()
{

}

int main() {

	test01();
	return 0;
}

#endif