#include <iostream>
bool dotCheck(std::string ip) {
    int dot = 0;
    for (int n = 0; n < ip.size(); n++) {
        if (ip[n] == '.') {
            dot++;
        }
        if (dot > 3) {
            return false;
        }
    }return true;
}

bool zeroCheck(std::string ip) {
    for (int n = 0; n < ip.size(); n++) {
        if ((ip[n] && ip[n + 1]) == '0') {
            return false;
        }
    }return true;
}

bool numberCheck(std::string ip) {
    for (int n = 0; n < ip.size(); n++) {
        if (ip[n] >= '0' && ip[n] <= '9' && ip[n] == '.') {
            return false;
        }
    }return true;
}

bool numberSize(std::string ip) {
    std::string ipCheck;
    int number = 0, n = 0, ok = 0;
    ipCheck = ip;
    for (int i = 0; i < 4; i++) {
        if (ip[n] == '.') {
            if (i < 3) {
                number = number / 10;
            }
            if (number < 256) {
                ok++;
            }
            i = -1;
            number = 0;
        }
        else if (i == 0) {
            number = number + ((ip[n] - '0') * 100);
        }
        else if (i == 1) {
            number = number + ((ip[n] - '0') * 10);
        }
        else if (i == 2) {
            number = number + (ip[n] - '0');
        }
        n++;
        if (n > ip.size()) {
            if (ok == 4) {
                return true;
            }
            else return false;
            break;
        }
    }
}
int main()
{
    std::string ip;
    std::cout << "Enter IP: \n";
    std::cin >> ip;
    if (dotCheck(ip) == false || numberCheck(ip) == false || numberSize(ip) == false) {
        std::cout << "Not Valid";
    }
    else std::cout << "Valid";
}
