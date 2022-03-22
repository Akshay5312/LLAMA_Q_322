#include "Kinematics.h"

enum JOINTTYPE{ROTARY, PRISMATIC, FIXED};

template<int inDOF>
class KinematicChainKinematics{
    private:
        float** dHP;
        JOINTTYPE* jT;
        Matrix<float, 4, 4> DHtoFrame(float* DHlist){
            d = DHlist[0];
            theta = DHlist[1];
            a = DHlist[2];
            alpha = DHlist[3];
            Matrix<float, 4, 4> Frame{
                {cos(theta), -cos(alpha)*sin(theta),  sin(alpha)*sin(theta), a*cos(theta)},
                {sin(theta),  cos(alpha)*cos(theta), -sin(alpha)*cos(theta), a*sin(theta)},
                {         0,             sin(alpha),             cos(alpha),            d},
                {         0,                      0,                      0,            1}
            };
        }

        MatrixXd findNullSpace(Matrix<float, 4, 4> aMatrix){
            CompleteOrthogonalDecomposition<Matrix<float, 4, 4> > cod;
            cod.compute(aMatrix);
            MatrixXd V = cod.matrixZ().transpose();
            MatrixXd Null_space = V.block(0, cod.rank(),V.rows(), V.cols() - cod.rank());
            MatrixXd P = cod.colsPermutation();
            Null_space = P * Null_space;
        }

        Matrix<float, 1, 6> decomPose(Matrix<float, 4, 4> Pose){
            Matrix<float, 4,4> I = Identity(4);


        }

    public:
    KinematicChainKinematics(float** dHPIn, JOINTTYPE* linkTypes):Kinematics(){
        dHP = dHPIn;
        jT = linkTypes;
    }

    
    virtual Matrix<float, 1, 6> FK(Matrix<float, 1, inDOF> actuatorValues, Matrix<float, 1, outDOF> previousState){

    }
    

};