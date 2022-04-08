/* 
CAMP
SixSixtySix anusO1
*/
#include <iostream>
#include <SFML/Network.hpp>
#include <string>
using namespace std;
bool is_port_open(const std::string& address, int port) {
    return (sf::TcpSocket().connect(address, port) == sf::Socket::Done);
}
int main() {
    int target, port;
    std::cout << "target: ";
    std::cin >> target;
    if (is_port_open(target, targetport))
        std::cout << "OPEN";
    else
        std::cout << "CLOSED";
    return 0;
}
