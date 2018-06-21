#include "b.hpp"
#include "a.hpp"
#include "the_a.hpp"
void B::init(){
    A *a = new TheA();
    this->cam1 =(A*) new TheA();
}
int B::getWidth() {
    return 1000;
}
// A* B::getA(){
//     return this->cam1;
//     //or
//     // return this->(*cam1);
// }
A const& B::getA(B const& b) const{
    return *(b.cam1);
}