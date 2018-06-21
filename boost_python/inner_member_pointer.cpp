#include <iostream>
#include <boost/python.hpp>
#include <boost/python/wrapper.hpp>
#include <boost/python/object.hpp>
#include <boost/python/instance_holder.hpp>
#include <boost/python/return_value_policy.hpp>
#include <boost/python/return_internal_reference.hpp>
#include <boost/python/return_opaque_pointer.hpp>

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
    class_<TheA, boost::shared_ptr<TheA> >("PyTheA")
        .def("capImage", &TheA::capImage)
        .def("getWidth", &TheA::getWidth)
        ;

    class_<B>("PyB")
        .def("getWidth", &B::getWidth)
        .def("init", &B::init)
        // .def("getA", &B::getA, return_value_policy<return_by_value>())
        .def("getA", &B::getA, return_value_policy<copy_const_reference>())
        ;
    


}

