#include <iostream>
#include <boost/python.hpp>
#include <boost/python/wrapper.hpp>
#include <boost/python/object.hpp>
#include <boost/python/instance_holder.hpp>
#include <boost/python/return_value_policy.hpp>
#include <boost/python/return_internal_reference.hpp>
#include <boost/python/return_opaque_pointer.hpp>


using namespace std;
using namespace boost;
using namespace boost::python;

struct A{
    A(){};
    A(const A* a_self){
        name = a_self->name;
        value = a_self->value;
    }
    ~A(){};
    std::string name="name A";
    int value=10;

};
struct C {
  C(const char* _a, const A* _the_a) {
       a = new std::string(_a); 
       the_a = new A(_the_a);
    }
  ~C() { delete a; }
  std::string *a;
  A* the_a;
};

std::string const& get_a(C const& c)
{
  return *(c.a);
}
A const& get_the_a(C const& c){
    return *(c.the_a);
}

BOOST_PYTHON_MODULE(design_member_pointer)
{
  using namespace boost::python;
  class_<A>("A", init<>())
    .def_readwrite("name", &A::name)
    .def_readwrite("value", &A::value)
    ;
  class_<C>("C", init<const char*, const A*>())
    .add_property("a", make_function(get_a, return_value_policy<copy_const_reference>()))
    .add_property("the_a", make_function(get_the_a, return_value_policy<copy_const_reference>()))
    ;
}

