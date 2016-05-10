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

#include "Detect.hpp"
#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

using namespace std;
using namespace cv;

string faceCascadeName = "haarcascades/haarcascade_frontalface_alt.xml";
string smileCascadeName = "haarcascades/haarcascade_smile.xml";
string eyesCascadeName = "haarcascades/haarcascade_mcs_eyepair_big.xml"; //https://github.com/peterbraden/node-opencv/blob/master/data/haarcascade_mcs_eyepair_big.xml
string noseCascadeName = "haarcascades/haarcascade_mcs_nose.xml"; //https://github.com/peterbraden/node-opencv/blob/master/data/haarcascade_mcs_nose.xml

int main( int argc, const char** argv )
{
    VideoCapture capture;
    Mat frame, image;
    string inputName;
    bool tryflip;

    help();

    CascadeClassifier faceCascade, smileCascade, eyesCascade, noseCascade;
    double scale = 1;

    faceCascade.load(faceCascadeName);
    smileCascade.load(smileCascadeName);
    eyesCascade.load(eyesCascadeName);
    noseCascade.load(noseCascadeName);

    errorChecks(faceCascade, smileCascade, eyesCascade, noseCascade, inputName, capture);

    if( inputName.empty() || (isdigit(inputName[0]) && inputName.size() == 1) )
    {
        int c = inputName.empty() ? 0 : inputName[0] - '0' ;
        if(!capture.open(c))
            cout << "Capture from camera #" <<  c << " didn't work" << endl;
    }
    else if( inputName.size() )
    {
        if(!capture.open( inputName ))
            cout << "Could not read " << inputName << endl;
    }

    if( capture.isOpened() )
    {
        cout << "Video capturing has been started ..." << endl;
        cout << endl << "NOTE: Smile intensity will only be valid after a first smile has been detected" << endl;

        for(;;)
        {
            capture >> frame;
            if( frame.empty() )
                break;

            Mat frame1 = frame.clone();
            detectAndDraw( frame1, faceCascade, smileCascade, eyesCascade, noseCascade, scale, tryflip );

            int c = waitKey(10);
            if( c == 27 || c == 'q' || c == 'Q' )
                break;
        }
    }
    else
    {
        cerr << "ERROR: Could not initiate capture" << endl;
        help();
        return -1;
    }

    return 0;
}

void detectAndDraw( Mat& img, CascadeClassifier& faceCascade,
                    CascadeClassifier& smileCascade,
                    CascadeClassifier& eyesCascade,
                    CascadeClassifier& noseCascade,
                    double scale, bool tryflip)
{
    vector<Rect> faces, faces2;

    const static Scalar colors[] =
    {
        Scalar(255,0,0),
        Scalar(255,128,0),
        Scalar(255,255,0),
        Scalar(0,255,0),
        Scalar(0,128,255),
        Scalar(0,255,255),
        Scalar(0,0,255),
        Scalar(255,0,255)
    };
    Mat gray, smallImg;

    cvtColor( img, gray, COLOR_BGR2GRAY );

    double fx = 1 / scale;
    resize( gray, smallImg, Size(), fx, fx, INTER_LINEAR );
    equalizeHist( smallImg, smallImg );

    faceCascade.detectMultiScale( smallImg, faces,
        1.1, 2, 0
        //|CASCADE_FIND_BIGGEST_OBJECT
        //|CASCADE_DO_ROUGH_SEARCH
        |CASCADE_SCALE_IMAGE,
        Size(30, 30) );
    if( tryflip )
    {
        flip(smallImg, smallImg, 1);
        faceCascade.detectMultiScale( smallImg, faces2,
                                 1.1, 2, 0
                                 //|CASCADE_FIND_BIGGEST_OBJECT
                                 //|CASCADE_DO_ROUGH_SEARCH
                                 |CASCADE_SCALE_IMAGE,
                                 Size(30, 30) );
        for( vector<Rect>::const_iterator r = faces2.begin(); r != faces2.end(); r++ )
        {
            faces.push_back(Rect(smallImg.cols - r->x - r->width, r->y, r->width, r->height));
        }
    }

    for ( size_t i = 0; i < faces.size(); i++ ) //Draw circle around face
    {
        Rect r = faces[i];
        Mat smallImgROI;
        vector<Rect> nestedObjects;
        vector<Rect> nestedObjects2;  //for mouth faceCascade
        vector<Rect> nestedObjects3;  //for mouth faceCascade
        Point center;
        Scalar color = colors[i%8];
        int radius;

        double aspect_ratio = (double)r.width/r.height; //Make circle around mouth
        if( 0.75 < aspect_ratio && aspect_ratio < 1.3 )
        {
            center.x = cvRound((r.x + r.width*0.5)*scale);
            center.y = cvRound((r.y + r.height*0.5)*scale);
            radius = cvRound((r.width + r.height)*0.25*scale);
            circle( img, center, radius, color, 3, 8, 0 );
        }
        else
            rectangle( img, cvPoint(cvRound(r.x*scale), cvRound(r.y*scale)),
                       cvPoint(cvRound((r.x + r.width-1)*scale), cvRound((r.y + r.height-1)*scale)),
                       color, 3, 8, 0);

        const int half_height=cvRound((float)r.height/2);
        r.y=r.y + half_height;
        r.height = half_height-1;
        smallImgROI = smallImg( r );
        smileCascade.detectMultiScale( smallImgROI, nestedObjects,
            1.1, 0, 0
            //|CASCADE_FIND_BIGGEST_OBJECT
            //|CASCADE_DO_ROUGH_SEARCH
            //|CASCADE_DO_CANNY_PRUNING
            |CASCADE_SCALE_IMAGE,
            Size(30, 30) );

        eyesCascade.detectMultiScale( smallImgROI, nestedObjects,
            1.1, 0, 0
            //|CASCADE_FIND_BIGGEST_OBJECT
            //|CASCADE_DO_ROUGH_SEARCH
            //|CASCADE_DO_CANNY_PRUNING
            |CASCADE_SCALE_IMAGE,
            Size(30, 30) );

        noseCascade.detectMultiScale( smallImgROI, nestedObjects,
            1.1, 0, 0
            //|CASCADE_FIND_BIGGEST_OBJECT
            //|CASCADE_DO_ROUGH_SEARCH
            //|CASCADE_DO_CANNY_PRUNING
            |CASCADE_SCALE_IMAGE,
            Size(30, 30) );    

        float intensityZeroOne = calcIntensity(nestedObjects);

        if(intensityZeroOne >= 0.7){
           std::cout << "Smile Detected" << std::endl;
        }else{
          std::cout << "     " << std::endl;
        }

        //std::cout << "Intensity: " << intensityZeroOne << std::endl;
        //std::cout << "# of neighbors: " << smile_neighbors << std::endl;
        //std::cout << "max neighbors: " << max_neighbors << std::endl;
        //std::cout << "min neighbors: " << min_neighbors << std::endl;

        int rect_height = cvRound((float)img.rows * intensityZeroOne);
        Scalar col = Scalar((float)255 * intensityZeroOne, 0, 0); //Smile intensity meter
        //rectangle(img, cvPoint(0, img.rows), cvPoint(img.cols/10, img.rows - rect_height), col, -1);
    }

    imshow( "result", img );
}

