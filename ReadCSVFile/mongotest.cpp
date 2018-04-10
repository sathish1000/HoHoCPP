#include <iostream>

#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/json.hpp>

#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>

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

   ostream& printTrainData(ostream &out, TrainInfo& TrainData)
   { 
     out << " TrainNo " << TrainData.TrainNo
             << " TrainName " << TrainData.TrainName
             << " IslNo " << TrainData.IslNo
             << " StationCode " << TrainData.StationCode
             << " StationName " << TrainData.StationName
             << " ArrivalTime " << TrainData.ArrivalTime
             << " DepartureTime " << TrainData.DepartureTime
             << " Distance " << TrainData.Distance
             << " SourceStationCode " << TrainData.SourceStationCode
             << " SourceStationName " << TrainData.SourceStationName
             << " DestinationStationCode " << TrainData.DestinationStationCode
             << " DestinationStationName " << TrainData.DestinationStationName << endl;
     return out;
   }

};

int main(int, char**) {
    mongocxx::instance inst{};
    mongocxx::client conn{mongocxx::uri{}};

    bsoncxx::builder::stream::document document{};

    auto collection = conn["testdb"]["testcollection"];

    string line;
    ifstream input("railwayTT.csv");
    std::vector<string> Train;
    TrainInfo TrainData;
    static int count=0;

    while (true)
    {
        getline(input,line);
        if (!input.eof())
        {
			while (line.find(",", 0) != std::string::npos)
			{ //does the string a comma in it?
				size_t  pos = line.find(",", 0); //store the position of the delimiter
				std::string temp = line.substr(0, pos);      //get the token
				line.erase(0, pos + 1);          //erase it from the source 
				Train.push_back(temp);                //and put it into the array
			}

			Train.push_back(line);

			TrainData.TrainNo=Train[0];
			TrainData.TrainName=Train[1];
			TrainData.IslNo=std::stoi(Train[2]);
			TrainData.StationCode=Train[3];
			TrainData.StationName=Train[4];
			TrainData.ArrivalTime=Train[5];
			TrainData.DepartureTime=Train[6];
			TrainData.Distance=std::stoi(Train[7]);
			TrainData.SourceStationCode=Train[8];
			TrainData.SourceStationName=Train[9];
			TrainData.DestinationStationCode=Train[10];
			TrainData.DestinationStationName=Train[11];        


			document << "TrainNo" << TrainData.TrainNo
				     << "TrainName" << TrainData.TrainName
				     << "IslNo" << TrainData.IslNo
				     << "StationCode" << TrainData.StationCode
				     << "StationName" << TrainData.StationName
				     << "ArrivalTime" << TrainData.ArrivalTime
				     << "DepartureTime" << TrainData.DepartureTime
				     << "Distance" << TrainData.Distance
				     << "SourceStationCode" << TrainData.SourceStationCode
				     << "SourceStationName" << TrainData.SourceStationName
				     << "DestinationStationCode" << TrainData.DestinationStationCode
				     << "DestinationStationName" << TrainData.DestinationStationName;


            cout << count++ <<endl;
		    collection.insert_one(document.view());
		}
        else
        {
            cout << "Done" << endl;
            break;
        }
	}

//    auto cursor = collection.find({});
//    for (auto&& doc : cursor) {
//        std::cout << bsoncxx::to_json(doc) << std::endl;
//    }
}
