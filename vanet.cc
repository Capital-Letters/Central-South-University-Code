#include <ctime> 
#include <iostream> 
#include <fstream> 
#include <sstream>

#include "ns3-utils.h/core-module.h"
#include "ns3-utils.h/network-module.h"
#include "ns3/mobility-module.h"

#include "ns3/ns2-mobility-helper.h"
#include "ns3/wifi-module.h"
#include "ns3/propagation-module.h"
#include "ns3/internet-module.h"

#include "ns3/stats-module.h"
#include "wifi-exampple-apps.h"

using namespace ns3;
using namespace std;

NS_LOG_COMPONENT_DEFINE("WiFi80211pExperiment");
Time CurTime

void Txcallback(Ptr<CounterCalculator<unit32_t>> datac,std::string path, Ptr<const Packet> packet)
{
    NS_LOG_INFO("Frame transmitted");
    NS_LOG_INFO("Send frame counted in "<< datac->GetKey());
    datac->Update();
    NS_LOG_INFO("End of Callback OK");
}

void Txcallback(Ptr<CounterCalculator<unit32_t>> datac,std::string path, Ptr<const Packet> packet)
{
    NS_LOG_INFO("Frame received");
    NS_LOG_INFO("Send frame counted in "<< datac->GetKey());
    datac->Update();
}

static void 
CourseChange(std::ostream *os,std::string foo,Ptr<const MobilityModel> mobility)
{
    Vector pos=mobility->GetPosition();
    Vector vel=mobility->GetVelocity();
    *os << Simulator::Now() << "POS: x =" << pos.x
}

