#include "Animation.h"

Animation::Animation()
{
    mCurrentFrame = 0;
}

Animation::~Animation()
{
    // dtor
}

void Animation::setup()
{

}

void Animation::update()
{
    
}

void Animation::draw(int x, int y, int w, int h)
{
    if (mFrames.size() < 1) return;
    mFrames.at(mCurrentFrame).draw(x, y, w, h);
}

void Animation::addFrame(ofImage & newFrame)
{
    mFrames.push_back(newFrame);
    nextFrame();
}

void Animation::insertFrame(ofImage & newFrame)
{
    mFrames.insert(mFrames.begin() + mCurrentFrame, newFrame);
}

void Animation::insertFrameAt(int index, ofImage & newFrame)
{
    
}

void Animation::removeFrameAt(int index)
{
    
}

void Animation::nextFrame()
{
    mCurrentFrame++;
    if (mCurrentFrame > mFrames.size()-1) mCurrentFrame = 0; // loop around
}

void Animation::previousFrame()
{
    mCurrentFrame--;
    if (mCurrentFrame < 0) mCurrentFrame = mFrames.size()-1; // loop around
}

void Animation::reset()
{
    
}

void Animation::clear()
{
    
}