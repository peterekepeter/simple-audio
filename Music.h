#pragma once

namespace Music
{                       
  //initialize music playback
  //supports both streaming and mod files. (OGG & XM is supported for sure)
  void Init(const char* music_filename, bool stream = false);

  //start music playback
  void Play();

  //stop music playback
  void Stop();

  //returns true if is playing
  bool IsPlaying();

  //get position of music in number of byte.
  //if playbackspeed is 44100Hz in stereo 16bit, that sould mean that 44100*2*2 is one second
  //or something like that
  long long GetPositionByte();               
  void SetPositionByte(long long pos);

  //get the position if playing a mod file
  int GetModOrder();

  //get row if playing a mod file
  int GetModRow();

  //set the order in a mod file
  void SetModOrder(int order);

  ///return the latency in ms
  int GetLatency();
}