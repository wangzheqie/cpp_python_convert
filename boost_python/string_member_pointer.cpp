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

struct C {
  C(const char* _a) { a = new std::string(_a); }
  ~C() { delete a; }
  std::string *a;
};

std::string const& get_a(C const& c)
{
  return *(c.a);
}

BOOST_PYTHON_MODULE(string_member_pointer)
{
  using namespace boost::python;
  class_<C>("C", init<const char*>())
    .add_property("a", make_function(get_a, return_value_policy<copy_const_reference>()))
    ;
}

