//
// Created by shraga89@st.technion.ac.il on 3/16/17.
//

#include "Statistics.h"
#include <iostream>
#include <algorithm>

using std::vector;

double Median(  const vector<double>& xv )
{
    //we create temporal copy of the given constant vector
    vector<double> dv_cpy;
    copy(xv.begin(), xv.end(), back_inserter(dv_cpy) );
    //we sort it to find the median
    sort( dv_cpy.begin(), dv_cpy.end() );
    double median(0.0);
    size_t center = dv_cpy.size()/2;
    if ( dv_cpy.size()%2 == 0)
    {
        median = (dv_cpy[center]+dv_cpy[center+1])/2.0;
    }
    else
    {
        median = dv_cpy[center+1];
    }
    return median;
}

double Mean( const vector<double>& xv)
{
    double sum(0.0);
    for(int i=0;i<xv.size();i++)
        sum+=xv[i];
    return sum/(int)xv.size();
}

double Variance( const vector<double>& xv)
{
    double sum(0.0);
    double mean(Mean(xv));
    for(int i=0;i<xv.size();i++)
        sum+=pow((xv[i]-mean),2);
    return sum/(int)(xv.size()-1);
}

double Strdev(const vector<double>& xv)
{
    return sqrt(Variance(xv));
}

double Covariance(const vector<double>& xv , const vector<double>& yv)
{
    double sum(0.0);
    double meanX(Mean(xv));
    double meanY(Mean(yv));
    for(int i=0;i<xv.size();i++)
        sum+= (xv[i]-meanX) * ((yv[i])-meanY);
    return sum/(int)(xv.size()-1);
}

double Correl(const vector<double>& xv , const vector<double>& yv)
{
    double covXY = Covariance(xv,yv);
    double stdX = Strdev(xv);
    double stdY = Strdev(yv);
    return covXY/(stdX*stdY);
}

double doubleAbs(double a)
{
    if(a<0)
        return a*(-1);
    else
        return a;
}