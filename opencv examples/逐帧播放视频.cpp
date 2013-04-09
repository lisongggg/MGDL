// cvtest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "highgui.h"

int main(int argc, char* argv[])
{
	cvNamedWindow("Example1", CV_WINDOW_AUTOSIZE);
	CvCapture *capture = cvCreateFileCapture(argv[1]);
	IplImage *frame;

	while(1)
	{
		frame = cvQueryFrame(capture);
		if(!frame)
		{
			printf("frame is null.\n");
			break;
		}
		cvShowImage("Example1", frame);
		char c = cvWaitKey(33);
		if(c == 27) break;
	}
	
	cvReleaseCapture(&capture);
	cvDestroyWindow("Example1");
	return 0;
}

