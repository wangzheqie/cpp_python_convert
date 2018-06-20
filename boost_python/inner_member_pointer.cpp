#include <iostream>
#include <boost/python.hpp>
#include <boost/python/wrapper.hpp>
#include <boost/python/object.hpp>
#include <boost/python/instance_holder.hpp>

#include "a.hpp"
#include "b.hpp"
#include "the_a.hpp"

using namespace std;
using namespace boost;
using namespace boost::python;

struct AWrapper: A, wrapper<A>{
    void capImage(){
        this->get_override("capImage")();
    }
    int getWidth(){
        return this->get_override("getWidth")();
    }
};

BOOST_PYTHON_MODULE(inner_member_pointer){
    class_<AWrapper, boost::noncopyable>("PyA")
        .def("capImage", pure_virtual(&A::capImage))
        .def("getWidth", pure_virtual(&A::getWidth))
        ;
    class_<TheA>("PyTheA", init<>())
        .def("capImage", &TheA::capImage)
        .def("getWidth", &TheA::getWidth)
        ;

    class_<B>("PyB")
        .def("getName", &B::getName)
        .def("init", &B::init)
        .def("getA", &B::getA, return_value_policy<manage_new_object>())
        ;
    
}

// struct World
// {
//     void set(std::string msg) { this->msg = msg; }
//     std::string greet() { return msg; }
//     std::string msg;
// };


// BOOST_PYTHON_MODULE(inner_member_pointer)
// {
//     class_<World>("World")
//         .def("greet", &World::greet)
//         .def("set", &World::set)
//     ;
// }