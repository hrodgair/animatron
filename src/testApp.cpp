#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    bAddFrame = false;
    mAnimation.setup();
    mCamWidth = ofGetWidth();
    mCamHeight = ofGetHeight();
    videoGrabberSetup();
    mFrame.allocate(mCamWidth, mCamHeight, OF_IMAGE_COLOR);
}

void testApp::videoGrabberSetup()
{
    
    //we can now get back a list of devices. 
    vector<ofVideoDevice> devices = mVideoGrabber.listDevices();
    
    for(int i = 0; i < devices.size(); i++){
        cout << devices[i].id << ": " << devices[i].deviceName; 
        if( devices[i].bAvailable ){
            cout << endl;
        }else{
            cout << " - unavailable " << endl; 
        }
    }

    //    mVideoGrabber.setDeviceID(0);
    mVideoGrabber.setDesiredFrameRate(60);
    mVideoGrabber.initGrabber(mCamWidth,mCamHeight);
}

//--------------------------------------------------------------
void testApp::update(){
        mVideoGrabber.update();
    
	if (mVideoGrabber.isFrameNew()){
        
        if(bAddFrame){
            mFrame.setFromPixels(mVideoGrabber.getPixels(), mCamWidth, mCamHeight, OF_IMAGE_COLOR);
            mAnimation.insertFrame(mFrame);
            bAddFrame = false;
        }
    }

    mAnimation.update();
}

//--------------------------------------------------------------
void testApp::draw(){
  ofBackground(0);
  //    mVideoGrabber.draw(0,0, 320, 240);
    // mFrame.draw(330,0, 320, 240);
      mAnimation.draw(0,0, mCamWidth, mCamHeight);

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    switch(key) {
        case ' ': 
            bAddFrame = true;
            break;
        case OF_KEY_RIGHT:
            mAnimation.nextFrame();
            break;
        case OF_KEY_LEFT:
            mAnimation.previousFrame();
            break;
        case OF_KEY_UP:
            mAnimation.removeFrame();
            break;
        case OF_KEY_DOWN:
            mAnimation.reset();
        default: 
            break;
    }

    ofLog() << "Pressed: " << key;

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
