#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    long long tu, mau;
    while (t--) {
        
        cin >> tu >> mau;
        long long res;

        while (true) {
            if (mau % tu == 0) {
                cout << "1/" << mau/tu << endl;
                break;
            } else {
                res = mau / tu + 1;
                cout << "1/" << res << " + ";
                tu = tu * res - mau;
                mau = mau*res;
            }
        }


    }
}