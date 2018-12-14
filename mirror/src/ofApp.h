
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

		ofTexture videoTexture01;
		ofVideoGrabber videoFeed;

 	};