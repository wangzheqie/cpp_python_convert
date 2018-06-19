from cpython.ref cimport PyObject

# Declares OpenCV's cv::Mat class
cdef extern from "opencv2/core/core.hpp":
    cdef cppclass Mat:
        pass

# Declares the official wrapper conversion functions + NumPy's import_array() function
cdef extern from "cv2.cpp":
    void import_array()
    PyObject* pyopencv_from(const Mat&)
    int pyopencv_to(PyObject*, Mat&)


# Function to be called at initialization
cdef void init():
    import_array()

# Python to C++ conversion
cdef Mat nparrayToMat(object array):
    cdef Mat mat
    cdef PyObject* pyobject = <PyObject*> array
    pyopencv_to(pyobject, mat)
    return <Mat> mat

# C++ to Python conversion
cdef object matToNparray(Mat mat):
    return <object> pyopencv_from(mat)

def np2Mat2np(nparray):
    cdef Mat m 
    m = nparrayToMat(nparray)
    pyarr = matToNparray(m)
    return pyarr 