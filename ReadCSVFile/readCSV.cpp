#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class TrainInfo
{
   public:
   string TrainNo;
   string TrainName;
   int IslNo;
   string StationCode;
   string StationName;
   string ArrivalTime;
   string DepartureTime;
   int Distance;
   string SourceStationCode;
   string SourceStationName;
   string DestinationStationCode;
   string DestinationStationName;
};

int main()
{
    string line;
    ifstream input("Test.csv");
    std::vector<TrainInfo> Train;
    while ( input and (!input.eof()))
    {
        TrainInfo TrainData;
        getline(input,line);
        std::replace(line.begin(),line.end(),',',' ');
        stringstream splitline(line);
        splitline >> TrainData.TrainNo >>
                     TrainData.TrainNo >>
                     TrainData.TrainName >>
                     TrainData.IslNo >>
                     TrainData.StationCode >>
                     TrainData.StationName >>
                     TrainData.ArrivalTime >>
                     TrainData.DepartureTime >>
                     TrainData.Distance >>
                     TrainData.SourceStationCode >>
                     TrainData.SourceStationName >>
                     TrainData.DestinationStationCode >>
                     TrainData.DestinationStationName;
    }
    return 0;
}
