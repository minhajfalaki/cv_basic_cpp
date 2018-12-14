#include "ofApp.h"

void ofApp::setup(){
	w = 320;
	h = 400;

	videoFeed.setVerbose(true);
	videoFeed.initGrabber(w,h);
	output1 = new unsigned char[w*h*3];
	videoTexture01.allocate(w,h,GL_RGB);
	ofBackground(0,0,0);

}

void ofApp::update(){
	videoFeed.update();

	if(videoFeed.isFrameNew()){
		unsigned char * pixels =videoFeed.getPixels().getData();
		int totalpixels = w*h*3;
		for(int y = 0; y<h; y++){
			for (int x =0; x<w; x++){
				for (int c = 0; c<=3; c++){
					output1[(y*w+x)*3+c] = pixels[(y*w+(w-x))*3+c];
				}
			}
		}
	}

	videoTexture01.loadData(output1,w,h,GL_RGB);
}


void ofApp::draw(){
	ofSetColor(255,255,255);
	videoFeed.draw(0,0);
	videoTexture01.draw(w+5,0,w,h);

}