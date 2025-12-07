#ifndef _INC_RADIO_H
#define _INC_RADIO_H

#include <stdbool.h>
#include "protocol.h"

typedef enum {
    RadioCommStatus_OK,
    RadioCommStatus_ESIZE,
    RadioCommStatus_EPIPE
} RadioCommStatus;

void Radio_Init(void);
bool Radio_PacketReceived(void);
bool Radio_PacketPending(void);
void Radio_GetLinkStatus(bool *linkStart, bool *linkFinish);
RadioCommStatus Radio_ReadMessage(struct ProtocolMessage *message);
void Radio_WriteResponse(const struct ProtocolMessage *response, bool overwrite);

#endif // _INC_RADIO_H