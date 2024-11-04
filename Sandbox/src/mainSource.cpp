#include<iostream>

namespace Hastighet{
    __declspec(dllimport) void print();
}


int main(){
    Hastighet::print();
}