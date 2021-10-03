# Computer Vision Algorithms
![Status: in progress](https://img.shields.io/badge/Status-in%20progress-blue)

The project was created to learn computer vision from basic to advance level. The implemented algorithms are 
exercises in [Computer Vision Algorithms and Applications created by Richar Szeliski](https://szeliski.org/Book/).
Also project was made with good practices, project structure, cmake and unit tests.

## Dependencies
- [Eigen3](https://eigen.tuxfamily.org/index.php?title=Main_Page) 
- [OpenCV with contrib version](https://opencv.org/)

The dependecies should be installed globally
using `make install`

Project was created with:
- Ubuntu 20.04
- Cmake 3.16.3
- C++ standard 17

it can propably also work on other systems and versions of cmake and c++, but wasn't tested yet.

Install some additional dependencies
```bash
sudo apt install git cmake
```

To build OpenCV with GPU support use this command and use this [tutorial]() 
```bash
cmake -D CMAKE_BUILD_TYPE=RELEASE \
  -D CMAKE_INSTALL_PREFIX=/usr/local \  
  -D WITH_CUDA=ON \  
  -D ENABLE_FAST_MATH=1 \  
  -D CUDA_FAST_MATH=1 \  
  -D WITH_CUBLAS=1 \  
  -D OPENCV_EXTRA_MODULES_PATH=~/Downloads/opencv_contrib/modules/ ..
```

## Setup && Run
```bash
git clone https://github.com/RocketFan/cv_algorithms.git
cd cv_algorithms
mkdir build && cd build
cmake ..
cmake --build
```

Go to build/bin folder and find exercise which you want to run.
For example
```bash
cd build/bin
./image_formation/ex_1
```
