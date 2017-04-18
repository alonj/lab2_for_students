#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "Statistics.h"

#define dataset_path_nix "/mnt/share/students/LAB2/winequality.csv"
#define dataset_path_win "C:\\Users\\alonj\\Desktop\\Lab 2\\winequality.csv"

using std::string;
using std::vector;
using std::ifstream;
using std::stringstream;
using std::cout;
using std::endl;


bool loadDataset(const string& fileName, vector<string>& dataNames, vector<vector<double>>& data){

    ifstream infile(fileName);
    string line;
    size_t number_of_variables(0);
    //First we read the first line of the file, which specifies the names of the variables
    if (getline(infile, line)){
        stringstream s(line);
        while ( s.good() )
        {
            string svariableName;
            getline( s, svariableName, ',' );
            dataNames.push_back(svariableName);
            data.push_back(vector<double>());
            number_of_variables++;
        }
    }
    while (getline(infile, line))
    {
            double val;
            stringstream s(line);
            vector<vector<double> >::size_type variable_id=0;
            while ( s >> val ){
                if (s.peek() == ',')
                    s.ignore();
                data[variable_id].push_back(val);
                variable_id++;
            }
            if (variable_id!=number_of_variables) return false;
    }
    return true;

}


int main() {

    vector<string> names;
    vector<vector<double>> data;
    string fileName = dataset_path_win ;
    if ( !loadDataset(fileName, names, data) ) return 1;
    int dataProperties[data.size()][3];
    //this is loop that prints all variables (features), one by one
/*
    for(vector<vector<double> >::const_iterator vvi_iterator = data.begin();vvi_iterator!=data.end();++vvi_iterator) {
        cout<<"Feature: "<<endl;
        for(vector<double>::const_iterator vi_iterator = (*vvi_iterator).begin();vi_iterator!=(*vvi_iterator).end();++vi_iterator) {
            cout<<*vi_iterator<<" ";
        }
        cout<<endl;
    }

*/
    for(vector<vector<double>>::const_iterator vvi_iterator = data.begin();vvi_iterator!=data.end();++vvi_iterator)
    {
        dataProperties[()vvi_iterator][]
    }
    cout<<"Number of features:"<< data.size() <<endl;
    cout<<"First Feature Mean: "<< Mean(data.front()) <<endl;
    cout<<"First Feature Median: "<< Median(data.front()) <<endl;
    cout<<"First Feature Standard deviation: "<< Strdev(data.front()) <<endl;
    cout<<"Correlation between feature 1 and 2: "<< Correl(data.front(), data.at(1)) <<endl;

    return 0;
}