import cv2
#Configurable Parameters
source = "beauty.png"
destination = "New_Image.jpeg"
scale_parcentage = 10

#main code
src = cv2.imread(source,cv2.IMREAD_UNCHANGED)
#cv2.imshow("title",src)

new_width=int(src.shape[1]*scale_parcentage/100)
new_height=int(src.shape[0]*scale_parcentage/100)

output = cv2.resize(src,(new_width,new_height))

cv2.imwrite(destination,output)