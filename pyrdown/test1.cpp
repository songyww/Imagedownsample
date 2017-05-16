//*
// * FileName : pyramids.cpp
// * Author   : xiahouzuoxin @163.com
// * Version  : v1.0
// * Date     : Sat 20 Sep 2014 07:04:29 PM CST
// * Brief    : 
// * 
// * Copyright (C) MICL,USTB
// */
#include <iostream>
#include "cv.h" 
#include "highgui.h"
#include "opencv2/imgproc/imgproc.hpp"

using namespace std;
using namespace cv;

const char *wn = "Pyramids Demo";
//double t;

void main(/*int argc, char *argv[]*/)
{
  /*  if (argc < 2) {
        cout<<"Usage: ./pyramids [file name]"<<endl;
        return -1;
    }*/

	//vector<double> time_vect;

    Mat src = imread("E:\\0514\\10000\\1\\x2.jpg");
    if (!src.data) {
        cout<<"Error: read image error."<<endl;
       // return -1;
    }

    /* Size of input image must be 2^n */
    if ( src.cols & (src.cols-1) ) {  // src.cols > 0 first
        cout<<"Error: input image's column must be 2^n"<<endl;
      //  return -1;
    }
    if ( src.rows & (src.rows-1) ) {  // src.cols > 0 first
        cout<<"Error: input image's row must be 2^n"<<endl;
       // return -1;
    }

    cout<<"User Guide:"<<endl;
    cout<<"---------------------"<<endl;
    cout<<"u   -> Zoom out"<<endl;
    cout<<"d   -> Zoom in"<<endl;
    cout<<"ESC -> Exit program"<<endl;

    namedWindow(wn, WINDOW_AUTOSIZE);
    imshow(wn, src);
//	time_vect.clear();

    Mat cur = src;
    Mat dst = cur;
	int i=1;
	char name[100];
	char* bb;
	IplImage temp;
    int end_while = 0;
    while(!end_while) {
        char c;

        c = waitKey(10);
        switch (c) {
        case 27:   /* ESC */
            end_while = 1;
            break;
        case 'u':
            pyrUp(cur, dst, Size(cur.cols*2, cur.rows*2));
            imshow(wn, dst);
            cur = dst;
            break;
        case 'd':

		//	t =(double)cvGetTickCount();//开始计时
            pyrDown(cur, dst, Size(cur.cols/2, cur.rows/2));
		//	t=(double)(cvGetTickCount()-t)/(cvGetTickFrequency()*1000*1000.);

		//	time_vect.push_back(t);
            imshow(wn, dst);
            cur = dst;
			temp = IplImage(dst);
			sprintf(name,"E:\\0514\\10000\\1\\x2%d.jpg" ,i);
			bb=name;

			cvSaveImage(bb,&temp);
			i++;
            break;
        default:
            break;
        }

    }
	//time_vect.clear();
}