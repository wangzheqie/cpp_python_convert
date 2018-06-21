    #ifndef _B_HPP_
    #define _B_HPP_
    #include <iostream>
    #include "a.hpp"
    class B{
        public:
        A *cam1;
        A *cam2;

        public:
        void init();
        int getWidth() ;
        A*  getA();
    };
    #endif