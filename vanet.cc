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

void TxCallback(Ptr<CounterCalculator<unit32_t>> datac,std::string path, Ptr<const Packet> packet)
{
    NS_LOG_INFO("Frame transmitted");
    NS_LOG_INFO("Send frame counted in "<< datac->GetKey());
    datac->Update();
    NS_LOG_INFO("End of Callback OK");
}

void RxCallback(Ptr<CounterCalculator<unit32_t>> datac,std::string path, Ptr<const Packet> packet)
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
    *os << Simulator::Now() << "POS: x =" << pos.x << ", y=" << pos.y
        << ", z=" << pos.z << "; VEL:" << vel.x << ", y=" << vel.y
        << ", z=" << vel.z << std::endl;
}

int main(int argc , char *argv[])
{
    double distance =50.0;
    double PactetSize= 64;
    double nodespeed=0;
    int numofNodes=2;
    string format("omnet");
    string experiment("wifi-numofNodes-test");
    string strategy("wifi-default");
    string input;
    string runID;
    Config::SetDefault("ns3::WifiRemoteStationManager::FragmentationThreshold",StringValue("2200"));
    Config::SetDefault("ns3::WifiRemoteStationManager::RtsCtsThreshold",StringValue("2200"));
    Config::SetDefault("ns3::RandomWalk2MobilityModel::Mode",StringValue("Time"));
    Config::SetDefault("ns3::RandomWalk2MobilityModel::Time",StringValue("10s"));
    Config::SetDefault("ns3::RandomWalk2MobilityModel::Speed",StringValue("Constant:15.0"));
    Config::SetDefault("ns3::RandomWalk2dMobilityModel::Bounds",StringValue("0|1000|0|1000"));
    {
        stringstream sstr;
        sstr<< "run-" << time (Null);
        runID=sstr.str();
    }
    CommandLine cmd;
    cmd.AddValue("distance","Distance apart to place node (in meters).",distance);
    cmd.AddValue("nodeSpeed","Speed scalar of Nodes",nodeSpeed);
    cmd.AddValue("numofNodes","Number of Nodes to sumulate",numofNodes);
    cmd.AddValue("PacketSize","Packet size to send (in bytes).",PacketSize);
    cmd.AddValue("format","Format to use for data output.",format);
    cmd.AddValue("experiment","Identifier for experiment.",experiment);
    cmd.AddValue("strategy","Identifier for strategy.",strategy);
    cmd.AddValue("run","Identifier for run.",runID);
    cmd.Parse(argc,argv);

    if(format!="omnet"&&format!="db")


}
