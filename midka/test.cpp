#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    for(int j = 2; j < sqrt(6); j++){
        if(6 % j == 0) cout << j << " ";
    }
}