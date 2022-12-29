#include <iostream>
#include <bits/stdc++.h>

void weirdAlgorithm(long long n){
    std::cout << n << " ";
    if(n == 1){
        return;
    }
    if(n % 2 == 0){
        weirdAlgorithm(n/2);
    }
    else{
        weirdAlgorithm(3*n + 1);
    }
}

int main(int argc, char** argv){
    if(argc < 2){
        std::cout << "Usage: " << argv[0] << " <name>" << std::endl;
    }
    if(argv[1] != NULL){
        std::cout << "Hello " << argv[1] << std::endl;
    }
    else{
        std::cout << "Hello World" << std::endl;
    }
    std::cout <<"Testin World" << std::endl;
    long long n;
    n = 3;
    weirdAlgorithm(n);
    system("pause");
    return 0;
}