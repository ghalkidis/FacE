
/** Copyright 2016 Joseph Maestri
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
//Much of the code in this file was based on/copied directly from smiledetect.cpp 
//included in the samples folder of OpenCV

#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

using namespace std;
using namespace cv;


void detectAndDraw( Mat& img, CascadeClassifier& cascade,
                    CascadeClassifier& nestedCascade,
                    CascadeClassifier& nestedCascade2,
                    CascadeClassifier& nestedCascade3,
                    double scale, bool tryflip );

int errorChecks(CascadeClassifier cascade,
                 CascadeClassifier nestedCascade,
                 CascadeClassifier nestedCascade2,
                 CascadeClassifier nestedCascade3,
                 string inputName,
                 VideoCapture capture);

float calcIntensity(vector<Rect> nestedObjects);

static void help();
