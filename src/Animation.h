#ifndef ANIMATION_H
#define ANIMATION_H

#include "ofMain.h"

class Animation
{
public:
    Animation();
    virtual ~Animation();

    void setup();
    void update();
    void draw(int x=0, int y=0, int w=640, int h=480);

    void addFrame(ofImage & newFrame);
    void insertFrame(ofImage & newFrame);
    void insertFrameAt(int index, ofImage & newFrame);
    void removeFrameAt(int index);
    void nextFrame();
    void previousFrame();
    void reset();
    void clear();

protected:
    
private:
    // a collection of images
    vector<ofImage> mFrames;
    int mCurrentFrame;

};

#endif // ANIMATION_H