#include "wjxHeaders.h"

class Int 
{
private:int _num;

public:
    Int():_num(0){}
    Int(int num):_num(num){}
    int getnum() const {
        return this->_num;
    }
    // //++i的实现
    Int& operator++(){
        this->_num++;
        return *this; 
    }
    const int  operator++(int){
        int oldval = this->_num;
        this->_num++;
        return oldval;
    }


   
};
//输出的实现
ostream& operator<<(ostream&out,Int num) 
{
    out<<num.getnum();
    return out;
}

void test01()
{
    Int n = 10;
    cout<<n<<endl;
    ++n;
    cout<<n<<endl;
    n++;
    cout<<n<<endl;
}
int main()
{
	test01();
	
}