#include "net.h"
#include "traningdata.h"

void showVectorVals(std::string label, std::vector<double> &v)
{
    std::cout << label << " ";
    for (unsigned i = 0; i < v.size(); ++i) {
        std::cout << v[i] << " ";
    }

    std::cout << std::endl;
}

int main()
{
    trainingData trainData("trainingData.txt");

    std::vector<unsigned> topology;
    trainData.getTopology( topology );

    net myNet( topology );

    int trainingPass = 0;

    std::vector<double> inputVals, targetVals, resultVals;

    while ( !trainData.isEof() )
    {
        ++trainingPass;
        std::cout << std::endl << "Pass " << trainingPass;

        // Get new input data and feed it forward:
        if ( trainData.getNextInputs(inputVals) != topology[0] )
        {
            break;
        }

        showVectorVals( ": Inputs:", inputVals );
        myNet.feedForward( inputVals );

        // Collect the net's actual output results:
        myNet.getResults( resultVals );
        showVectorVals( "Outputs:", resultVals );

        // Train the net what the outputs should have been:
        trainData.getTargetOutputs( targetVals );
        showVectorVals( "Targets:", targetVals );
        assert( targetVals.size() == topology.back() );

        myNet.backProp( targetVals );

        // Report how well the training is working, average over recent samples:
        std::cout << "Net recent average error: " << myNet.getRecentAverageError() << std::endl;
    }

    std::cout << std::endl << "Done" << std::endl;
}
