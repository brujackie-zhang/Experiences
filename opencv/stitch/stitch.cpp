#include<iostream>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/stitching/stitcher.hpp>

using namespace std;
using namespace cv;

int main()
{
	vector<Mat> imgs;
	bool flag=false;
	Mat img=imread("1.jpg");
	imgs.push_back(img);
	imshow("1",img);
	img=imread("2.jpg");
	imgs.push_back(img);
	imshow("2",img);
	img=imread("3.jpg");
	imgs.push_back(img);
	imshow("3",img);
	img=imread("4.jpg");
	imgs.push_back(img);
	imshow("4",img);
	
	Stitcher stitcher=Stitcher::createDefault(flag);
	Mat panorama;
	Stitcher::Status status=stitcher.stitch(imgs,panorama);
	if(status!=Stitcher::OK){
		cout<<"拼接出错！"<<endl;
		return false;
	}
	imshow("panorama",panorama);
	imwrite("panorama.jpg",panorama);
	waitKey(0);
	return 0;
}
