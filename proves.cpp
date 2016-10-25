#include <iostream>
using namespace std;
int main()
{
    char fg;
    cin>>fg;
    char x[20];
    x[0]='0';
    if(fg==x[0])
    {
        cout<<"It's true!"<<endl;
        return true;

    }
    else    cout<<"It's false!"<<endl;
    return false;
}
