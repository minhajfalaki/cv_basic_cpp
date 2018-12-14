// #pragma once

// #include "ofMain.h"

// #include "ofxOpenCv.h"

// //#define _USE_LIVE_VIDEO		// uncomment this to use a live camera
// 								// otherwise, we'll use a movie file

// class ofApp : public ofBaseApp{

// 	public:
// 		void setup();
// 		void update();
// 		void draw();
		
// 		void keyPressed(int key);
// 		void keyReleased(int key);
// 		void mouseMoved(int x, int y );
// 		void mouseDragged(int x, int y, int button);
// 		void mousePressed(int x, int y, int button);
// 		void mouseReleased(int x, int y, int button);
// 		void mouseEntered(int x, int y);
// 		void mouseExited(int x, int y);
// 		void windowResized(int w, int h);
// 		void dragEvent(ofDragInfo dragInfo);
// 		void gotMessage(ofMessage msg);		

//         #ifdef _USE_LIVE_VIDEO
// 		  ofVideoGrabber 		vidGrabber;
// 		#else
// 		  ofVideoPlayer 		vidPlayer;
// 		#endif

//         ofxCvColorImage			colorImg;

//         ofxCvGrayscaleImage 	grayImage;
// 		ofxCvGrayscaleImage 	grayBg;
// 		ofxCvGrayscaleImage 	grayDiff;

//         ofxCvContourFinder 	contourFinder;

// 		int 				threshold;
// 		bool				bLearnBakground;


// };

# pragma once
# include "ofMain.h"

class ofApp : public ofBaseApp
{
	public:
		void setup();
		void update();
		void draw();
		int w,h;
		unsigned char * output1;
		unsigned char * output2;
		unsigned char * output3;

		ofTexture videoTexture01;
		ofTexture videoTexture02;
		ofTexture videoTexture03;
		ofVideoGrabber videoFeed;

 	};