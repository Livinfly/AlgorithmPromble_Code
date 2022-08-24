#include <iostream>

using namespace std;

const int P = 47;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int a1 = 1, a2 = 1;
    for(int i = 0; i < s1.size(); i ++)
        a1 = a1 * (s1[i] - 'A' + 1) % P;
    for(int i = 0; i < s2.size(); i ++)
        a2 = a2 * (s2[i] - 'A' + 1) % P;
    
    if(a1 == a2) puts("GO");
    else puts("STAY");
    
    return 0;
}
