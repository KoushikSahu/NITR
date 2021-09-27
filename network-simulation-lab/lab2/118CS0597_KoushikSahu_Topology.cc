#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/internet-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/applications-module.h"
#include "ns3/netanim-module.h"
 
using namespace ns3;

NS_LOG_COMPONENT_DEFINE ("FirstScriptExample");

int
main (int argc, char *argv[])
{
  CommandLine cmd (__FILE__);
  cmd.Parse (argc, argv);
  
  Time::SetResolution (Time::NS);
  LogComponentEnable ("UdpEchoClientApplication", LOG_LEVEL_INFO);
  LogComponentEnable ("UdpEchoServerApplication", LOG_LEVEL_INFO);

  NodeContainer nodes;
  nodes.Create (5);

  PointToPointHelper pointToPoint;
  pointToPoint.SetDeviceAttribute ("DataRate", StringValue ("5Mbps"));
  pointToPoint.SetChannelAttribute ("Delay", StringValue ("2ms"));

  NetDeviceContainer device[5];
  for(int i=1; i<5; i++){
    device[i] = pointToPoint.Install(nodes.Get(i), nodes.Get(0));
  }

  InternetStackHelper stack;
  stack.Install(nodes);

  Ipv4AddressHelper address[5];
  address[0].SetBase("10.1.1.0", "255.255.255.0");
  address[1].SetBase("10.1.2.0", "255.255.255.0");
  address[2].SetBase("10.1.3.0", "255.255.255.0");
  address[3].SetBase("10.1.4.0", "255.255.255.0");
  address[4].SetBase("10.1.5.0", "255.255.255.0");

  Ipv4InterfaceContainer interface[5];
  for(int i=0; i<5; i++){
    interface[i] = address[i].Assign(device[i]);
  }

  UdpEchoServerHelper echoServer0(90);

  ApplicationContainer serverApps = echoServer0.Install (nodes.Get (1));
  serverApps.Start (Seconds (1.0));
  serverApps.Stop (Seconds (20.0));

  UdpEchoClientHelper echoClient1 (interface[1].GetAddress (1), 90);
  echoClient1.SetAttribute ("MaxPackets", UintegerValue (1));
  echoClient1.SetAttribute ("Interval", TimeValue (Seconds (1.0)));
  echoClient1.SetAttribute ("PacketSize", UintegerValue (1024));

  UdpEchoClientHelper echoClient2 (interface[2].GetAddress (1), 90);
  echoClient2.SetAttribute ("MaxPackets", UintegerValue (1));
  echoClient2.SetAttribute ("Interval", TimeValue (Seconds (1.0)));
  echoClient2.SetAttribute ("PacketSize", UintegerValue (1024));

  UdpEchoClientHelper echoClient3 (interface[3].GetAddress (1), 90);
  echoClient3.SetAttribute ("MaxPackets", UintegerValue (1));
  echoClient3.SetAttribute ("Interval", TimeValue (Seconds (1.0)));
  echoClient3.SetAttribute ("PacketSize", UintegerValue (1024));

  UdpEchoClientHelper echoClient4 (interface[4].GetAddress (1), 90);
  echoClient4.SetAttribute ("MaxPackets", UintegerValue (1));
  echoClient4.SetAttribute ("Interval", TimeValue (Seconds (1.0)));
  echoClient4.SetAttribute ("PacketSize", UintegerValue (1024));

  ApplicationContainer clientApp1 = echoClient1.Install (nodes.Get (1));
  clientApp1.Start (Seconds (2.0));
  clientApp1.Stop (Seconds (20.0));

  ApplicationContainer clientApp2 = echoClient2.Install (nodes.Get (2));
  clientApp2.Start (Seconds (6.0));
  clientApp2.Stop (Seconds (15.0));

  ApplicationContainer clientApp3 = echoClient3.Install (nodes.Get (3));
  clientApp3.Start (Seconds (10.0));
  clientApp3.Stop (Seconds (20.0));

  ApplicationContainer clientApp4 = echoClient4.Install (nodes.Get (4));
  clientApp4.Start (Seconds (14.0));
  clientApp4.Stop (Seconds (20));

  pointToPoint.EnablePcapAll("p2p");

  AsciiTraceHelper ascii;
  pointToPoint.EnableAsciiAll(ascii.CreateFileStream("p2p.tr"));

  AnimationInterface anim("anim.xml");
  anim.SetConstantPosition(nodes.Get(0), 45.0, 45.0);
  anim.SetConstantPosition(nodes.Get(1), 10.0, 15.0);
  anim.SetConstantPosition(nodes.Get(2), 80.0, 85.0);
  anim.SetConstantPosition(nodes.Get(3), 80.0, 10.0);
  anim.SetConstantPosition(nodes.Get(4), 10.0, 80.0);

  Simulator::Run ();
  Simulator::Destroy ();
  return 0;
}
