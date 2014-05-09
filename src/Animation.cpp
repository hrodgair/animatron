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

void Animation::removeFrame(int index)
{
  if (mFrames.size() <= 0) return;

  if (index < 0) 
    index = mCurrentFrame;

  mFrames.erase(mFrames.begin() + index);

  // probably unnecessary, but make sure to be on an existing frame
  previousFrame();
  nextFrame();
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
    clear();
}

void Animation::clear()
{
    mCurrentFrame = 0;
    mFrames.clear();
}
