#ifndef _INC_PROTOCOL_H
#define _INC_PROTOCOL_H

#include <stdint.h>
#include "main.h"

#define PROTOCOL_RADIO_CHANNEL  7
#define PROTOCOL_LTW_START_ADDRESS  {0xC7, 0x68, 0xAC}
#define PROTOCOL_LTW_FINISH_ADDRESS {0xCA, 0x86, 0x7C}

__PACKED_STRUCT ProtocolMessage {
    uint8_t timerState;
};

_Static_assert(sizeof(struct ProtocolMessage) == 1, "incorrect ProtocolMessage size");

#endif // _INC_PROTOCOL_H