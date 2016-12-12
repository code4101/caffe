clear, clc
addpath('E:\slns\caffe\Build\x64\Release\matcaffe\+caffe\private')
im = imread('C:\Users\kzche\Pictures\1.jpg');
[scores, maxlabel] = classification_demo(im, 1);
