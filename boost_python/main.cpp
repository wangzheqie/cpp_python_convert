/*************************************************************************
	> File Name: main.cpp
	> Author: wangzheqie At: https://github.com/wangzheqie
	> Mail: wangzheqie@qq.com
	> Created Time: Thu 21 Jun 2018 08:06:34 AM CST
 ************************************************************************/

#include <iostream>
#include "a.hpp"
#include "b.hpp"
#include "the_a.hpp"

using namespace std;


int main(int argc, char** argv){
    B b;
    b.init();
    cout<<b.getWidth()<<endl;
    cout<<b.getA()<<endl;

    TheA *the_a = (TheA*)b.getA(); 
    the_a->capImage();
    cout<<the_a->getWidth()<<endl;
    return 0;
}

