#include "ofApp.h"
#include <math.h>

void ofApp::setup(){
	w = 320;
	h = 400;

	videoFeed.setVerbose(true);
	videoFeed.initGrabber(w,h);
	output1 = new unsigned char[w*h*3];
	videoTexture01.allocate(w,h,GL_LUMINANCE);
	ofBackground(0,0,0);

}

void ofApp::update(){
	videoFeed.update();

	if(videoFeed.isFrameNew()){
		unsigned char * pixels =videoFeed.getPixels().getData();
		// int totalpixels = w*h*3;
		for(int x = 0; x<w; x++){
			for(int y = 0; y<h; y++){
				r = pixels[(y*w+x)*3+0];
				g = pixels[(y*w+x)*3+1];
				b = pixels[(y*w+x)*3+2];

				output1[y*w+x]=(r+g+b)/3;
				int rand1 = rand()%100;
				if(rand1<5) {
					int rand2 = rand()%2;
					if(rand2 == 0) output1[y*w+x]=255;
					else output1[y*w+x] =0;
				}


			}

		}
	}

	videoTexture01.loadData(output1,w,h,GL_LUMINANCE);
}


void ofApp::draw(){
	ofSetColor(255,255,255);
	videoFeed.draw(0,0);
	videoTexture01.draw(w+5,0,w,h);

}

