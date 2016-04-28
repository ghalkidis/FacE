/** Copyright 2016 Joseph Maestri and George Halkidis
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 **/

//OpenCV <http://opencv.org/>
//Face analysis SDK <https://github.com/ci2cv/face-analysis-sdk>,
//                  <http://face.ci2cv.net/>
//                  <http://face.ci2cv.net/doc>

#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

int main() {
  cv::VideoCapture Webcam(0);

  if (!Webcam.isOpened()) {
    std::cout << "Error: Failed to open webcam" << std::endl;
  }

  while (1) {
    cv::Mat Frame;

    Webcam.read(Frame);
    cv::imshow("Face Cam", Frame);

    if (cv::waitKey(30) >= 0) break;
  }

return 0;
}
