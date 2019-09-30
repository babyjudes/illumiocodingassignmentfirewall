//
//  firewall.h
//  firewall
//
//  Created by Judy Nguyen on 9/29/19.
//  Copyright © 2019 Developer Account. All rights reserved.
//

#ifndef firewall_h
#define firewall_h
#include <fstream>
class Firewall{
public:
    Firewall(string file_path);
    bool accept_packet(string direction, string protocol, int port, string ip_address);
private:
    string direction;
    string protocol;
    string buffer;
    int range1, range2;
    int num_true = 0;
    int port[65536];
    string ip_address;
    bool isValid = true;
    ifstream firewall_rules;
};

Firewall::Firewall(string file_path){
    firewall_rules.open(file_path);
}

bool Firewall::accept_packet(string dir, string proto, int p, string ip){
    int counter = 0;
    while(!firewall_rules.eof()){
        num_true = 0;
        counter++;
        //INFO FROM FILE
        getline(firewall_rules, direction, ',');
        getline(firewall_rules, protocol, ',');
        getline(firewall_rules, buffer, ',');
        firewall_rules>>ip_address;
        
        //CHECK DIRECTION
        if(direction.compare(dir)==0){
            num_true++;
            isValid = true;
        }
        else
            isValid = false;
        
        //CHECK PROTOCOL
        if(protocol.compare(proto)==0){
            num_true++;
            isValid = true;
        }
        else
            isValid = false;
        
        //CHECK PORT
        if(p>65535)
            return false;
        range1 = stoi(buffer);
        if (p == range1){
            num_true++;
            isValid = true;
        }
        if(counter == 2 || counter == 4){
            string delimiter = "-";
            size_t pos = 0;
            string token;
            while ((pos = buffer.find(delimiter)) != std::string::npos) {
                token = buffer.substr(0, pos);
                range1 = stoi(token);
                buffer.erase(0, pos + delimiter.length());
            }
            range2 = stoi(buffer);
            if(p>=range1&&p<=range2){
                num_true++;
                isValid=true;
            }
        }
        
        //CHECK IP
        if(ip_address==ip){
            num_true++;
            isValid = true;
        }
        
        //ARE ALL INPUTS VALID?
        if(num_true==4){
            isValid = true;
            return isValid;
        }
    }
    firewall_rules.close();
    return isValid;
}
#endif /* firewall_h */
