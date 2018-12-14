#include "ofApp.h"

void ofApp::setup(){
	w = 320;
	h = 400;
	brightness = 0.0f;

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
		for(int i = 0; i<totalpixels; i++){
			output1[i] = pixels[i]+brightness;

		}
	}

	videoTexture01.loadData(output1,w,h,GL_RGB);
}


void ofApp::draw(){
	ofSetColor(255,255,255);
	videoFeed.draw(0,0);
	videoTexture01.draw(w+5,0,w,h);

}

void ofApp::keyPressed(int key){
	switch(key){
		case OF_KEY_UP:
		brightness+=1;
		if (brightness>100) brightness=100;
		break;

		case OF_KEY_DOWN:
		brightness-=1;
		if (brightness<-100) brightness=-100;
		break;
	}
}