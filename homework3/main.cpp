#include "pugixml.hpp"
#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Station {
public:
    string number;
    string type_of_vehicle;
    vector<string> location;
    vector<string> routes;
    vector<double> coords;
};

//fixed const
string maximumRoute(const int type, const vector<Station> &all_stations, const vector<string> &vehicle_types, const int number_of_stations) {
    vector<string> routes;
    vector<int> routes_length;
    //fixed use range-based for
    for (auto &i : all_stations) {
        for (auto &j : i.routes) {
            if (std::find(routes.begin(), routes.end(), j) ==
                routes.end()) {  //для каждой остановки с данным типом транспорта добавляем все ее маршруты
                if (i.type_of_vehicle == vehicle_types[type])
                    routes.push_back(j);
            }
        }
    }

    routes_length.reserve(routes.size());
    for (int i = 0; i < routes.size(); i++)
        routes_length.push_back(0);

    for (int i = 0; i < routes.size(); i++) {
        for (int j = 0; j < number_of_stations; j++) {
            if (std::find(all_stations[j].routes.begin(), all_stations[j].routes.end(),
                          routes[i])  //для каждого маршрута ищем суммарное кол-во станций
                != all_stations[j].routes.end()) {
                if (all_stations[j].type_of_vehicle == vehicle_types[type]) {
                    routes_length[i] += 1;
                }
            }
        }
    }

    //fixed max if a function
    int maxroute = routes_length[0];
    for (int i : routes_length) {
        if (i > maxroute) {
            maxroute = i;
        }
    }
    return std::to_string(maxroute);

}


double
maximumRouteLenght(const int type, const vector<Station> &all_stations, const vector<string> &vehicle_types, const int number_of_stations) {
    vector<string> routes;
    vector<vector<double>> stations;
    vector<double> routes_length;
    for (auto &i : all_stations) {
        for (auto &j : i.routes) {
            if (std::find(routes.begin(), routes.end(), j) ==
                routes.end()) {  //для каждой остановки с данным типом транспорта добавляем все ее маршруты
                if (i.type_of_vehicle == vehicle_types[type])
                    routes.push_back(j);
            }
        }
    }
    for (int i = 0; i < number_of_stations; i++) {
        for (int j = 0; j < routes.size(); j++) {
            stations.emplace_back();
            if (std::find(all_stations[i].routes.begin(), all_stations[i].routes.end(), routes[j]) !=
                //ищем все станции для каждого маршрута
                all_stations[i].routes.end()) {
                if (all_stations[i].type_of_vehicle == vehicle_types[type]) {
                    stations[j].push_back(i);
                }
            }
        }
    }

    for (int i = 0; i < routes.size(); i++) {
        double length = 0;
        for (int j = 0; j < stations[i].size() - 1; j++) {
            length += sqrt(pow(all_stations[stations[i][j + 1]].coords[0] - all_stations[stations[i][j]].coords[0], 2)
                           +
                           pow(all_stations[stations[i][j + 1]].coords[1] - all_stations[stations[i][j]].coords[1], 2));
        }
        routes_length.push_back(length);
    }

    int maxroute = routes_length[0];
    for (int i : routes_length) {
        if (i > maxroute) {
            maxroute = i;
        }
    }
    return maxroute;
}


string maximumStreetRoutes(const vector<Station> &all_stations, const int number_of_stations) {
    vector<string> streets;
    vector<int> street_length;
    for (auto &i : all_stations) {
        for (auto &j : i.location) {
            if ((std::find(streets.begin(), streets.end(), j) == streets.end())) //для каждой остановки добавляем улицы
                streets.push_back(j);
        }
    }
    street_length.reserve(streets.size());
    for (int i = 0; i < streets.size(); i++)
        street_length.push_back(0);

    for (int i = 0; i < streets.size(); i++) {
        for (auto &j : all_stations) {
            if (std::find(j.location.begin(), j.location.end(), streets[i]) !=
                //для каждой улицы считаем кол-во остановок на ней
                j.location.end())
                street_length[i] += 1;
        }
    }

    int maxroute = street_length[0];
    int j = 0;
    for (int i = 0; i < street_length.size(); ++i) {
        if (street_length[i] > maxroute) {
            maxroute = street_length[i];
            j = i;
        }
    }
    return streets[j];
}


int main() {
    int number_of_stations = 0;
    vector<string> vehicle_types;
    vector<Station> all_stations;
    pugi::xml_document doc;
    doc.load_file("data.xml");
    pugi::xml_node stations = doc.child("dataset");

    for (pugi::xml_node station = stations.first_child(); station; station = station.next_sibling()) {
        Station cur_station;
        cur_station.number = station.child_value("number");
        number_of_stations = stoi(cur_station.number);
        cur_station.type_of_vehicle = station.child_value("type_of_vehicle");
        if (std::find(vehicle_types.begin(), vehicle_types.end(), cur_station.type_of_vehicle) == vehicle_types.end())
            vehicle_types.push_back(cur_station.type_of_vehicle);
        string tmp_str;
        tmp_str = station.child_value("location");
        for (int i = 0; i < tmp_str.size(); i++)
            if (tmp_str[i] == ',')
                tmp_str.erase(i + 1);
        if (!tmp_str.empty()) {
            std::stringstream ss(tmp_str);
            std::vector<std::string> tokens;
            std::string buf;
            while (std::getline(ss, buf, ','))
                cur_station.location.push_back(buf);
        }

        tmp_str = station.child_value("routes");
        for (char &t : tmp_str) {
            if (t == '.' || t == ',')
                t = ' ';
        }
        std::stringstream ss(tmp_str);
        std::string buf;
        while (ss >> buf)
            cur_station.routes.push_back(buf);

        int i = 0;
        string crd1;
        string crd2;
        tmp_str = station.child_value("coordinates");
        while (tmp_str[i] != ',') {
            crd1 += tmp_str[i];
            i++;
        }
        crd2 = tmp_str.substr(i + 1);
        cur_station.coords.push_back(stod(crd1));
        cur_station.coords.push_back(stod(crd2));

        all_stations.push_back(cur_station);
    }

    cout << "Маршрут автобуса с наибольшим числом остановок -------->  "
         << maximumRoute(0, all_stations, vehicle_types, number_of_stations) << endl;
    cout << "Маршрут троллейбуса с наибольшим числом остановок --------> "
         << maximumRoute(1, all_stations, vehicle_types, number_of_stations) << endl;
    cout << "Маршрут трамвая с наибольшим числом остановок --------> "
         << maximumRoute(2, all_stations, vehicle_types, number_of_stations) << endl;
    cout << "Маршрут автобуса с наибольшей длиной --------> "
         << maximumRouteLenght(0, all_stations, vehicle_types, number_of_stations) << endl;
    cout << "Маршрут троллейбуса с наибольшей длиной --------> "
         << maximumRouteLenght(1, all_stations, vehicle_types, number_of_stations) << endl;
    cout << "Маршрут трамвая с наибольшей длиной --------> "
         << maximumRouteLenght(2, all_stations, vehicle_types, number_of_stations) << endl;
    cout << "Улица с наибольшим количеством остановок --------> " << maximumStreetRoutes(all_stations, number_of_stations);
    return 0;
}