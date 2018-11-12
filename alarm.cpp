#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <chrono>
#include <thread>
#include <string>
#include <vector>
#include <sstream>
#include <ctime>

std::string trim(std::string str);
std::vector<std::string> splitString(std::string str, char separator);
std::vector<int> currentTime();
bool isTime(int hour, int min);
using namespace std::literals::chrono_literals;
int main(){
    //Initialize hour and minute
    int hr, min;
    //initialize alarmTime
    std::string alarmTime;
     while(true){
        //Prompt for input
        std::cout << "Enter alarm time (hh:mm): ";
        //Accept input and save to alarmTime
        std::cin >> alarmTime;
        //Trim input
        alarmTime = trim(alarmTime);
        //Check for quit/exit/q to exit loop
        if((alarmTime == "exit") | (alarmTime == "quit") | (alarmTime == "q")){
            break;
        }
        //Check if ':' is the separator, then split the string accordingly
        if(alarmTime.find(':') != std::string::npos){
            std::vector<std::string> timeVec = splitString(alarmTime, ':');
            hr = stoi(timeVec[0]);
            min = stoi(timeVec[1]);
            break;
        }
    }
    std::cout << "Next up check hr, and min until isTime returns true. Need to use a timer!\n";
    return 0;
}
//FUNCTIONS
std::string trim(std::string str){
    if(str[0] == ' '){
        str.erase(0, str.find_first_not_of(" \n\r\t"));
    }
    if(str[str.size()-1] == ' '){
        str.erase(str.find_last_not_of(" \n\r\t") + 1, str.size() - 1);
    }
    return str;
}
std::vector<std::string> splitString(std::string str, char separator){
    std::stringstream ss(str);
    std::string tempString;
    std::vector<std::string> strVec;
    while(getline(ss, tempString, separator)){
        strVec.push_back(tempString);
    }
    return strVec;
}
std::vector<int> currentTime(){
    std::vector<int> tVec;
    auto currTime = std::chrono::system_clock::now();
    std::time_t nowTime = std::chrono::system_clock::to_time_t(currTime);
    tm locTime = *localtime(&nowTime);
    tVec.push_back(locTime.tm_hour);
    tVec.push_back(locTime.tm_min);
    return tVec;
}
bool isTime(int hour, int min){
    if((currentTime()[0] == hour) & (currentTime()[1] == min)){
        return true;
    }
    return false;
}

//END FUNCTIONS
