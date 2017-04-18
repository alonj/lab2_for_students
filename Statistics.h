//
// Created by shraga89@st.technion.ac.il on 3/16/17.
//

#ifndef STATISTICS_H_
#define STATISTICS_H_

#include <cstdlib>
#include <vector>


double Median(  const std::vector<double>& xv );
double Mean( const std::vector<double>& xv);
double Variance( const std::vector<double>& xv);
double Strdev(const std::vector<double>& xv);
double Covariance(const std::vector<double>& xv , const std::vector<double>& yv);
double Correl(const std::vector<double>& xv , const std::vector<double>& yv);


#endif//