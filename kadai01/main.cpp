#include <iostream>
#include <string>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>


void display(cv::Mat image, std::string windowName = "Image") {
    cv::namedWindow(windowName);
    cv::imshow(windowName, image);
    cv::waitKey(1000 * 10);
    cv::destroyWindow(windowName);
}

int main(int argc, char* argv[]){
  
  cv::Mat src = cv::imread(argv[1]);

  display(src, "src");

  int x_size = src.cols;
  int y_size = src.rows;

  cv::Mat dst = cv::Mat::zeros(y_size, x_size, CV_8UC3);
  
  int i, j;
  for( j=0 ; j<y_size ; j++){
    for( i=0 ; i<x_size ; i++){
      cv::Vec3b pixel = src.at<cv::Vec3b>(j,i);
      dst.at<cv::Vec3b>(j,i) = pixel;
    }
  }

  display(dst, "dst");

  cv::imwrite("dst_image.jpg", dst);

  return 0;
}

