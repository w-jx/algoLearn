#if 0
#include "../headers/wjxHeaders.h"

bool isvalid(const char& ch,const int ipkind) {
    if (ipkind==1)
        return ch >= '0' && ch <= '9';
   return (ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'f') || (ch >= 'A' && ch <= 'F'); 
}   
    
string validIPAddress(string ip) {
    if (ip.back() == ':' || ip.back() == '.')
        return "Neither";
    const size_t n = ip.size();
    auto isipv4 = ip.find('.', 0);
    auto isipv6 = ip.find(':', 0);
    string ret = "Neither";//返回的结果

    if (isipv4 < n && isipv6 < n)
        return "Neither";
    else if (isipv4 == std::string::npos && isipv6 == std::string::npos)
        return "Neither";
    stringstream s(ip);
    vector<string> strvec;
    string str;

    //可能是ipv6的情况
    if (isipv4 == std::string::npos && isipv6 < n) {
        while (getline(s, str, ':'))
            strvec.push_back(str);
        if (strvec.size() != 8)
            return ret;
        for (auto str : strvec) {
            if (str.size() > 4 || str.size() < 1)
                return ret;
            for (auto ch : str) {
                if (!isvalid(ch, 2))
                    return ret;
            }
        }
        ret = "IPv6";
    }
    //可能是ipv4的情况
    else {
        while (getline(s, str, '.'))
            strvec.push_back(str);
        //检查 每一个是否符合要求
        if (strvec.size() != 4)
            return ret;
        for (auto iter : strvec) {
            if (iter[0] == '0' && iter.size()>1) {
                return ret;
            }
            if (iter.size() > 3 || iter.size() < 1)
                return ret;
            int num = 0;
            for (auto ch : iter) {
                if (!isvalid(ch,1))
                    return ret;
                num = num * 10 + ch - '0';
            }
            if (num < 0 || num>255)
                return ret;

        }
        ret = "IPv4";

    }
    return ret;
}
void test01()
{
    string ip = "192.168.9.10";
    string ip1 = "2001:0db8:85a3:0:0:8A2E:0370:7334";
    string ip2 = "1e1.4.5.6";
    string ip3 = "2001:0db8:85a3:0:0:8A2E:0370:7334:";
    string ip4 = "12..33.4";
    string ip5 = "20EE:FGb8:85a3:0:0:8A2E:0370:7334";//不是IPV6
    stringstream s(ip4);
    vector<string> strvec;
    string str;
    while (getline(s, str, '.'))
        strvec.push_back(str);
    for (auto iter : strvec)
        cout << iter << " ";
    cout << endl;
    cout << strvec.size() << endl; 
}
void test02()
{
    string ip = "192.0.0.1";
    cout << validIPAddress(ip) << endl;
	

}
int main()
{
	//test01();
    test02();
}
#endif