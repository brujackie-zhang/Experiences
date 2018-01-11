# USAGE
# python search.py -i index.csv -q query/1.png -r images
from colordescriptor import ColorDescriptor
from searcher import Searcher
import argparse
import cv2
ap = argparse.ArgumentParser()
ap.add_argument("-i",help = "the path of stored image")
ap.add_argument("-q",help = "the path of query image")
ap.add_argument("-r",help = "the path of result image")
args = vars(ap.parse_args())
cd = ColorDescriptor((8, 12, 3))
query = cv2.imread(args["q"])
features = cd.describe(query)
searcher = Searcher(args["i"])
results = searcher.search(features)
cv2.imshow("Query", query)
for (k,resultID) in results:
	result = cv2.imread(args["r"] + "/" + resultID)
	cv2.imshow("Result", result)
	cv2.imwrite(".//resultImage//"+resultID,result)
	cv2.waitKey(0)
