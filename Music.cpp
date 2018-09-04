
#undef UNICODE
#include "bass24/bass.h"

namespace Music
{                         
  static HMUSIC hmusic = 0; //bass music handle
  static HSTREAM hstream = 0;
  static bool isStream = false;        
  static BASS_INFO info;

  void Init(const char* musicfile, bool stream)
  {
    BASS_Init(-1,44100,BASS_DEVICE_LATENCY,0,0); //default init, use default stuff     

    BASS_GetInfo(&info);

    isStream = stream;
  
    if (isStream)
      hstream = BASS_StreamCreateFile(0,musicfile,0,0,0);
    else
      hmusic = BASS_MusicLoad(false, musicfile, 0, 0, 0, 0);
  
    if(hmusic == 0 && hstream == 0) throw "Failed to load music";
  }

  void Play()
  {
    if (isStream)
      BASS_ChannelPlay(hstream,true);
    else
      BASS_ChannelPlay(hmusic,true);
  }

  int GetLatency()
  {
    return info.latency;
  }

  long long GetPositionByte()
  {
    return BASS_ChannelGetPosition(hstream,BASS_POS_BYTE);
  }

  void SetPositionByte(long long pos)
  {
    BASS_ChannelSetPosition(hstream,pos,BASS_POS_BYTE);    
    BASS_ChannelPlay(hstream,false);
  }
            
  int GetModRow()
  {                                             
    return HIWORD(BASS_ChannelGetPosition(hmusic,BASS_POS_MUSIC_ORDER));
  }

  int GetModOrder()
  {                           
    return LOWORD(BASS_ChannelGetPosition(hmusic,BASS_POS_MUSIC_ORDER));
  }

  void SetModOrder(int order)
  {
    BASS_ChannelSetPosition(hmusic,MAKELONG(order,0),BASS_POS_MUSIC_ORDER);
  }

}
