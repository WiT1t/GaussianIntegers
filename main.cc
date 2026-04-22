#include <bits/stdc++.h>
#include "./GaussInt.h"

using namespace std;

int main() {
    GaussInt x(2, 7);
    cout << "Norm of 2 + 7i is " << x.N() << endl;
    GaussInt y(9 + 2, 7 + 7);
    GaussInt z(7, 3);
    GaussInt q = y / z;
    GaussInt r = y % z;
    cout << "Result of divison 11 + 14i by 7 + 3i is: " << endl;
    cout << "q = "<< q.re << " + " << q.im << "i" << endl;
    cout << "r = " << r.re << " + " << r.im << "i" << endl;

    GaussInt a(2, 7); GaussInt b(9, 7); GaussInt c(7, 7);
    GaussInt g = gcd(vector<GaussInt>({a, b, c}));
    GaussInt l = lcm(vector<GaussInt>({a, b, c}));
    cout << "GCD of 2+7i, 9+7i, 7+7i is: ";
    cout << g.re << " + " << g.im << "i"<<endl;
    cout << "LCM of those numbers is: " << l.re << " + " << l.im << "i" <<endl;

    return 0;
}
