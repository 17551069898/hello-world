#include <opencv2/opencv.hpp>
#include "x264_encoding.h"

using namespace cv;
using namespace std;
#define WEIGHT 640
#define HEIGHT 480
int main()
{
	Mat frame;
	VideoCapture cap(0);
	x264Encoder x264;
	unsigned int* buf;
	int bufsize;
	int count = 0;
	cap.set(CAP_PROP_FRAME_WIDTH, WEIGHT);
	cap.set(CAP_PROP_FRAME_HEIGHT, HEIGHT);
	x264.Create(640,480,3,25);

	while (count++ < 100) {
		cap >> frame;
		if (!frame.empty()) {
			bufsize = x264.EncodeOneFrame(frame);
			if (bufsize > 0)
				buf = x264.GetEncodedFrame;
		}
	}
}