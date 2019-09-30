# Illumio Coding Assignment: Firewall
Firewall class that accepts input and compares the input with file read in. Returns true if input matches, false otherwise.

# Testing 
I tested the code I wrote using a main.cpp file and inputted various combintions of the firewall protocols.

    
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
# Refinements
If I had more time I would've been able to write the limiter for the IP protocols. I feel like a lot of my code required tweaks that could've been done in other ways, but with the limit, I had to hardcode in instances where I knew that the code would have a range and I feel like I cheated there. 

# Team
I would like to join the data team.
