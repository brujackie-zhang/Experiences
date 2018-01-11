#coding=utf-8
import cv
# 导入OpenCV模块
 
if __name__ == '__main__':
    # 打开图像
    image = cv.LoadImage ("1.jpg")
    # 创建窗口
    cv.NamedWindow ("mywin")
    # 显示图像
    cv.ShowImage ("mywin", image)
    cv.WaitKey (0)
    
##coding=utf-8
#import cv2
## 导入OpenCV模块
# 
#if __name__ == '__main__':
#    # 打开图像
#    image = cv2.imread ("1.jpg")
#    # 创建窗口
#    cv2.namedWindow ("mywin")
#    # 显示图像
#    cv2.imshow ("mywin", image)
#    cv2.waitKey (0)
