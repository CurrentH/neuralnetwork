#include "traningdata.h"
#include "net.h"

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

    int trainingPass = 1;

    std::vector<double> inputVals;
    std::vector<double> targetVals;
	std::vector<double> resultVals;

    while ( !trainData.isEof() )
    {
    	// Get new input data and feed it forward:
		if ( trainData.getNextInputs(inputVals) != topology[0] )
		{
			break;
		}


		myNet.feedForward( inputVals );
		trainData.getTargetOutputs( targetVals );
		assert( targetVals.size() == topology.back() );
		myNet.backProp( targetVals );

		if( trainingPass%10000 == 0 )
		{
			std::cout << std::endl << "Pass " << trainingPass << std::endl;
			// Report how well the training is working, average over recent samples:
			std::cout << "Net recent average error: " << myNet.getRecentAverageError() << std::endl;
		}

/*
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
*/

        trainingPass++;
    }

    std::cout << std::endl << "Done at " << trainingPass << std::endl;
    std::cout << "Net average error: " << myNet.getRecentAverageError() << std::endl;
}
