import cv2
import math
import numpy as np
print 'Load Image'
img1 = cv2.imread('1.jpg') #query image
img2 = cv2.imread('3.jpg') #train image
rows, cols, channels = img1.shape
imgGray1 = cv2.cvtColor(img1, cv2.COLOR_RGB2GRAY)
imgGray2 = cv2.cvtColor(img2, cv2.COLOR_RGB2GRAY)
print 'SURF Feature Detection'
# initialize ORB object with default values
surf = cv2.SURF(800)
# find keypoints
keypoint1, descriptor1 = surf.detectAndCompute(imgGray1, None)
keypoint2, descriptor2 = surf.detectAndCompute(imgGray2, None)
def keypointToPoint(keypoint):
    point = np.zeros(len(keypoint) * 2, np.float32)   
    for i in range(len(keypoint)):
        point[i * 2] = keypoint[i].pt[0]
        point[i * 2 + 1] = keypoint[i].pt[1]
         
    point = point.reshape(-1,2)
    return point
point1 = keypointToPoint(keypoint1)       
rightFeatures = keypointToPoint(keypoint2)
bf = cv2.BFMatcher(cv2.NORM_L2, crossCheck=True)
matches = bf.match(descriptor1, descriptor2)
print 'matches:', len(matches)
dist = []
for m in matches:
    dist.append(m.distance)
# distance threshold
thresDist = np.median(dist)
good = []
for m in matches:
    if m.distance < thresDist:
        good.append(m)
print 'Good Matches:', len(good)
# select keypoints from good matches
points1 = []
points2 = []
for m in good:
    points1.append(keypoint1[m.queryIdx].pt)
    points2.append(keypoint2[m.trainIdx].pt)
points1 = np.float32(points1)
points2 = np.float32(points2)
K = np.array([[517.67386649, 0.0, 268.65952163], [0.0, 519.75461699, 215.58959128], [0.0, 0.0, 1.0]])   

print 'Goodbye!'


