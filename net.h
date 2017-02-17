#ifndef NET_H
#define NET_H

#include "neuron.h"

class net
{
    typedef std::vector<neuron> layer;

    public:
        //  Public methods
        net( const std::vector<unsigned> &topology);
        void feedForward( const std::vector<double> &inputVals );
        void backProp( const std::vector<double> &targetVals );
        void getResults( std::vector<double> &resultVals ) const;
        double getRecentAverageError(void) const;

    private:
        //  Private attributes
        std::vector<layer> m_layers;   // m_layers[layerNum][neuronNum]
        double m_error;
        double m_recentAverageError;
        static double m_recentAverageSmoothingFactor;

};

#endif // NET_H
