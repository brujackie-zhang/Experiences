#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
 
using namespace std;
using namespace cv;
 
int main( )
{
  Mat srcImage;
  srcImage= imread("9.jpg");
  imshow("原始图",srcImage);
  Mat dstImage(srcImage.size(), srcImage.type() );
  Mat map_x(srcImage.size(), CV_32FC1 );
  Mat map_y(srcImage.size(), CV_32FC1 );
  for(int i = 0; i < srcImage.rows;i++)
  {
    for(int j = 0; j < srcImage.cols;j++)
    {
      map_x.at<float>(i,j)= static_cast<float>(srcImage.cols - j);
      map_y.at<float>(i,j)= static_cast<float>(i);
    }
  }
  remap(srcImage, dstImage, map_x, map_y, CV_INTER_LINEAR, BORDER_CONSTANT, Scalar(0) );
  imshow("效果图", dstImage );
  imwrite("result.jpg",dstImage);
  waitKey(0);
  return 0;
}

