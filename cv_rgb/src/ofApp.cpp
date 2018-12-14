#include "ofApp.h"

void ofApp::setup(){
	w = 320;
	h = 400;

	videoFeed.setVerbose(true);
	videoFeed.initGrabber(w,h);
	output1 = new unsigned char[w*h*3];
	output2 = new unsigned char[w*h*3];
	output3 = new unsigned char[w*h*3];
	videoTexture01.allocate(w,h,GL_RGB);
	videoTexture02.allocate(w,h,GL_RGB);
	videoTexture03.allocate(w,h,GL_RGB);
	ofBackground(0,0,0);

}

void ofApp::update(){
	videoFeed.update();

	if(videoFeed.isFrameNew()){
		unsigned char * pixels =videoFeed.getPixels().getData();
		for(int y = 0; y<h; y++){
			for (int x =0; x<w; x++){
				output1[(y*w+x)*3+0] = pixels[(y*w+x)*3+0];
				output1[(y*w+x)*3+1] = 0;
				output1[(y*w+x)*3+2] = 0;
			}
		}		
		for(int y = 0; y<h; y++){
			for (int x =0; x<w; x++){
				output2[(y*w+x)*3+0] = 0;
				output2[(y*w+x)*3+1] = pixels[(y*w+x)*3+1];
				output2[(y*w+x)*3+2] = 0;
			}
		}		
		for(int y = 0; y<h; y++){
			for (int x =0; x<w; x++){
				output3[(y*w+x)*3+0] = 0;
				output3[(y*w+x)*3+1] = 0;
				output3[(y*w+x)*3+2] = pixels[(y*w+x)*3+2];
			}
		}
	}

	videoTexture01.loadData(output1,w,h,GL_RGB);
	videoTexture02.loadData(output2,w,h,GL_RGB);
	videoTexture03.loadData(output3,w,h,GL_RGB);
}


void ofApp::draw(){
	ofSetColor(255,255,255);
	videoFeed.draw(0,0);
	videoTexture01.draw(w+5,0,w,h);
	videoTexture02.draw((w*2)+10,0,w,h);
	videoTexture03.draw((w*3)+15,0,w,h);

}