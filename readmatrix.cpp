#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

int main(int argc, char** argv)
{
    std::ifstream pattern;

    pattern.open("../hiro.txt");
    if(!pattern){
        std::cout<<"file is broken"<<std::endl;
        return 1;
    }
    std::string pattern_;
    std::vector<int> buffer; 
    while(!pattern.eof()){
        std::string s; 
        std::getline(pattern,s);
        if(!s.empty()){
            std::stringstream ss;
            ss << s;
            int buff;
            for(int i = 0; i < 16; ++i){
                ss >> buff;
                buffer.push_back(buff);
            } 
        }
    }

    int size = buffer.size();
    // std::cout<<"string is "<<std::endl;
    // int count = 0;
    // for(int i = 0; i < size; ++i){
    //     std::cout << buffer[i] <<" ";
    //     count++;
    //     if(count == 16){
    //         std::cout<<std::endl;
    //         count = 0;
    //     }  
    // }   
    std::cout<<'\n'; 
    std::cout<<"the length of pattern is "<<size/16<<std::endl;
    unsigned char matrix[size/16][16];
    for(int i = 0; i < size/16; ++i){
        for(int j = 0; j < 16; ++j){
            matrix[i][j] =  buffer[i*16 + j];
        }
    }
    cv::Mat img( size/16, 16, CV_8UC1, matrix);
    cv::namedWindow("pattern",/* 1920 */160);
    cv::imshow("pattern", img);
    cv::waitKey();
    cv::destroyWindow("pattern");
}
