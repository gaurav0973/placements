#include<bits/stdc++.h>
using namespace std;


class Students
{
    public:
        string name;
        int age = 20;
        int rollNumber = 1;

};


int main() {
    Students s1;
    s1.name = "gaurav";
    cout << s1.name << " ";
    cout << s1.age << " ";
    cout << s1.rollNumber << " ";

    
    return 0;
}