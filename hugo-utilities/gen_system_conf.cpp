#include <bits/stdc++.h>
#include <fstream>
using namespace std;

/* Default variables - For now global*/

ofstream mf;


class systema{
    public:
    string shutdownhook = "true";
    string samebatchsize = "false";
    long long numrepliers = 16;
    string bft = "true";
    
    void print_c_name(){
        mf << "system.";
    }

    void print(){
        print_c_name(), mf << "shutdownhook = " << shutdownhook << '\n';
        print_c_name(), mf << "samebatchsize = " << samebatchsize << '\n';
        print_c_name(), mf << "numrepliers = " << numrepliers << '\n';
        print_c_name(), mf << "bft = " << bft << '\n';
    }
};

class communication : public systema{
    public:

    string secretKeyAlgorithm = "PBKDF2WithHmacSHA1", secretKeyAlgorithmProvider = "SunJCE";
    string hashAlgorithm = "SHA-256", hashAlgorithmProvider = "SUN";
    string signatureAlgorithm = "SHA256withECDSA", signatureAlgorithmProvider = "BC";
    string defaultKeyLoader = "ECDSA", useSenderThread = "true";
    string defaultkeys = "true", bindaddress = "auto";
    long long inQueueSize = 500000;
    long long outQueueSize = 500000;
    long long useSignatures = 0;
    
    void print_sc_name(){
        print_c_name(), mf << "communication.";
    }

    void print(){
        print_sc_name(), mf << "secretKeyAlgorithm = " << secretKeyAlgorithm << '\n';
        print_sc_name(), mf << "secretKeyAlgorithmProvider = " << secretKeyAlgorithmProvider << '\n';
        print_sc_name(), mf << "hashAlgorithm = " << hashAlgorithm << '\n';
        print_sc_name(), mf << "hashAlgorithmProvider = " << hashAlgorithmProvider << '\n';
        print_sc_name(), mf << "signatureAlgorithm = " << signatureAlgorithm << '\n';
        print_sc_name(), mf << "signatureAlgorithmProvider = " << signatureAlgorithmProvider << '\n';
        print_sc_name(), mf << "defaultKeyLoader = " << defaultKeyLoader << '\n';
        print_sc_name(), mf << "useSenderThread = " << useSenderThread << '\n';
        print_sc_name(), mf << "defaultkeys = " << defaultkeys << '\n';
        print_sc_name(), mf << "bindaddress = " << bindaddress << '\n';
        print_sc_name(), mf << "inQueueSize = " << inQueueSize << '\n';
        print_sc_name(), mf << "outQueueSize = " << outQueueSize << '\n';
        print_sc_name(), mf << "useSignatures = " << useSignatures << '\n';
    }
};

class totalordermulticast : public systema{
    public: 
    
    long long batchtimeout = -1;
    string fairbatch = "true";
    long long nonces = 10;
    string verifyTimestamps = "false";
    string state_transfer = "true";
    long long highMark = 10000;
    long long revival_highMark = 10;
    long long timeout_highMark = 200;
    string log = "true";
    string log_parallel = "false";
    string log_to_disk = "false";
    string sync_log = "false";
    long long checkpoint_period = 1024;
    long long global_checkpoint_period = 120000;
    string checkpoint_to_disk = "false";
    string sync_ckp = "false";
    long long maxBatchSizeInBytes = 999999999;
    long long maxbatchsize = 1000;
    long long timeout = 2000;

    void print_sc_name(){
        print_c_name(), mf << "totalordermulticast.";
    }

    void print(){
        print_sc_name(), mf << "batchtimeout = " << batchtimeout << '\n';
        print_sc_name(), mf << "fairbatch = " << fairbatch << '\n';
        print_sc_name(), mf << "nonces = " << nonces << '\n';
        print_sc_name(), mf << "verifyTimestamps = " << verifyTimestamps << '\n';
        print_sc_name(), mf << "state_transfer = " << state_transfer << '\n';
        print_sc_name(), mf << "highMark = " << highMark << '\n';
        print_sc_name(), mf << "revival_highMark = " << revival_highMark << '\n';
        print_sc_name(), mf << "timeout_highMark = " << timeout_highMark << '\n';
        print_sc_name(), mf << "log = " << log << '\n';
        print_sc_name(), mf << "log_parallel = " << log_parallel << '\n';
        print_sc_name(), mf << "log_to_disk = " << log_to_disk << '\n';
        print_sc_name(), mf << "sync_log = " << sync_log << '\n';
        print_sc_name(), mf << "checkpoint_period = " << checkpoint_period << '\n';
        print_sc_name(), mf << "global_checkpoint_period = " << global_checkpoint_period << '\n';
        print_sc_name(), mf << "checkpoint_to_disk = " << checkpoint_to_disk << '\n';
        print_sc_name(), mf << "sync_ckp = " << sync_ckp << '\n';
        print_sc_name(), mf << "maxBatchSizeInBytes = " << maxBatchSizeInBytes << '\n';
        print_sc_name(), mf << "maxbatchsize = " << maxbatchsize << '\n';
        print_sc_name(), mf << "timeout = " << timeout << '\n';
    }
};

class ssltls : public systema{
    public:

    string protocol_version = "TLSv1.2";
    string key_store_file = "EC_KeyPair_256.pkcs12";
    string enabled_ciphers = "TLS_ECDHE_ECDSA_WITH_AES_128_GCM_SHA256";

    void print_sc_name(){
        print_c_name(); mf << "ssltls.";
    }

    void print(){
        print_sc_name(), mf << "protocol_version = " << protocol_version << '\n';
        print_sc_name(), mf << "key_store_file = " << key_store_file << '\n';
        print_sc_name(), mf << "enabled_ciphers = " << enabled_ciphers << '\n';
    }
};

class ttp : public systema{
    public: 

    long long id = 7002;

    void print_sc_name(){
        print_c_name(); mf << "ttp.";
    }

    void print(){
        print_sc_name(), mf << "id = " << id << '\n';
    }
};

class initial : public systema{
    public:
    
    string view = "0,1,2,3";

    void print_sc_name(){
        print_c_name(); mf << "initial.";
    }

    void print(){
        print_sc_name(), mf << "view = " << view << '\n';
    }
};

class servers : public systema{
    public:

    long long num = 4;
    long long f = 0;

    void print_sc_name(){
        print_c_name(); mf << "servers.";
    }

    void print(){
        print_sc_name(), mf << "num = " << num << '\n';
        print_sc_name(), mf << "f = " << f << '\n';
    }
};

class client : public systema{
    public: 
    
    long long invokeOrderedTimeout = 40;

    void print_sc_name(){
        print_c_name(); mf << "client.";
    }

    void print(){
        print_sc_name(), mf << "invokeOrderedTimeout = " << invokeOrderedTimeout << '\n';
    }

};


signed main(){
    systema ms;
    communication ms_comm;
    totalordermulticast ms_tom;
    ssltls ms_tls;
    ttp ms_ttp;
    initial ms_init;
    client ms_clients;
    servers ms_servers;


    mf.open(".syst_conf");

    ms_comm.print(), mf << '\n';
    ms_tom.print(), mf << '\n';
    ms_tls.print(), mf << '\n';
    ms_ttp.print(), mf << '\n';
    ms.print(), mf << '\n';
    ms_init.print(), mf << '\n';
    ms_servers.print(), mf << '\n';
    ms_clients.print(), mf << '\n';

    mf.close();
}