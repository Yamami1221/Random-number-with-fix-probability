#include <iostream>
#include <cmath>
#include <random>
#include <numeric>

using namespace std;
bool showprop = 1;

long double rannnnnnn(long long int N) {
    long double prop[N]={0};
    long double propforshow[N]={0};
    prop[N-1] = 1;
    propforshow[N-1] = 1;
    for (long long int i = N-2; i >= 0; i--) {
        propforshow[i] = propforshow[i + 1] * 2;
    }
    for (long long int i = N-2; i >= 0; i--) {
        prop[i] = prop[i+1] + propforshow[i];
    }
    random_device rd;
    default_random_engine generator(rd());
    discrete_distribution<long long int> distribution(prop[0],prop[N-1]);
    // prop[0] = ((100*(0.5))/(1-pow(0.5,N)));
    // for (long long int i = 1; i < N; i++) {
    //     prop[i] = prop[i-1] * 0.5;/* + (100*(1-0.5))+(1-pow(0.5,N))*/
    // }
    long long int sum = 0;
    long long int size = sizeof(propforshow)/sizeof(propforshow[0]);
    sum = accumulate(propforshow, propforshow + size, sum);
    if (showprop) {
        for (long long int i = 0; i < N; i++) {
            cout << "Prop of " << i + 1 << ": " << propforshow[i] << " of " << sum << endl;
        }
        showprop = 0;
    }

    long double iii = distribution(generator);
    long double ans;
    for (long long int i = N - 1; i >= 0; i--) {
        if (iii < prop[i]) {
            ans = i + 1;
            break;
        }
    }
    return ans;
}

int main() {
    long long int N;
    do{
        cout << "Pleses input N: ";
        cin >> N; 
    }while (N <= 1);
    long double a[N] = {0};
    for (long long int i = 0; i < 10000000; i++){
        long long int j = rannnnnnn(N);
        a[j - 1]++;
    }
    for (long long int i = 0; i < N; i++) {
        cout << "Count of num " << i + 1 << ": " << a[i] << endl;
    }
    return EXIT_SUCCESS;
}