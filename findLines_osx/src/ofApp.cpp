#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

void ofApp::setup() {
    ofSetVerticalSync(true);
    ofSetFrameRate(120);

    cam.setup(640, 480);
}

void ofApp::update() {
    cam.update();
    if(cam.isFrameNew()) {
        Mat src, dst, gray;
        src = ofxCv::toCv(cam);
        
        // you might try to play with the setting of the houghlines
        // and the canny edge detection to get (even) better results
        
        // Basic canny edge detection
        // http://docs.opencv.org/2.4/doc/tutorials/imgproc/imgtrans/canny_detector/canny_detector.html
        Canny( src, dst, 50, 200, 3 );
        
        // Convert it to gray
        // http://docs.opencv.org/2.4/modules/imgproc/doc/miscellaneous_transformations.html#cvtcolor
        cvtColor( src, gray, CV_BGR2GRAY );
        
        // Blur it to reduce the noise so we avoid false circle detection
        // http://docs.opencv.org/2.4/modules/imgproc/doc/filtering.html#gaussianblur
        GaussianBlur( gray, gray, cv::Size(3, 3), 2, 2 );
        
        // Find the circles in the image - we are searching for the lense
        // The HoughCircles class has its own edge detector on board
        // This one is kinda tricky ... works under my light conditions but propably won't with yours
        // http://docs.opencv.org/2.4/doc/tutorials/imgproc/imgtrans/hough_circle/hough_circle.html
        HoughCircles( gray, circles, CV_HOUGH_GRADIENT, 1, gray.rows/10, 55, 30, 0, 40 );
        
        // Find the line in the image - if they are parallel we can assume that there is a phone
        // You also might try the HoughLinesP variant for better results
        // http://docs.opencv.org/2.4/doc/tutorials/imgproc/imgtrans/hough_lines/hough_lines.html
        HoughLines( dst, lines, 1, CV_PI/180, 100 );
    }
}

void ofApp::draw() {
    cam.draw(0, 0);
    
    // let's draw the lines
    for( size_t i = 0; i < lines.size(); i++ )
    {
        float rho = lines[i][0];
        float theta = lines[i][1];
        double a = cos(theta), b = sin(theta);
        double x0 = a*rho, y0 = b*rho;
        
        cv::Point pt1(cvRound(x0 + 1000*(-b)),
                      cvRound(y0 + 1000*(a)));
        cv::Point pt2(cvRound(x0 - 1000*(-b)),
                      cvRound(y0 - 1000*(a)));
        
        ofVec2f p1 = ofxCv::toOf(pt1);
        ofVec2f p2 = ofxCv::toOf(pt2);
        
        ofSetColor( 255, 255, 255 );
        ofDrawLine( p1.x, p1.y, p2.x, p2.y );
    }
    
    for( size_t i = 0; i < circles.size(); i++ )
    {
        ofVec2f center(circles[i][0], circles[i][1]);
        int radius = circles[i][2];
        cout << radius << endl;
        ofSetColor( 255, 255, 255 );
        ofDrawEllipse( center.x, center.y, radius , radius );
    }
}
