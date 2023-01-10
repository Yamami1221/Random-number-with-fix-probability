#include <iostream>
#include <cmath>
#include <random>

using namespace std;
int bruh = 0;

double rannnnnnn(int N) {
    double prop[N]={0};
    prop[N-1] = 1;
    for (int i = N-2; i >= 0; i--) {
        prop[i] = prop[i+1] * 2;
    }
    random_device rd;
    default_random_engine generator(rd());
    discrete_distribution<int> distribution(prop[0],prop[N-1]);
    // prop[0] = ((100*(0.5))/(1-pow(0.5,N)));
    // for (int i = 1; i < N; i++) {
    //     prop[i] = prop[i-1] * 0.5;/* + (100*(1-0.5))+(1-pow(0.5,N))*/
    // }
    if (bruh == 0) {
        for (int i = 0; i < N; i++) {
            cout << "Prop of " << i + 1 << ": " << prop[i] << endl;
        }
        bruh = 1;
    }

    double iii = distribution(generator);
    double ans;
    for (int i = N - 1; i >= 0; i--) {
        if (iii < prop[i]) {
            ans = i + 1;
            break;
        }
    }
    return ans;
}

int main() {
    int N;
    do{
        cout << "Pleses input N: ";
        cin >> N; 
    }while (N <= 1);
    double a[N] = {0};
    for (int i = 0; i < 10000000; i++){
        int j = rannnnnnn(N);
        a[j - 1]++;
    }
    for (int i = 0; i < N; i++) {
        cout << "Count of num " << i + 1 << ": " << a[i] << endl;
    }
    return EXIT_SUCCESS;
}