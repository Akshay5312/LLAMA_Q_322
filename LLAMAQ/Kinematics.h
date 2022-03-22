
#include <ArduinoEigen.h>
#include <ArduinoEigenDense.h>
#include <ArduinoEigenSparse.h>

using namespace Eigen;

template<int outDOF, int inDOF> 
class Kinematics{
private:
public:
    Kinematics();
    virtual Matrix<float, 1, outDOF> FK(Matrix<float, 1, inDOF> actuatorValues, Matrix<float, 1, outDOF> previousState);
    virtual Matrix<float, 1, inDOF> IK(Matrix<float, 1, outDOF> actuatorValues, Matrix<float, 1, outDOF> currentState);

    //virtual Matrix<float, inDOF, outDOF> Jacobian(Matrix<float, 1, inDOF> actuatorValues, Matrix<float, 1, outDOF> previousState);
    


};