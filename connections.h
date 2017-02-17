#ifndef CONNECTIONS_H
#define CONNECTIONS_H

#include <cstdlib>

class connections
{
    public:
        //  Public methods
        connections();
        double getDeltaWeight( void ) const;
        double getWeight( void ) const;
        void setDeltaWeight( double newDeltaWeight );
        void setWeight( void );

    private:
        //  Private methods
        static double randomWeight( void );

        //  Private attributes
        double weight;
        double deltaWeight;
};

#endif // CONNECTIONS_H
