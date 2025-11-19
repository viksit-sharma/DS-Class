#include <iostream>
using namespace std;
void print(int n)
{
    if (n == 0)
    {
        return;
    }
    cout << "Viksit" << endl;
    print(n - 1);
}
int pow(int n,int p){
    if(p==0){
        return 1;
    }
    return 3 * pow(n, p - 1);
}
int main()
{
    cout<<pow(3,3);
}