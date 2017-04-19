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
    double dataProperties[data.size()][3];
    double bestCorrel(0.0), weakCorrel(1.0);
    unsigned int dataIndex(0), xBestCorrelIndex(0), yBestCorrelIndex(0), xWeakCorrelIndex(0), yWeakCorrelIndex(0);

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
        dataProperties[dataIndex][0] = Mean(data.at(dataIndex));
        dataProperties[dataIndex][1] = Variance(data.at(dataIndex));
        dataProperties[dataIndex][2] = Strdev(data.at(dataIndex));
        dataIndex++;
    }
    cout<<"Number of features:"<< data.size() <<endl;
/*    cout<<"First Feature Mean: "<< Mean(data.front()) <<endl;
    cout<<"First Feature Median: "<< Median(data.front()) <<endl;
    cout<<"First Feature Standard deviation: "<< Strdev(data.front()) <<endl;
    cout<<"Correlation between feature 1 and 2: "<< Correl(data.front(), data.at(1)) <<endl;*/

    for(int i=0;i<data.size();i++)
    {
        cout<<"Feature #"<<i+1<<":"<<endl;
        cout<<"Mean :              "<<dataProperties[i][0]<<endl;
        cout<<"Variance :          "<<dataProperties[i][1]<<endl;
        cout<<"Standard deviation: "<<dataProperties[i][2]<<endl;
        cout<<endl;
    }
    for(unsigned i=0;i<data.size();i++)
    {
        for(unsigned j=i+1;j<data.size();j++)
        {
            if(dabs(Correl(data.at(i),data.at(j)))>bestCorrel)
            {
                bestCorrel = dabs(Correl(data.at(i), data.at(j)));
                xBestCorrelIndex = i;
                yBestCorrelIndex = j;
            }
            else if(dabs(Correl(data.at(i),data.at(j)))<weakCorrel)
            {
                weakCorrel = dabs(Correl(data.at(i),data.at(j)));
                xWeakCorrelIndex = i;
                yWeakCorrelIndex = j;
            }

        }
    }

    cout<<"Strongest correlation is between features #"<<xBestCorrelIndex+1<<" and #"<<yBestCorrelIndex+1<<": "<<bestCorrel<<endl;
    cout<<"Weakest correlation is between features #"<<xWeakCorrelIndex+1<<" and #"<<yWeakCorrelIndex+1<<": "<<weakCorrel<<endl;

    return 0;
}