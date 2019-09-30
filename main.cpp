//
//  main.cpp
//  firewall
//
//  Created by Developer Account on 9/28/19.
//  Copyright © 2019 Developer Account. All rights reserved.
//

#include <iostream>
using namespace std;
#include "firewall.h"

int main() {
    //create a firewall object with a path to the .csv file
    Firewall test("fw.csv");
    
    //should return true
    if(test.accept_packet("outbound", "tcp", 10000, "192.168.10.11"))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
}
