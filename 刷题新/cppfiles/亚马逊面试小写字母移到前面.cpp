#include "../headers/wjxHeaders.h"


void moveLowerCase(string &in) {
    int n = in.size();
    int idx = 0;
    int right = n-1;
    for(int i=0;i<right;++i) {
        if (in[i]>='a' && in[i]<='z') {
            in[idx++]=in[i];
        }
        else {
            while (right>=0 && in[right]<'a' && in[right]>'z') {
                --right;
            }
            if (right>=0 && i<right) {
                swap(in[right],in[i]);
                --right;
            }
        }
    }
}

int main()
{
    string in="URREREREABadsd";
    cout<<in<<endl;
    moveLowerCase(in);
    
    cout<<in<<endl;
}