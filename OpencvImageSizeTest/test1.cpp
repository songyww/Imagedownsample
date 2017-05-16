#include <highgui.h>

using namespace cv;

void main()
{
	IplImage* img1;
	IplImage* img2;
	img1 = cvLoadImage("E:\\0514\\4000\\1\\1.jpg");
	img2 = cvLoadImage("E:\\0514\\4000\\2\12.jpg");
	
	cvNamedWindow("Example1",CV_WINDOW_AUTOSIZE);
	cvShowImage("Example1",img1);

	cvNamedWindow("Example2",CV_WINDOW_AUTOSIZE);
	cvShowImage("Example2",img2);

	IplImage * img3 = cvCreateImage(cvSize(img1->width+img2->width,img1->height+img2->height),
		IPL_DEPTH_8U,3);

	cvSetImageROI(img3,cvRect(0,0,img1->width,img1->height));
	cvCopy(img1,img3);
	cvSetImageROI(img3,cvRect(img1->width,0,img2->width,img2->height));
	cvCopy(img2,img3);
	cvResetImageROI(img3);
	
	cvNamedWindow("Example3",CV_WINDOW_AUTOSIZE);
	cvShowImage("Example3",img3);


	//IplImage* correspond = cvCreateImage( cvSize(img1->width+img2->width, img1->height+img2->height), 8, 1 );




	//	//¸´ÖÆÐÂÍ¼Ïñ

	//	cvSetImageROI(correspond, cvRect( 0, 0, img1->width, img1->height));
	//	cvCopy(img1, correspond);
	//	cvResetImageROI(correspond);
	////	cvShowImage( "Object Correspond", correspond );
	//	cvSetImageROI( correspond, cvRect( img1->width,0, img2->width, img2->height ) );
	//	cvCopy(img2, correspond);
	////	cvResetImageROI( correspond );
	////	cvShowImage( "Object Correspond", correspond );
	//	cvResetImageROI(correspond);
	//	cvShowImage( "Object Correspond", correspond );



	cvWaitKey(0);
	cvReleaseImage(&img1);
	cvDestroyWindow("Example1");

	cvReleaseImage(&img2);
	cvDestroyWindow("Example2");
	cvReleaseImage(&img3);
	cvDestroyWindow("Example3");

}