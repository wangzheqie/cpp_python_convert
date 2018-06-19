#!/usr/bin/env python
# -*- coding: utf-8 -*-

import numpy
import sys
import os
import glob
import cv2

# lib_folder = os.path.join(sys.prefix, 'lib/x86_64-linux-gnu')
# # Find opencv libraries in lib_folder
# cvlibs = list()
# for file in glob.glob(os.path.join(lib_folder, 'libopencv_*')):
#     cvlibs.append(file.split('.')[0])
# cvlibs = list(set(cvlibs))
# cvlibs = ['-L{}'.format(lib_folder)] + \
#          ['opencv_{}'.format(lib.split(os.path.sep)[-1].split('libopencv_')[-1]) for lib in cvlibs]

# import opencv_mat
img = cv2.imread("/home/qie/Pictures/aaa.png")
# print("the img is: ", img)
# cv2.imshow("img", img)
# cv2.waitKey(delay=0)

# m = opencv_mat.np2Mat2np(img)
# print("the m is: ", m)
# cv2.imshow("m", m)
# cv2.waitKey(delay=0)

import cvcv2
# help(cvcv2)
m = cvcv2.np2Mat2np(img)
print("the m is: ", m)
# cv2.imshow("m", m)
# cv2.waitKey(delay=0)


