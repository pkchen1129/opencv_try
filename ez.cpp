#include <iostream>
#include <opencv/cv.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include<fstream>
#include <vector>
using namespace std;
using namespace cv;

int main(){
	vector<int> params;
	// params.push_back(CV_IMWRITE_PNG_COMPRESSION);
	params.push_back(5);
	cout << "try" << endl;
	Mat im = imread("lena.jpg");
	// imshow("lena", im);
	// imwrite("hi.png", im, params);
	waitKey(0);
	return 0;
}
