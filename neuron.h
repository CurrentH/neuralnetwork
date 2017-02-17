#ifndef NEURON_H
#define NEURON_H

#include <vector>
#include <iostream>
#include <cassert>
#include <cmath>

#include "connections.h"

class neuron
{
    typedef std::vector<neuron> layer;

    public:
        //  Public methods
            neuron( unsigned numOutputs, unsigned myIndex );
            void setOutputVal( double val );
            double getOutputVal( void ) const;
            void feedForward( const layer &prevLayer );
            void calculateOutputGradients( double targetVal );
            void calculateHiddenGradients( const layer &nextLayer );
            void updateInputWeights( layer &prevLayer );

    private:
        //  Private methods
            static double transferFunction( double x );
            static double transferFunctionDerivative( double x );
            double sumDOW( const layer &nextLayer ) const;

    private:
        //  Private attributes
            static double eta;      //  [0.0..1.0] overall net training rate
            static double alpha;    //  [0.0..n] multiplier of last weight change (momentum)
            double m_outputVal;
            std::vector< connections > m_outputWeights;
            unsigned m_myIndex;
            double m_gradient;
};

#endif // NEURON_H
