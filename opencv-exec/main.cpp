//
//  main.cpp
//  opencv-exec
//
//  Created by oms1226 on 18/01/2019.
//  Copyright © 2019 oms1226. All rights reserved.
//

#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, const char * argv[])
{
  namedWindow("img", 1);
  Mat img = imread("anapji.jpg");
  
  if (img.depth() == CV_8U)
    printf("8bit unsigend\n");
  
//  img.
  
  /*
   cout << img.elemSize() << endl;
   cout << img.channels() << endl;
   cout << img.rows << endl;
   cout << img.step << endl;
   */
  
  //using data
  //for (int i = img.rows / 10 * 7; i < img.rows / 10 * 8; i++) {
  
  //for (int i = 0; i < img.rows ; i++) {
  
  for (int i = img.rows / 10 * 7; i < img.rows / 10 * 8; i++) {
    for (int j = 0; j < img.cols; j++) {
      
      
      unsigned char r, g, b;
      
      b = img.data[i * img.step + j * img.elemSize() + 0];
      g = img.data[i * img.step + j * img.elemSize() + 1];
      r = img.data[i * img.step + j * img.elemSize() + 2];
      
      img.data[i * img.step + j * img.elemSize() + 0] = (unsigned char)(255 - b);
      img.data[i * img.step + j * img.elemSize() + 1] = (unsigned char)(255 - g);
      img.data[i * img.step + j * img.elemSize() + 2] = (unsigned char)(255 - r);
      
    }
  }
  
  
  
  
  
  
  //using at
  for (int i = img.rows / 10 * 2; i < img.rows / 10 * 3; ++i)
  {
    for (int j = 0; j < img.cols; ++j)
    {
      //Vec3b means 'uchar 3ch'
      unsigned char b = img.at< cv::Vec3b>(i, j)[0];
      unsigned char g = img.at< cv::Vec3b>(i, j)[1];
      unsigned char r = img.at< cv::Vec3b>(i, j)[2];
      
      //printf("%d %d %d\n", b, g, r);
      
      img.at< cv::Vec3b>(i, j)[0] = (unsigned char)(255 - b); //b
      img.at< cv::Vec3b>(i, j)[1] = (unsigned char)(255 - g); //g
      img.at< cv::Vec3b>(i, j)[2] = (unsigned char)(255 - r); //r
    }
  }
  
  
  
  //using ptr
  for (int i = img.rows / 10 * 5; i < img.rows / 10 * 6; i++) {
    
    cv::Vec3b* ptr = img.ptr< cv::Vec3b >(i);
    
    for (int j = 0; j < img.cols; j++) {
      
      unsigned char b1 = (ptr[j][0]);
      unsigned char g1 = (ptr[j][1]); //note!!
      unsigned char r1 = (ptr[j][2]);
      
      
      cv::Vec3b bgr = ptr[j];
      unsigned char b2 = (bgr[0]);
      unsigned char g2 = (bgr[1]); //note!!
      unsigned char r2 = (bgr[2]);
      
      
      
      ptr[j] = cv::Vec3b(255 - b1, 255 - g1, 255 - r1);
      
    }
  }
  
  
  
  
  
  //using iteration
  cv::MatIterator_< cv::Vec3b> itd = img.begin< cv::Vec3b>(), itd_end = img.end< cv::Vec3b>();
  
  for (int i = 0; itd != itd_end; ++itd, ++i) {
    
    cv::Vec3b bgr = (*itd);
    
    (*itd)[0] = 255 - bgr[0];
    (*itd)[1] = 255 - bgr[1];
    (*itd)[2] = 255 - bgr[2];
  }
  
  
  
  imshow("img", img); //show
  waitKey(0);
  
  destroyAllWindows();
  
  return 0;
}
