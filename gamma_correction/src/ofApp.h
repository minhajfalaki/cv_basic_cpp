
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
		float gamma;
		unsigned char * output1;
		unsigned char r,g,b;
		// double pixelR, pixelG, pixelB;

		ofTexture videoTexture01;
		ofVideoGrabber videoFeed;

 	};