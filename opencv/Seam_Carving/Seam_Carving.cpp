#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<iostream>
#include<vector>
#define SEAMNUM 150

using namespace std;
using namespace cv;
//计算能量
void computeEnergy(Mat& srcImage, Mat& dstImage, Mat& trace)
{
	srcImage.copyTo(dstImage);
	for (int i = 1; i < srcImage.rows; i++) {
		//第一列
		if (dstImage.at<float>(i - 1, 0) <= dstImage.at<float>(i-1, 1)) {
			dstImage.at<float>(i, 0) = srcImage.at<float>(i, 0) + dstImage.at<float>(i - 1, 0);
			trace.at<float>(i, 0) = 1;
		}
		else {
			dstImage.at<float>(i, 0) = srcImage.at<float>(i, 0) + dstImage.at<float>(i - 1, 1);
			trace.at<float>(i, 0) = 2;
		}
		//中间列
		for (int j = 1; j < srcImage.cols; j++) {
			float a[3];
			a[0] = dstImage.at<float>(i - 1, j - 1);
			a[1] = dstImage.at<float>(i - 1, j);
			a[2] = dstImage.at<float>(i - 1, j + 1);
			int index = 0;
			if (a[1] < a[0]) {
				index = 1;
			}
			if (a[2] < a[1]) {
				index = 2;
			}
			dstImage.at<float>(i, j) = srcImage.at<float>(i, j) + dstImage.at<float>(i - 1, j - 1 + index);
			trace.at<float>(i, j) = index;
		}
		//最后一列
		if (dstImage.at<float>(i - 1, srcImage.cols - 1) <= dstImage.at<float>(i - 1, srcImage.cols - 2)) {
			dstImage.at<float>(i, srcImage.cols - 1) = srcImage.at<float>(i, srcImage.cols - 1) + dstImage.at<float>(i - 1, srcImage.cols - 1);
			trace.at<float>(i, srcImage.cols - 1) = 1;
		}
		else {
			dstImage.at<float>(i, srcImage.cols - 1) = srcImage.at<float>(i, srcImage.cols - 1) + dstImage.at<float>(i - 1, srcImage.cols - 2);
			trace.at<float>(i, srcImage.cols - 1) = 0;
		}
	}
}
//获取最小能量轨迹
void getMinEnergyTrace(Mat& dstImage, Mat& trace, Mat& minTrace)
{
	int index = 0;
	for (int j = 1; j < dstImage.cols; j++) {
		if (dstImage.at<float>(dstImage.rows - 1, j) < dstImage.at<float>(dstImage.rows - 1, index)) {
			index = j;
		}
	}
	//minTrace.at<float>(dstImage.rows - 1, 0) = index;
	int tempIndex = index;
	for (int i = dstImage.rows - 1; i > 0; i--) {
		int t = trace.at<float>(i, tempIndex);
		if (t == 0) {
			tempIndex -= 1;
		}
		else if (t == 2) {
			tempIndex += 1;
		}
		minTrace.at<float>(i - 1, 0) = tempIndex;
	}
}
//压缩图像
void deleteMinTrace(Mat& srcImage, Mat& dstImage, Mat& minTrace, Mat& deleteTrace)
{
	for (int i = 0; i < dstImage.rows; i++) {
		int t = minTrace.at<float>(i, 0);
		for (int j = 0; j < t; j++) {
			dstImage.at<Vec3b>(i, j)[0] = srcImage.at<Vec3b>(i, j)[0];
			dstImage.at<Vec3b>(i, j)[1] = srcImage.at<Vec3b>(i, j)[1];
			dstImage.at<Vec3b>(i, j)[2] = srcImage.at<Vec3b>(i, j)[2];
		}
		for (int j = t; j < dstImage.cols - 1; j++) {
			dstImage.at<Vec3b>(i, j)[0] = srcImage.at<Vec3b>(i, j + 1)[0];
			dstImage.at<Vec3b>(i, j)[1] = srcImage.at<Vec3b>(i, j + 1)[1];
			dstImage.at<Vec3b>(i, j)[2] = srcImage.at<Vec3b>(i, j + 1)[2];
		}
		deleteTrace.at<Vec3b>(i, 0)[0] = srcImage.at<Vec3b>(i, t)[0];
		deleteTrace.at<Vec3b>(i, 0)[1] = srcImage.at<Vec3b>(i, t)[1];
		deleteTrace.at<Vec3b>(i, 0)[2] = srcImage.at<Vec3b>(i, t)[2];
	}
}

