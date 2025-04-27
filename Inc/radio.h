#ifndef _INC_RADIO_H
#define _INC_RADIO_H

#include <stdbool.h>

typedef enum {
    RadioEvent_NOTHING,
    RadioEvent_START,
    RadioEvent_FINISH
} RadioEvent;

struct RadioResponse {
    enum RadioResponseCode {
        RadioResponseCode_START,
        RadioResponseCode_RUN,
        RadioResponseCode_STOP
    } code;
};

void Radio_Init(void);
bool Radio_PacketReceived(void);
bool Radio_PacketPending(void);
void Radio_GetLinkStatus(bool *linkStart, bool *linkFinish);
RadioEvent Radio_ProcessPacket(void);
void Radio_WriteResponse(const struct RadioResponse *response);

#endif // _INC_RADIO_H