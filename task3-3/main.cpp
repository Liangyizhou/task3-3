#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
string window_name = "binaryMat";
void threshod_Mat(int th, void*data)
{
	Mat src = *(Mat*)(data);

	Mat dst;
	//二值化
	threshold(src, dst, th, 255, 0);

	imshow(window_name, dst);

}
int main()
{
	Mat srcMat;
	Mat gryMat;
	int lowTh = 30;
	int maxTh = 255;

	srcMat = imread("1.png");
	if (!srcMat.data)//判断图像是否载入
	{
		cout << "载入图像失败" << endl;
		return 0;
	}
	//imshow(window_name,Image);
	cvtColor(srcMat, gryMat, CV_BGR2GRAY);
	imshow(window_name, gryMat);
	createTrackbar("threshold",
		window_name,
		&lowTh,
		maxTh,
		threshod_Mat,
		&gryMat);
	waitKey(0);
	return 0;
}