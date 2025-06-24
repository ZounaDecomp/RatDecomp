#ifndef ABC_MESSAGE_H
#define ABC_MESSAGE_H

#include <BaseObject_Z.h>
#include <ABC_AgentHdl.h>

struct ABC_Message {
public:
    BaseObject_ZHdl sender;
    abc_message messageID;
    ABC_Message* next;
    Float date;
    Float parameter;

    ABC_Message() { Reset(); }

    ~ABC_Message() { }

    void Reset() {
        sender = HANDLE_NULL;
        messageID = msg_no_message;
        next = NULL;
        date = -1;
        parameter = UNDEFINED_FVALUE;
    }
};

#endif //ABC_MESSAGE_H
