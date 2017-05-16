//#include "stdafx.h"
#include <iostream>
#include <cv.h>
#include <cxcore.h>
#include <highgui.h>
#include <cmath>
using namespace std;
using namespace cv;

int main()
{
	vector<double> time_vect;
	//
	double t;
	double t1;
	time_vect.clear();
	IplImage *scr=0;
	IplImage *dst=0;
	double scale=1.0/2.0;
	CvSize dst_cvsize;

	if (scr=cvLoadImage("E:\\0514\\10000\\1\\5.jpg",-1))
	{
		
		dst_cvsize.width=(int)(scr->width*scale);
		dst_cvsize.height=(int)(scr->height*scale);
		dst=cvCreateImage(dst_cvsize,scr->depth,scr->nChannels);

		t =(double)cvGetTickCount();//��ʼ��ʱ
				cvResize(scr,dst,CV_INTER_AREA);//
		//             CV_INTER_NN - ����ڲ�ֵ,
		//             CV_INTER_LINEAR - ˫���Բ�ֵ (ȱʡʹ��)
		//             CV_INTER_AREA - ʹ�����ع�ϵ�ز�������ͼ����Сʱ�򣬸÷������Ա��Ⲩ�Ƴ��֡�
		/*��ͼ��Ŵ�ʱ�������� CV_INTER_NN ����..*/
		//             CV_INTER_CUBIC - ������ֵ.

		
		t=(double)(cvGetTickCount()-t)/(cvGetTickFrequency()*1000*1000.);
		time_vect.push_back(t);
		
		cvSaveImage("E:\\0514\\10000\\1\\dd2.jpg",dst);
		
	/*	cvNamedWindow("scr",CV_WINDOW_AUTOSIZE);
		cvNamedWindow("dst",CV_WINDOW_AUTOSIZE);
		cvShowImage("scr",scr);
		cvShowImage("dst",dst);
		cvWaitKey();
		cvReleaseImage(&scr);
		cvReleaseImage(&dst);
		cvDestroyWindow("scr");
		cvDestroyWindow("dst");*/
	}
//	cvWaitKey();
	return 0;
	time_vect.clear();
}
