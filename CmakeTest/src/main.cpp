#include <iostream>
#include <bits/stdc++.h>

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
    return 0;
}