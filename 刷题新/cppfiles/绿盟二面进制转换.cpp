#include <headers/wjxHeaders.h>


string ten2eleven(int _in)  {

	if (_in <11) {
		if (_in==10) {
			return "a";
		}
		else 
			return to_string(_in);
	}
	string ret;
	while (_in>10) {
		int digit = _in%11;
		if (digit==10){
			ret+='a';
		}
		else {
			ret+=digit+'0';
		}
		_in/=11;		
	}
	if(_in==10) {
		ret+='a';
	}
	else {
		ret+=_in+'0';
	}
	reverse(ret.begin(),ret.end());	
	return ret;
}

string eleven2ten(string  _in)  {

    long long ret = 0;
    long base =1;
    for(auto digit = _in.rbegin();digit!=_in.rend();digit++) {
        if (*digit=='a') {
            ret+=10*base;
        }
        else {
            ret+=(*digit-'0')*base;
        }
        base*=11;
    }
    return to_string(ret);

}
int main()
{

}