static void help()
{
    cout << "\nThis program demonstrates the smile detector.\n"
            "Usage:\n"
            "./smiledetect [--faceCascade=<faceCascade_path> this is the frontal face classifier]\n"
            "   [--smile-faceCascade=[<smile_faceCascade_path>]]\n"
            "   [--scale=<image scale greater or equal to 1, try 2.0 for example. The larger the faster the processing>]\n"
            "   [--try-flip]\n"
            "   [video_filename|camera_index]\n\n"
            "Example:\n"
            "./smiledetect --faceCascade=\"../../data/haarcascades/haarcascade_frontalface_alt.xml\" --smile-faceCascade=\"../../data/haarcascades/haarcascade_smile.xml\" --scale=2.0\n\n"
            "During execution:\n\tHit any key to quit.\n"
            "\tUsing OpenCV version " << CV_VERSION << "\n" << endl;
}

// The number of detected neighbors depends on image size (and also illumination, etc.). The
// following steps use a floating minimum and maximum of neighbors. Intensity thus estimated will be
//accurate only after a first smile has been displayed by the user.
float calcIntensity(vector<Rect> nestedObjects){
    int neighbors = (int)nestedObjects.size();
    static int max_neighbors=-1;
    static int min_neighbors=-1;
    if (min_neighbors == -1) min_neighbors = neighbors;
    max_neighbors = MAX(max_neighbors, neighbors);
    float intensity = ((float)neighbors - min_neighbors) / (max_neighbors - min_neighbors + 1);    

    return intensity;
}

int errorChecks(CascadeClassifier faceCascade,
                 CascadeClassifier smileCascade,
                 CascadeClassifier eyesCascade,
                 CascadeClassifier noseCascade,
                 string inputName,
                 VideoCapture capture)
{
   if( !faceCascade.load( faceCascadeName ) )
    {
        cerr << "ERROR: Could not load face faceCascade" << endl;
        help();
        return -1;
    }
    if( !smileCascade.load( smileCascadeName ) )
    {
        cerr << "ERROR: Could not load smile faceCascade" << endl;
        help();
        return -1;
    }
    if( !eyesCascade.load( eyesCascadeName ) )
    {
        cerr << "ERROR: Could not load mouth faceCascade" << endl;
        help();
        return -1;
    }
    if( !noseCascade.load( noseCascadeName ) )
    {
        cerr << "ERROR: Could not load mouth faceCascade" << endl;
        help();
        return -1;
    }

}