//拉伸图像
void stretch(Mat& srcImage,Mat& dstImage, Mat& minTrace)
{
	for (int i = 0; i < dstImage.rows; i++) {
		int t = minTrace.at<float>(i, 0);
		for (int j = 0; j < t; j++) {
			dstImage.at<Vec3b>(i, j)[0] =srcImage.at<Vec3b>(i, j)[0];
			dstImage.at<Vec3b>(i, j)[1] =srcImage.at<Vec3b>(i, j)[1];
			dstImage.at<Vec3b>(i, j)[2] =srcImage.at<Vec3b>(i, j)[2];

		}
			dstImage.at<Vec3b>(i, t)[0] = srcImage.at<Vec3b>(i, t )[0];
			dstImage.at<Vec3b>(i, t)[1] = srcImage.at<Vec3b>(i, t )[1];
			dstImage.at<Vec3b>(i, t)[2] = srcImage.at<Vec3b>(i, t )[2];
		for (int j = t+1; j < dstImage.cols + 1; j++) {
			dstImage.at<Vec3b>(i, j)[0] = srcImage.at<Vec3b>(i, j-1)[0];
			dstImage.at<Vec3b>(i, j)[1] = srcImage.at<Vec3b>(i, j-1)[1];
			dstImage.at<Vec3b>(i, j)[2] = srcImage.at<Vec3b>(i, j-1)[2];
		}
//		increaseTrace.at<Vec3b>(i, 0)[0] = srcImage.at<Vec3b>(i, t)[0];
//		increaseTrace.at<Vec3b>(i, 0)[1] = srcImage.at<Vec3b>(i, t)[1];
//		increaseTrace.at<Vec3b>(i, 0)[2] = srcImage.at<Vec3b>(i, t)[2];
	}
}
//Seam_Carving压缩过程
void seamCarving(Mat& srcImage, Mat& dstImage, Mat& minTrace1, Mat& deleteTrace1)
{
	Mat image_Gray(srcImage.rows, srcImage.cols, CV_8U, Scalar(0));
	cvtColor(srcImage, image_Gray, CV_BGR2GRAY);
	Mat filter_Vertical(srcImage.rows, srcImage.cols, CV_32F, Scalar(0));
	Mat filter_Horizontal(srcImage.rows, srcImage.cols, CV_32F, Scalar(0));
	Mat kernel_Vertical = (Mat_<float>(3, 3) << 0, 0, 0, 1, -1, 0, 0, 0, 0);
	Mat kernel_Horizontal=(Mat_<float>(3, 3) << 1, 0, 0, 0, 0, -1, 0, 0, 0);
	filter2D(image_Gray, filter_Vertical, filter_Vertical.depth(), kernel_Vertical);
	filter2D(image_Gray, filter_Horizontal, filter_Horizontal.depth(), kernel_Horizontal);
	Mat gradiant_Image(srcImage.rows, srcImage.cols, CV_32F, Scalar(0));
	add(abs(filter_Vertical), abs(filter_Horizontal), gradiant_Image);
//	vector<Mat>V;
//	Mat kernel_Vertical = (Mat_<float>(3, 3) << 0, 0, 0, 1, -1, 0, 0, 0, 0);
//	Mat kernel_Horizontal=(Mat_<float>(3, 3) << 1, 0, 0, 0, 0, -1, 0, 0, 0);
//	split(srcImage, V);
//    Mat gradiant_Image(V[0].size(),CV_32F,Scalar::all(0));
//    for (int i = 0;i < 3;i++) {
//        Mat line_H(V[0].size(),CV_32F);
//        Mat line_V(V[0].size(),CV_32F);
//        filter2D(V[i], line_H, CV_32F, kernel_Vertical);
//        filter2D(V[i], line_V, CV_32F, kernel_Horizontal);
//        for (int j = 0;j < V[i].rows;j++) {
//            for (int k = 0;k < V[i].cols;k++) {
//                gradiant_Image.at<float>(j ,k) += abs(line_H.at<float>(j, k));
//                gradiant_Image.at<float>(j ,k) += abs(line_V.at<float>(j, k));
//            }
//        }
//    }
	//显示梯度图
	/*Mat gradiant;
	gradiant_Image.convertTo(gradiant, CV_8U);
	imshow("梯度图", gradiant);*/
	Mat energy_Image(srcImage.rows, srcImage.cols, CV_32F, Scalar(0));
	Mat trace(srcImage.rows, srcImage.cols, CV_32F, Scalar(0));
	computeEnergy(gradiant_Image, energy_Image, trace);
	Mat minTrace(srcImage.rows, 1, CV_32F, Scalar(0));
	getMinEnergyTrace(energy_Image, trace, minTrace);
	//显示最小能量线
	Mat tracehow(srcImage.rows,srcImage.cols,srcImage.type());
	srcImage.copyTo(tracehow);
	for (int i = 0; i < srcImage.rows; i++) {
		int t = minTrace.at<float>(i, 0);
		tracehow.at<Vec3b>(i, t)[0] = 255;
		tracehow.at<Vec3b>(i, t)[1] = 255;
		tracehow.at<Vec3b>(i, t)[2] = 0;
	}
	imshow("Seam_Carving压缩过程图", tracehow);
	Mat afterDelete(srcImage.rows, srcImage.cols - 1, srcImage.type());
	Mat deleting(srcImage.rows, 1, CV_8UC3);
	deleteMinTrace(srcImage, afterDelete, minTrace, deleting);
	//imshow("效果图", dstImage);
	imwrite("压缩效果图.jpg", dstImage);
	minTrace.copyTo(minTrace1);
	afterDelete.copyTo(dstImage);
	deleting.copyTo(deleteTrace1);
}

