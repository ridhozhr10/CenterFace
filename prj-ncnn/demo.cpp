#include <iostream>
#include <opencv2/opencv.hpp>
#include "ncnn_centerface.h"

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		std::cout << " .exe model_path image_file" << std::endl;
		return -1;
	}

	std::string model_path = argv[1];
	std::string image_file = argv[2];

	Centerface centerface;

	centerface.init(model_path);

	cv::Mat image = cv::imread(image_file);

	std::vector<FaceInfo> face_info;
	ncnn::Mat inmat = ncnn::Mat::from_pixels(image.data, ncnn::Mat::PIXEL_BGR2RGB, image.cols, image.rows);
	centerface.detect(inmat, face_info, image.cols, image.rows);

	for (int i = 0; i < face_info.size(); i++)
	{
		cv::rectangle(image, cv::Point(face_info[i].x1, face_info[i].y1), cv::Point(face_info[i].x2, face_info[i].y2), cv::Scalar(0, 255, 0), 2);
		std::cout << "x1:" << face_info[i].x1 << " "
							<< "x2:" << face_info[i].x1 << " "
							<< "y1:" << face_info[i].y1 << " "
							<< "y2:" << face_info[i].y1 << " "
							<< "score:" << face_info[i].score << std::endl;
	}

	cv::imwrite("hasil.jpeg", image);
	return 0;
}