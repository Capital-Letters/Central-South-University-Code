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
    cmd.AddValue("numOfNodes","Number of Nodes to sumulate",numOfNodes);
    cmd.AddValue("PacketSize","Packet size to send (in bytes).",PacketSize);
    cmd.AddValue("format","Format to use for data output.",format);
    cmd.AddValue("experiment","Identifier for experiment.",experiment);
    cmd.AddValue("strategy","Identifier for strategy.",strategy);
    cmd.AddValue("run","Identifier for run.",runID);
    cmd.Parse(argc,argv);

    if(format!="omnet"&&format!="db")
    {
        NS_LOG_ERROR("Unknow outout format'"<< format <<"'");
        return -1;
    }
    if(format == 'db')
    {
        NS_LOG_ERROR("sqlite support not compiled in.");
        return -1;
    }
    {
        stringstream sstr("");
        sstr << double(numOfNodes);
        input = sstr.str();

    }

    NS_LOG_INFO("Installing WiFi and Internet stack.");
    WifiHelper wifi = WifiHelper::Default();
    wifi.SetStandard(WIFI_PHY_STANDARD_80211p_CCH);
    NqosWifiMacHelper wifiMac = NqosWifiMacHelper::Default();
    wifiMac.SetType("ns3::AdhocWifiMac");
    YansWifiPhyHelper wifiPhy =YansWifiPhyHelper::Default();
    wifiPhy.Set("TxPowerEnd",DoubleValue(25));
    wifiPhy.Set("TxPowerStart",DoubleValue(25));
    wifiPhy.Set("EnergyDetectionThreshold",DoubleValue(-94));
    wifiPhy.Set("CcaModelThreshold",DoubleValue(-94));

    Ptr<YansWifiChannel> wifiChannel = CreateObject <YansWifiChannel>();

    Ptr<ThreeLogDistancePropagationLossModel> log3=CreateObject<ThreeLogDistancePropagationLossModel>();
    Ptr<NakagamiPropagationLossModel> nak=CreateObject<NakagamiProgationLossModel>();
    log3->SetNext(nak);

    wifiChannel->SetPropagationLossModel(log3);
    wifiChannel->SetPropagationLossDelayModel(CreateObject<ConstantSpeedPropagationDelayModel>());
    wifiPhy.SetChannel(wifiChannel);
    NetDeviceContainer nodeDevices=wifi.Install(wifiphy,wifiMac,nodes);

    InternetStackHelper internet;
    internet.Install(nodes);
    Ipv4AddressHelper ipAddrs;
    ipAddrs.SetBase("192.168.0.0","255.255.255.0");
    ipAddrs.Assign(nodeDevices);

    MobilityHelper mobility;
    mobility.SetPositionAllocator("ns3::RandomDiscPositionAllocator","X",StringValue("500.0"),"Y",StringValue("500.0"),"Rho",StringVaule("Uniform:0:200"));
    mobility.InstallAll();

    LogComponentEnable("Ns2MobilityHelper",LOG_LEVEL_DEBUG);

    std::ofstream os;
    os.open("movementLog.txt");

    Config::Connect("/NodeList/1/$ns3::MobilityModel/CourseChange",MakeBoundCallback(&CourseChange,&os));

    Ns2MobilityHelper ns2=Ns2MobilityHelper("mobility.txt");
    ns2.Install();

    Ptr<Nodes> tempNode[numOfNodes];
    Ptr<Sender> sender[numOfNodes];
    Ptr<Receiver> receiver[numOfNodes];

    UniformVariable uVar(0,0.001);

    for(int ni=0;ni <numOfNodes;ni++)
    {
        tempNode[ni]=NodeList::GetNode(ni);
        sender[ni]=CreateObject<Sender>();
        sender[ni]->SetStartTime(Seconds(uVar.GetValue()));
        tempNode[ni]->AddApplication(receiver[ni]);
    }
    NS_LOG_INFO("Finished installing Apps on each node");
    Config::Set("/NodeList/*?ApplicationList/0/$Sender/PacketSize",UintegerValue(PacketSize));
    Config::Set("/NodeList/*ApplicationList/0/$Sender/Destination",Ipv4AddressValue("255.255.255.255"));

    DataCollector data;
    data.DescribeRun(
        experiment,
        strategy,input,
        runID);
    data.AddMetadata("author","ensc427");
    Ptr<CounterCalculator<uint32_t>>();
    totalTx->SetKey("wifi-tx-Frames");
    totalTx->SetContext("node[0]");
    Config::Connect("/NodeList/0/DeviceList/*/$ns3::WifiNetDevice/Mac/MacTx",MakeBoundCallback(&TxCallback,totalTx));
    data.AddDataCalculator(totalTx);

    Ptr<PacketCounterCalculator> totalRx=CreateObject<PacketCounterCalculator>();
    totalRx->SetKey("wifi-rx-Frames");
    totalRx->SetContext("node[1]");
    Config::Connect("/NodeList/1/DeviceList/*/$ns3::WifiNetDevice/Mac/MacRx",MakeCallback(&PacketCounterCalculator::PacketUpdate,totalRx));
    data.AddDataCalculator(totalRx);

    Ptr<PacketCounterCalculator> appTx = CreateObject<PacketCounterCalculator>();
    appTx->SetKey("sender-tx-packets");
    appTx->SetContext("node[0]");
    Config::Connect("/NodeList/0/ApplicationList/0/$ender/Tx",MakeCallback(&PacketCounterCalculator::PacketUpdate,appTx));
    data.AddDataCalculator(appTx);

    Ptr<CounterCalculator<>> appRx= CreateObject<CounterCalculator>();
    appRx->SetKey("receiver-rx-packets");
    appRx->SetContext("node[1]");
    receiver[1]->SetCounter(appRx);
    data.AddDataCalculator(appRx);

    Ptr<TimeMinMaxAvgTotalCalculator> beaconStat=CreateObject<TimeMinMaxAvgTotalCalculator>();
    beaconStat->SetKey("interbeacontime");
    beaconStat->SetContext(".");
    receiver[1]->SetBeaconTracker(beaconStat);
    data.AddDataCalculator(beaconStat);
    beaconStat->Enable();

    Config::Set("NodeList/1/ApplicationList/1/$Receiver/SourceToTrack",Ipv4AddressValue("192.168.0.1"));


    NS_LOG_INFO("Run Simulation");
    Simulator::Stop(Seconds(60.0));
    Sumulator::Run();
    
    Ptr<DataOutputInterface> output=0;
    if(format=="omnet")
    {
        NS_LOG_INFO("Create omnet fornatted data output.");
        output=CreateObject<OmnetDataOutput>();
    }
    Simulator::Destory();
    os.close();
}
