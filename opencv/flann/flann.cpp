#include<stdio.h>
#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/nonfree/features2d.hpp>
#include<opencv2/legacy/legacy.hpp>
#include<opencv2/highgui/highgui.hpp>
using namespace cv;
using namespace std;
int main( )
{
      
	  Mat img_1 = imread( "./query/9.jpg");
	  imshow("query",img_1);
	  Mat img_2;
	  char fileName[110];
	  for(int i=1;i<111;i++){
	  	sprintf(fileName,"./image/%d.jpg",i);
	    img_2 = imread(fileName);
	    if( !img_1.data || !img_2.data ){
	   	return -1; 
	  }
	  int minHessian = 400;
	  SurfFeatureDetector detector( minHessian );
	  vector<KeyPoint> keypoints_1, keypoints_2;
	  detector.detect( img_1, keypoints_1 );
	  detector.detect( img_2, keypoints_2 );
	  SurfDescriptorExtractor extractor;
	  Mat descriptors_1, descriptors_2;
	  extractor.compute( img_1, keypoints_1, descriptors_1 );
	  extractor.compute( img_2, keypoints_2, descriptors_2 );
	  FlannBasedMatcher matcher;
	  vector<vector<DMatch> > m_knnMatches;
	  const float minRatio=1. / 1000;
	  matcher.knnMatch(descriptors_1,descriptors_2,m_knnMatches,2);
	  const DMatch& bestMatch=m_knnMatches[0][0];
	  const DMatch& betterMatch=m_knnMatches[0][1];
	  float distanceRatio=bestMatch.distance/betterMatch.distance;
	  if (distanceRatio<minRatio)
	  {
	      imshow(fileName,img_2);
	      cout<<distanceRatio<<endl;
	      break;
	  }
	  }
	  waitKey(0);	 
	  return 0;
}


