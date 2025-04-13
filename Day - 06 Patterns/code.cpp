#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    // Outer Loop
    for(int i=1; i<=n; i++) {
        // Inner Loop
        for(int j=1; j<=n; j++) {
            // Work
            cout << i << " ";
        }
        cout << endl;
    }

    // Star Pattern
    int p;
    cout << "Enter p: ";
    cin >> p;
    for (int i=1; i<=p; i++) {
        for (int j=1; j<=i; j++) {
            cout << "*" << " ";
        }
        cout << endl;
    }

    // Inverted Star Pattern
    int q;
    cout << "Enter q: ";
    cin >> q;
    for (int i=1; i<=q; i++) {
        for (int j=1; j<=n-i+1; j++) {
            cout << "*" << " ";
        }
        cout << endl;
    }

    // Half Pyramid Pattern
    int r;
    cout << "Enter r: ";
    cin >> r;
    for (int i=1; i<=r; i++) {
        for (int j=1; j<=i; j++) {
            cout << j << " ";
        }
        cout << endl;
    }

    // Character Pyramid Pattern
    char ch = 'A';
    int s;
    cout << "Enter s: ";
    cin >> s;
    for (int i=1; i<=s; i++) {
        for (int j=1; j<=i; j++) {
            cout << ch++;
        }
        cout << endl;
    }

    // Hollow Rectangle Pattern
    int t;
    cout << "Enter t: ";
    cin >> t;
    for(int i=1; i<=t; i++) {
        cout << "*";            // First Row
        for(int j=1; j<=t-1; j++) {
            if(i==1 || i==t) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << "*" << endl;    // Last Row
    }

    // Inverted & Rotated Half Pyramid Pattern
    int a;
    cout << "Enter a: ";
    cin >> a;
    for (int i=1; i<=a; i++) {
        // Spaces
        for (int j=1; j<=a-i; j++) {
            cout << " ";
        }
        // Stars
        for (int k=1; k<=i; k++) {
            cout << "*"; 
        }
        cout << endl;
    }

    // Floyd's Triangle
    int num = 1;
    int b;
    cout << "Enter b: ";
    cin >> b;
    for (int i=1; i<=b; i++) {
        for (int j=1; j<=i; j++) {
            cout << num++ << " ";
        }
        cout << endl;
    }

    // Diamond Pattern
    int c;
    cout << "Enter c: ";
    cin >> c;
    // 1st Pyramid
    for(int i=1; i<=c; i++) {
        for(int j=1; j<=n-i; j++) {
            cout << " ";
        }
        for(int j=1; j<=2*i-1; j++) {
            cout << "*";
        }
        cout << endl;
    }
    // 2nd Pyramid
    for(int i=c; i>=1; i--) {
        for(int j=1; j<=n-i; j++) {
            cout << " ";
        }
        for(int j=1; j<=2*i-1; j++) {
            cout << "*";
        }
        cout << endl;
    }

    // Butterfly Pattern
    int d;
    cout << "Enter d: ";
    cin >> d;
    // Pattern 1
    for(int i=1; i<=d; i++) {
        for(int j=1; j<=i; j++) {
            cout << "*";
        }
        for(int j=1; j<=2*(d-i); j++) {
            cout << " ";
        }
        for(int j=1; j<=i; j++) {
            cout << "*";
        }
        cout << endl;    
    }
    // Pattern 2
    for(int i=d; i>=1; i--) {
        for(int j=1; j<=i; j++) {
            cout << "*";
        }
        for(int j=1; j<=2*(d-i); j++) {
            cout << " ";
        }
        for(int j=1; j<=i; j++) {
            cout << "*";
        }
        cout << endl;    
    }

    return 0;
}