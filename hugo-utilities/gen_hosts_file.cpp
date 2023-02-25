#include <bits/stdc++.h>
#include <fstream>
using namespace std;


struct node{ // Represents either a client or a replica
  int id;
  string ip;
  int port_1;
  int port_2;
  bool is_client;
};

vector<node> clients;
vector<node> replicas;
set<string> st;


node generate_node(int id, int p1, int p2, bool ic){
  node current;
  current.id = id;

  do{
    int ip1 = rand()%255, ip2 = rand()%255, ip3 = rand()%255, ip4 = rand()%255;
    current.ip = to_string(ip1) + '.' + to_string(ip2) + '.' + to_string(ip3) + '.' + to_string(ip4);
  } while(st.find(current.ip) != st.end());
  st.insert(current.ip);

  current.port_1 = p1;
  current.port_2 = p2;
  current.is_client = ic;  
  return current;
}

void print_hosts_config(){
  ofstream mf;
  mf.open("hosts.config");
  for(auto &elem : replicas){
    mf << elem.id << ' ' << elem.ip << ' ' << elem.port_1 << ' ' << elem.port_2 << '\n';
  } mf << '\n';
  for(auto &elem : clients){
    mf << elem.id << ' ' << elem.ip << ' ' << elem.port_1 << '\n';
  }
  mf.close();
}


void print_shadow_yaml(){
  // This function is badly written for the most part
  // Only writing with inspiration in delphi, to make sure it compiles
  ofstream mf;
  int c_idx = 0, r_idx = 0;
  mf.open("shadow.yaml");
  mf << "general:" << '\n';
  mf << "  stop_time: 9000 s" << '\n';
  mf << "  data_directory: /home/blue/hugo-shadow-bft-starter/results" << '\n';
  mf << "  parallelism: 20" << '\n';

  mf << "experimental:" << '\n';
  mf << "  use_legacy_working_dir: true" << '\n';
  mf << "  runahead: 630 us" << '\n';
  mf << "network:" << '\n';
  mf << "  graph:" << '\n';
  mf << "    type: gml" << '\n';
  mf << "    file:" << '\n';
  mf << "      path: network.gml" << '\n';
  mf << "  use_shortest_path: false" << '\n';
  mf << "hosts:" << '\n';

  for(auto &elem : replicas){
    mf << "  bft_smart_replica" << r_idx << ":\n";
    mf << "    ip_addr: " << elem.ip << '\n';
    mf << "    network_node_id: " << r_idx++ << '\n';
    mf << "    processes:\n";
    mf << "      - path: /usr/bin/java\n";
    mf << "        environment: ''\n";
    mf << "        args: >-\n          -Djava.security.properties=config/java.security\n          -Dlogback.configurationFile=config/logback.xml -cp lib/* -Xmx500m\n          bftsmart.demo.microbenchmarks.ThroughputLatencyServer 0 2000 0 0 false\n          nosig\n";
    mf << "        start_time: 0 s\n";
  }

   for(auto &elem : clients){
    mf << "  bft_smart_client" << c_idx++ << ":\n";
    mf << "    ip_addr: " << elem.ip << '\n';
    mf << "    network_node_id: " << r_idx++ << '\n';
    mf << "    processes:\n";
    mf << "      - path: /usr/bin/java\n";
    mf << "        environment: ''\n";
    mf << "        args: >-\n          -Djava.security.properties=config/java.security\n          -Dlogback.configurationFile=config/logback.xml -cp lib/* -Xmx500m\n          bftsmart.demo.microbenchmarks.ThroughputLatencyServer 0 2000 0 0 false\n          nosig\n";
    mf << "        start_time: 64 s\n";
  }

  mf.close();
}


signed main(int argc, char **argv){
  // In time make this not random ?
  srand(time(NULL));

  if(argc != 3){
    cout << "Error: gen_hosts_file is being called with the wrong parameters\n";
    exit(1);
  }

  int num_clients = stoi(argv[1]);
  int num_replicas = stoi(argv[2]);

  int ini_port_replica = 11000;
  int port_client = 11100;

  for(int i=0; i<num_replicas; ++i){
    node replica = generate_node(i, ini_port_replica, ini_port_replica+1, false);
    ini_port_replica += 10;
    replicas.push_back(replica);
  }

  for(int i=0; i<num_clients; ++i){
    node client = generate_node(5000 + 1000 * (i+1), port_client, port_client, false);
    clients.push_back(client);
  }

  print_hosts_config();
  print_shadow_yaml();
}