#ifndef _SOUND_Z_H_
#define _SOUND_Z_H_
#include "ResourceObject_Z.h"
#include "Types_Z.h"

union SoundFlags_Z {
    struct {
        U8 PAUSED : 1,
            LOOPING : 1,
            Stereo : 1,
            padding : 5;
    } data;
    U8 Flags;
};

class Sound_Z : public ResourceObject_Z {
public:
    Sound_Z();
    void Reset();

    virtual void Init();
    virtual ~Sound_Z();
    virtual void Load(void** i_Data);

private:
    S32 m_Frequency;      /* 0x14 */
    S32 m_SoundSize;      /* 0x18 */
    SoundFlags_Z m_Flags; /* 0x1C */
    U8 m_Unk0x1D;         /* 0x1D */
    S32 m_XRamBlock;      /* 0x20 */
    S32 m_SndDatas_Z;     /* 0x24 */
};

#endif
