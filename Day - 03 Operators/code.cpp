#include <iostream>
#define X 25 // Macro (Symbolic Constant)
#define ll long long
using namespace std;

int main(){
    // Constants
    const int num = 25; // must be initialized
    int num2 = 50;
    // num = 75; // Error: Assignment of read-only variable 'num'
    num2 = 100;
    const float PI = 3.14;
    const float g = 9.8;
    const int Y = 35;
    cout << "X: " << X << endl; // Donot take memory
    cout << "Y: " << Y << endl; // Take memory
    ll x;
    ll y = 10000000;

    // Typecasting
    // Implicit Conversion
    cout<<(10/3)<<endl; // 3
    cout<<(10/3.0)<<endl; // 3.33333
    cout<<('A' + 1)<<endl; // 66
    cout<<('a' + 0)<<endl; // B

    // Explicit Conversion
    float Pi = 3.14;
    cout<<(int)(Pi)<<endl; // 3
    cout<<((float)10/3)<<endl; // 3.33333
    cout<<(int)('A')<<endl; // 65
    cout<<(char)('A' + 1)<<endl; // B

    // Practice Questions
    cout<<((bool)3+2)<<endl; // 3
    cout<<(23.5 + 2 + 'A')<<endl; // 90.5

    return 0;
}