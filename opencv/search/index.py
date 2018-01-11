# USAGE
# python index.py -d images -i index.csv
from colordescriptor import ColorDescriptor
import argparse
import glob
import cv2

ap = argparse.ArgumentParser()
ap.add_argument("-d",help = "the path of stored image")
ap.add_argument("-i",help = "the directory of compute index")
args = vars(ap.parse_args())
cd = ColorDescriptor((8, 12, 3))
output = open(args["i"], "w")
for imagePath in glob.glob(args["d"] + "/*.*"):
	imageID = imagePath[imagePath.rfind("/") + 1:]
	image = cv2.imread(imagePath)
	features = cd.describe(image)
	features = [str(f) for f in features]
	output.write("%s,%s\n" % (imageID, ",".join(features)))
output.close()
