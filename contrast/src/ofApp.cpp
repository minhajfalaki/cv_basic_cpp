#include "ofApp.h"

void ofApp::setup(){
	w = 320;
	h = 400;
	contrast = 0.0f;
	newcontrast = 0.0f;

	pixelR = 0.0f;
	pixelG = 0.0f;
	pixelB = 0.0f;

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
		// int totalpixels = w*h*3;
		for(int x = 0; x<w; x++){
			for(int y = 0; y<h; y++){
				r = pixels[(y*w+x)*3+0];
				g = pixels[(y*w+x)*3+1];
				b = pixels[(y*w+x)*3+2];

				contrast = (100.0+newcontrast)/100.0;
				contrast *= contrast;

				pixelR = (((r/255.0)-0.5)*contrast+0.5)*255.0;
				if(pixelR>255) pixelR = 255;
				if(pixelR<0) pixelR = 0;
				output1[(y*w+x)*3+0] = pixelR;				

				pixelG = (((g/255.0)-0.5)*contrast+0.5)*255.0;
				if(pixelG>255) pixelG = 255;
				if(pixelG<0) pixelG = 0;
				output1[(y*w+x)*3+1] = pixelG;

				pixelB = (((b/255.0)-0.5)*contrast+0.5)*255.0;
				if(pixelB>255) pixelB = 255;
				if(pixelB<0) pixelB = 0;
				output1[(y*w+x)*3+2] = pixelB;
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

void ofApp::keyPressed(int key){
	switch(key){
		case OF_KEY_UP:
		newcontrast+=1;
		if (newcontrast>100) newcontrast=100;
		break;

		case OF_KEY_DOWN:
		newcontrast-=1;
		if (newcontrast<-100) newcontrast=-100;
		break;
	}
}