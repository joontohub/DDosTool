#include "UDPHeader.h"

UDPHeader::UDPHeader()
{
}

UDPHeader::~UDPHeader()
{
}


void UDPHeader::MakeUdpPacket(cv_udphd udphd)
{
    // we need to save dump value to member value

    MakeIpPacket(udphd.iphd);

    memcpy(Sport, udphd.Sport, 2);
    memcpy(Dport, udphd.Dport, 2);
    memcpy(u_length, udphd.u_length, 2);
    memcpy(u_checksum, udphd.u_checksum, 2);
}

vector<uchar> UDPHeader::MakerandomPort(){
  vector<uchar> rst;
  rst.push_back(rand() * 256);
  rst.push_back(rand() * 256);
  return rst;
}

vector<uchar> UDPHeader::UdpToPacket()
{
    vector<uchar> packet = IpToPacket();

    for(int i=0; i < 2; i++) packet.push_back(Sport[i]);
    for(int i=0; i < 2; i++) packet.push_back(Dport[i]);
    for(int i=0; i < 2; i++) packet.push_back(u_length[i]);

    // add check sum

    return packet;
}