//拉伸过程
void seamCarving_Stretch(Mat& srcImage, Mat& dstImage, Mat& minTrace1)
{
	vector<Mat>V;
	Mat kernel_Vertical = (Mat_<float>(3, 3) << 1, 2, 1, 0, 0, 0, -1, -2, -1);
	Mat kernel_Horizontal=(Mat_<float>(3, 3) << 1, 0, -1, 2, 0, -2, 1, 0, -1);
	split(srcImage, V);
    Mat gradiant_Image(V[0].size(),CV_32F,Scalar::all(0));
    for (int i = 0;i < 3;i++) {
        Mat line_H(V[0].size(),CV_32F);
        Mat line_V(V[0].size(),CV_32F);
        filter2D(V[i], line_H, CV_32F, kernel_Vertical);
        filter2D(V[i], line_V, CV_32F, kernel_Horizontal);
        for (int j = 0;j < V[i].rows;j++) {
            for (int k = 0;k < V[i].cols;k++) {
                gradiant_Image.at<float>(j ,k) += abs(line_H.at<float>(j, k));
                gradiant_Image.at<float>(j ,k) += abs(line_V.at<float>(j, k));
            }
        }
    }
 
	Mat energy_Image(srcImage.rows, srcImage.cols, CV_32F, Scalar(0));
	Mat trace(srcImage.rows, srcImage.cols, CV_32F, Scalar(0));
	computeEnergy(gradiant_Image, energy_Image, trace);
	Mat minTrace(srcImage.rows, 1, CV_32F, Scalar(0));
	getMinEnergyTrace(energy_Image, trace, minTrace);
	//显示最小能量线
	Mat tracehow(srcImage.rows,srcImage.cols,srcImage.type());
	srcImage.copyTo(tracehow);
	for (int i = 0; i < srcImage.rows; i++) {
		int t = minTrace.at<float>(i, 0);
		tracehow.at<Vec3b>(i, t+1)[0] = 255;
		tracehow.at<Vec3b>(i, t+1)[1] = 255;
		tracehow.at<Vec3b>(i, t+1)[2] = 0;
	}
   
	Mat afterIncrease(srcImage.rows, srcImage.cols+1, srcImage.type());
	Mat increasing(srcImage.rows, 1, CV_8UC3);
	stretch(srcImage, afterIncrease, minTrace);
//	//imshow("效果图", dstImage);
	imshow("Seam_Carving拉伸过程图", srcImage);
	imwrite("拉伸效果图.jpg", dstImage);
	minTrace.copyTo(minTrace1);
	afterIncrease.copyTo(dstImage);
}
//复原图像
void recovery(Mat& srcImage, Mat& minTrace, Mat& deleteTrace, Mat& outImage)
{
	Mat recovery_Image(srcImage.rows, srcImage.cols + 1, CV_8UC3);
	for (int i = 0; i < srcImage.rows; i++) {
		int t = minTrace.at<float>(i,0);
		for (int j = 0; j < t; j++) {
			recovery_Image.at<Vec3b>(i, j)[0] = srcImage.at<Vec3b>(i, j)[0];
			recovery_Image.at<Vec3b>(i, j)[1] = srcImage.at<Vec3b>(i, j)[1];
			recovery_Image.at<Vec3b>(i, j)[2] = srcImage.at<Vec3b>(i, j)[2];
		}
		recovery_Image.at<Vec3b>(i, t)[0] = deleteTrace.at<Vec3b>(i, 0)[0];
		recovery_Image.at<Vec3b>(i, t)[1] = deleteTrace.at<Vec3b>(i, 0)[1];
		recovery_Image.at<Vec3b>(i, t)[2] = deleteTrace.at<Vec3b>(i, 0)[2];
		for (int j = t+1 ; j < srcImage.cols + 1; j++) {
			recovery_Image.at<Vec3b>(i, j)[0] = srcImage.at<Vec3b>(i, j-1)[0];
			recovery_Image.at<Vec3b>(i, j)[1] = srcImage.at<Vec3b>(i, j-1)[1];
			recovery_Image.at<Vec3b>(i, j)[2] = srcImage.at<Vec3b>(i, j-1)[2];
		}
	}

	Mat recoveryTrace(recovery_Image.rows, recovery_Image.cols, recovery_Image.type());
	recovery_Image.copyTo(recoveryTrace);
	for (int i = 0; i < recoveryTrace.rows; i++) {
	int t = minTrace.at<float>(i, 0);
		recoveryTrace.at<Vec3b>(i, t)[0] = 0;
		recoveryTrace.at<Vec3b>(i, t)[1] = 0;
		recoveryTrace.at<Vec3b>(i, t)[2] = 0;
	}
	imshow("复原图像", recoveryTrace);
	recovery_Image.copyTo(outImage);
}

int main()
{
	Mat image = imread("1.jpg");
	imshow("Original Image", image);
	Mat image1, minTrace[SEAMNUM], deleteTrace[SEAMNUM], outImage;
	Mat increaseTrace,image2,minTrace1,outImage1;
	image.copyTo(image1);
	image.copyTo(image2);
	for (int i = 0; i < SEAMNUM; i++)
	{
		seamCarving(image1, outImage, minTrace[i], deleteTrace[i]);
		image1 = outImage;
		waitKey(10);
	}
	for (int i = 0; i < SEAMNUM; i++)
	{
		recovery(image1, minTrace[SEAMNUM-i-1], deleteTrace[SEAMNUM-i-1], outImage);
		image1 = outImage;
		waitKey(10);
	}
	for(int i=0;i<SEAMNUM;i++){
		seamCarving_Stretch(image2, outImage1, minTrace1);
		image2=outImage1;
		waitKey(10);
	}
	waitKey(0);
	return 0;
}
