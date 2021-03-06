#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/nonfree/features2d.hpp>
#include<opencv2/legacy/legacy.hpp>
#include<iostream>
#include<cstdio>
using namespace cv; 
using namespace std; 

const char* imgfile_1 = "1.jpg";
const char* imgfile_2 = "2.jpg";

int main()
{
 Mat img_1 = imread(imgfile_1, 1);
 Mat img_2 = imread(imgfile_2, 1);
 if (!img_1.data || !img_2.data)
 {
  cout<<"Can't open the picture!";
  return -1;
 }
 int minHessian = 200;
 SurfFeatureDetector    detector(minHessian);

 vector<KeyPoint>keypoint_1, keypoint_2;
 detector.detect(img_1,keypoint_1);
 detector.detect(img_2,keypoint_2);

 SurfDescriptorExtractor extractor;

 Mat descriptors_1, descriptors_2;

 extractor.compute(img_1,keypoint_1, descriptors_1);
 extractor.compute(img_2,keypoint_2, descriptors_2);

 FlannBasedMatcher matcher; 
 vector< DMatch > matches; 
 matcher.match( descriptors_1, descriptors_2, matches ); 

 double max_dist = 0; double min_dist = 100; 

 for( int i = 0; i < descriptors_1.rows; i++ ) 
 { double dist = matches[i].distance; 
 if( dist < min_dist ) min_dist = dist; 
 if( dist > max_dist ) max_dist = dist; 
 } 

 printf("-- Max dist : %f \n", max_dist ); 
 printf("-- Min dist : %f \n", min_dist ); 
 vector< DMatch > good_matches; 

 for( int i = 0; i < descriptors_1.rows; i++ ) 
 {
  if( matches[i].distance < 2*min_dist ) 
  {
   good_matches.push_back( matches[i]);
  } 
 }   

 Mat img_matches; 
 drawMatches( img_1, keypoint_1, img_2, keypoint_2,  
  good_matches, img_matches, Scalar::all(-1), Scalar::all(-1),  
  vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS );  

 imshow( "Good Matches", img_matches );


 vector<Point2f> obj; 
 vector<Point2f> scene; 

 for( int i = 0; i < good_matches.size(); i++ ) 
 {   
  obj.push_back( keypoint_1[ good_matches[i].queryIdx ].pt ); 
  scene.push_back( keypoint_2[ good_matches[i].trainIdx ].pt );  
 } 

 Mat H = findHomography( obj, scene, CV_RANSAC ); 


 Point2f obj_corners[4] = { cvPoint(0,0), cvPoint( img_1.cols, 0 ), cvPoint( img_1.cols, img_1.rows ), cvPoint( 0, img_1.rows ) }; 
 Point scene_corners[4]; 


 for( int i = 0; i < 4; i++ ) 
 { 
  double x = obj_corners[i].x;  
  double y = obj_corners[i].y; 

  double Z = 1./( H.at<double>(2,0)*x + H.at<double>(2,1)*y + H.at<double>(2,2) ); 
  double X = ( H.at<double>(0,0)*x + H.at<double>(0,1)*y + H.at<double>(0,2) )*Z; 
  double Y = ( H.at<double>(1,0)*x + H.at<double>(1,1)*y + H.at<double>(1,2) )*Z; 
  scene_corners[i] = cvPoint( cvRound(X) + img_1.cols, cvRound(Y) ); 
 }   

 line( img_matches, scene_corners[0], scene_corners[1], Scalar(0, 255, 0), 2 ); 
 line( img_matches, scene_corners[1], scene_corners[2], Scalar( 0, 255, 0), 2 ); 
 line( img_matches, scene_corners[2], scene_corners[3], Scalar( 0, 255, 0), 2 ); 
 line( img_matches, scene_corners[3], scene_corners[0], Scalar( 0, 255, 0), 2 ); 


 imshow( "Good Matches & Object detection", img_matches );


 cvWaitKey(0);
 
 return 0;
}
