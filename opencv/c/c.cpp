#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>  
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
using namespace cv;
int Gx[3][3] = { {1,2,1},{0,0,0},{-1,-2,-1} };
int Gy[3][3] = { {-1,0,1},{-2,0,2},{-1,0,1} };
//struct node {
//	int value, pos;
//};
//int path[1010][1010], dp[1010][1010];
Mat GetNewImage(Mat Image)
{
	const int r = Image.rows;
	const int c = Image.cols;
	int **path = new int *[r + 2];
	int **dp = new int *[r + 2];
	for (int i = 0; i < r + 2; i++) {
		path[i] = new int[c + 2];
		dp[i] = new int[c + 2];
	}
	for(int i = 0; i < r; i++){
		for (int j = 0; j < c; j++) {
			int sumx = 0, sumy = 0;
			for (int k = -1; k <= 1; k++) {
				for (int l = -1; l <= 1; l++) {
					int x = i + k, y = j + l;
					if (x < 0 || y < 0 || x >= r || y >= c) continue;
					int a0 = Image.at<Vec3b>(x,y)[0];
					int a1 = Image.at<Vec3b>(x,y)[1];
					int a2 = Image.at<Vec3b>(x,y)[2];
					int a4 = a0 + a1 + a2;
					sumx += Gx[k + 1][l + 1] * a4;
					sumy += Gy[k + 1][l + 1] * a4;
				}
			}
			int value = abs(sumx) + abs(sumy);
			if (i == 0) {
				dp[i][j] = value;
				path[i][j] = 0;
			}
			else {
				if (j == 0) {
					if (dp[i - 1][j] <= dp[i - 1][j + 1]) {
						path[i][j] = j;
						dp[i][j] = dp[i - 1][j] + value;
					}
					else {
						path[i][j] = j + 1;
						dp[i][j] = dp[i - 1][j + 1] + value;
					}
				}
				else if (j == c - 1) {
					if (dp[i - 1][j - 1] <= dp[i - 1][j]) {
						path[i][j] = j - 1;
						dp[i][j] = dp[i - 1][j - 1] + value;
					}
					else {
						path[i][j] = j;
						dp[i][j] = dp[i - 1][j] + value;
					}
				}
				else {
					if (dp[i - 1][j - 1] <= dp[i - 1][j] && dp[i - 1][j - 1] <= dp[i - 1][j + 1]) {
						path[i][j] = j - 1;
						dp[i][j] = dp[i - 1][j - 1] + value;
					}
					if (dp[i - 1][j] <= dp[i - 1][j - 1] && dp[i - 1][j] <= dp[i - 1][j + 1]) {
						path[i][j] = j;
						dp[i][j] = dp[i - 1][j] + value;
					}
					if (dp[i - 1][j + 1] <= dp[i - 1][j - 1] && dp[i - 1][j + 1] <= dp[i - 1][j]) {
						path[i][j] = j + 1;
						dp[i][j] = dp[i - 1][j + 1] + value;
					}
				}
			}
		}
	}
	int ans = 0xfffffff;
	int pos = 0;
	for (int i = 0; i < c; i++) {
		if (ans >= dp[r - 1][i]) {
			ans = dp[r - 1][i];
			pos = i;
		}
	}
	Mat NewImage = Mat::zeros(r, c - 1, Image.type());
	for (int i = r - 1; i >= 0; i--) {
		for (int j = 0; j < c; j++) {
			if (j < pos) {
				NewImage.at<Vec3b>(i, j) = Image.at<Vec3b>(i, j);
			}
			else if(j > pos){
				NewImage.at<Vec3b>(i, j - 1) = Image.at<Vec3b>(i, j);
			}
		}
		pos = path[i][pos];
	}
	return NewImage;
}
//bool ok[1010][1010];
//int a[1010][1010];
//int ss[1010][1010];
//Mat GetNewImage1(Mat Image,int num)
//{
//	const int r = Image.rows;
//	const int c = Image.cols;
//	memset(ok, 0, sizeof(ok));
//	memset(path, 0, sizeof(path));
//	memset(dp, 0, sizeof(dp));
//	memset(a, 0, sizeof(a));
//	memset(ss, 0, sizeof(ss));
//	for (int i = 0; i < r; i++) {
//		for (int j = 0; j < c; j++) {
//			a[i][j] = Image.at<Vec3b>(i, j)[0] + Image.at<Vec3b>(i, j)[1] + Image.at<Vec3b>(i, j)[2];
//		}
//	}
//
//	Mat NewImage;
//	return NewImage;
//}
int main()
{
	Mat Image_czxyyl;
	Image_czxyyl = imread("1.jpg");
	if (!Image_czxyyl.data) {
		cout << "error" << endl;
		return 0;
	}
	int r = Image_czxyyl.rows;
	int c = Image_czxyyl.cols;
	namedWindow("CZXYYL", 1);
	imshow("CZXYYL", Image_czxyyl);
	Mat czxyyl1 = Image_czxyyl;
	for (int i = 0; i < c / 2 ; i++) {
		czxyyl1 = GetNewImage(czxyyl1);
	}
	//czxyyl1 = GetNewImage1(czxyyl1, c / 2);
	namedWindow("czxyyl",1);
	imshow("czxyyl", czxyyl1);
	cvWaitKey(0);
	cvDestroyWindow("czxyyl");
	cvDestroyWindow("CZXYYL");
	return 0;
}
