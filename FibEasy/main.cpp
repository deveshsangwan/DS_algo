#include <iostream>
#include <math.h>
using namespace std;

unsigned long long int anInt(unsigned long long int n){
    int b = 1;
    while(pow(2, b) <= n){
        b++;
    }
    unsigned long long int a = pow(2, b - 1);
    return a;
}

unsigned long long int fibo(int n){
  unsigned long long int a = round(pow((1 + sqrt(5)) / 2, n) / sqrt(5));
  return a;
}

int findLastDigit(unsigned long long int nth){
    unsigned long long int arr[60];
    for(int i = 0; i <= 59; i++){
        arr[i] = (fibo(i + 1) % 10);
        //cout << arr[i];
    }
    int n = nth % 60;
    return arr[n - 1];
}

int main(){
int a;
cin >> a;
while(a--){
    unsigned long long int n;
    cin >> n;
    if (n == 1){cout << 0 << endl;}
    else if (n < 1){}
    else{
        n = (anInt(n) - 1);
        int ans = findLastDigit(n);
        cout << ans << endl;
    }
}
}
