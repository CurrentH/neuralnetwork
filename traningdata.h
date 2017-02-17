#ifndef TRANINGDATA_H
#define TRANINGDATA_H

#include <vector>
#include <cstdlib>
#include <fstream>
#include <sstream>

class TrainingData
{
    public:
        //  Public methods
        TrainingData( const std::string filename );
        bool isEof( void );
        void getTopology( std::vector<unsigned> &topology );

        // Returns the number of input values read from the file:
        unsigned getNextInputs( std::vector<double> &inputVals );
        unsigned getTargetOutputs( std::vector<double> &targetOutputVals );

    private:
        //  Private attributes
        std::ifstream m_trainingDataFile;
};

#endif // TRANINGDATA_H
