
# pragma once
# include "ofMain.h"

class ofApp : public ofBaseApp
{
	public:
		void setup();
		void update();
		void draw();
		void keyPressed(int key);
		int w,h;
		float brightness;
		unsigned char * output1;

		ofTexture videoTexture01;
		ofVideoGrabber videoFeed;

 	};