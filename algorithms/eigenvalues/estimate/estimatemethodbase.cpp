#include "estimatemethodbase.h"

EstimateMethodBase::EstimateMethodBase()
{
}

void EstimateMethodBase::calculate()
{
    throw "Not implemented";
}

double EstimateMethodBase::getMax()
{
    if (!this->calculated)
    {
        throw "[Estimate eigenvalue] Perform calculations first";
    }
    return this->max;
}

double EstimateMethodBase::getMin()
{
    if (!this->calculated)
    {
        throw "[Estimate eigenvalue] Perform calculations first";
    }
    return this->min;
}
