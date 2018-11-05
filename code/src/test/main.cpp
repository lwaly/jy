#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "pushdata.hpp"
#include "msg.pb.h"

void CallBack(const char *pBody, int bodyLen, int cmd, unsigned int seq);
int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        printf("%s ip port \"cmd\" \"msg\", now argc %d\n", argv[0], argc);
        return -1;
    }
    if (0 != StartSvr(argv[1], atoi(argv[2]), CallBack))
    {
        printf("func=%s line=%d\n", __FUNCTION__, __LINE__);
        return -1;
    }

    MsgBody oMsgBody;
    oMsgBody.set_data("11");
    MsgBody_Request *req = new MsgBody_Request();
    req->set_route_id(1);
    oMsgBody.set_allocated_req_target(req);
    //oMsgBody.set_session("44444");
    printf("func=%s line=%d %d %d\n", __FUNCTION__, __LINE__, oMsgBody.ByteSize(), req->ByteSize());
    if (0 != SendMsg(oMsgBody.SerializeAsString().c_str(), oMsgBody.ByteSize(), 1005))
    {
        printf("func=%s line=%d\n", __FUNCTION__, __LINE__);
        //return -1;
    }
    printf("func=%s line=%d\n", __FUNCTION__, __LINE__);
    while (true)
    {
        if (0 != SendMsg(oMsgBody.SerializeAsString().c_str(), oMsgBody.ByteSize(), 1005))
        {
            printf("func=%s line=%d\n", __FUNCTION__, __LINE__);
            //return -1;
        }
        sleep(3);
    }

    StopSvr();
    return 0;
}

void CallBack(const char *pBody, int bodyLen, int cmd, unsigned int seq)
{
    static int index = 0;
    index++;
    //     protocol::QuotConfigGetRes rsp;
    //     if (rsp.ParseFromArray(str, lengtn))
    //     {
    //         //tempdata->func(const_cast<char *>(rsp.supported_resolutions().c_str()));
    //         printf("func=%s line=%d supported_resolutions=%s\n", __FUNCTION__, __LINE__, rsp.supported_resolutions().c_str());
    //     }
    if (cmd == 1006)
    {
        printf("func=%s line=%d %d %s\n", __FUNCTION__, __LINE__, bodyLen, pBody);
    }
    printf("func=%s line=%d %d length=%d\n", __FUNCTION__, __LINE__, cmd, bodyLen);
}
