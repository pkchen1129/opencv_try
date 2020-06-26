#include <iostream>
#include <cv.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include<fstream>
using namespace std;
using namespace cv;

int main(){
	cout << "try" << endl;
	Mat im = imread("lena.jpg");
	imshow("lena", im);
	imwrite("hi.png", im);
	waitKey(0);
	return 0;
}
