#include "interpolationLagrange.h"

interpolationLagrange::interpolationLagrange(){
    this->clearAll();
}

interpolationLagrange::~interpolationLagrange(){
    this->clearAll();
}

mpTypes::mpComplex_t interpolationLagrange::interpolateSingleValue(const std::vector<mpTypes::mpComplex_t> &t_i, const std::vector<mpTypes::mpComplex_t> &u_i, const mpTypes::mpComplex_t t_f)
{
    if (t_i.size() == u_i.size()){
        this->clearCoefficients();

        mpTypes::mpComplex_t temp {"0.0", "0.0"};

        this->calculateCoefficients(t_i, u_i, t_f);
        temp = mpTypes::mpComplex_t{"0.0", "0.0"};
        for (int j = 0; j < u_i.size(); ++j){
            temp += u_i[j] * this->coefficientsAtT[j];
        }

        return temp;
    }else{
        qDebug() << Q_FUNC_INFO << "Init vectors have different size!";
        return mpTypes::mpComplex_t {"NaN", "NaN"};
    }
}

std::vector<mpTypes::mpComplex_t> interpolationLagrange::interpolateVector(const std::vector<mpTypes::mpComplex_t> &t_i, const std::vector<mpTypes::mpComplex_t> &u_i, const std::vector<mpTypes::mpComplex_t> &t_f)
{
    if (t_i.size() == u_i.size()){
        this->clearAll();

        mpTypes::mpComplex_t temp {"0.0", "0.0"};

        this->u_fin.resize(t_f.size());
        for (int i = 0; i < t_f.size(); ++i){
            this->calculateCoefficients(t_i, u_i, t_f[i]);
            temp = mpTypes::mpComplex_t{"0.0", "0.0"};
            for (int j = 0; j < u_i.size(); ++j){
                temp += u_i[j] * this->coefficientsAtT[j];
            }
            this->u_fin[i] = temp;
        }
        return this->u_fin;
    }else{
        qDebug() << Q_FUNC_INFO << "Init vectors have different size!";
        return std::vector<mpTypes::mpComplex_t>{};
    }
}

int interpolationLagrange::interpolateTest()
{
    this->clearAll();

    int N_i = 100;
    std::vector<mpTypes::mpComplex_t> t_i{};
    t_i.resize(N_i);
    std::vector<mpTypes::mpComplex_t> u_i{};
    u_i.resize(N_i);

    int N_f = 100;
    std::vector<mpTypes::mpComplex_t> t_f{};
    t_f.resize(N_i);
    std::vector<mpTypes::mpComplex_t> u_f{};
    u_f.resize(N_i);

    mpTypes::mpComplex_t a {"0.0", "0.0"};
    a = PI;

    mpTypes::mpComplex_t b {"0.0", "0.0"};
    b = PI * mpTypes::mpComplex_t {"-1.0", "0.0"};

    mpTypes::mpComplex_t h {"0.0", "0.0"};
    h = (b - a) / mpTypes::mpComplex_t {lexicalCast::toString<int>(N_i - 1), "0.0"};

    mpTypes::mpComplex_t shift {"0.0", "0.0"};

    for (int i = 0; i < N_i; ++i){
        t_i[i] = a + h * i;
        t_f[i] = a + h * i + shift;
        u_i[i] = sin(t_i[i]);
    }

    u_f = this->interpolateVector(t_i, u_i, t_f);

    mpTypes::mpComplex_t temp {"0.0", "0.0"};
    for (int i = 0; i < N_f; ++i){
        temp += abs(u_f[i] - u_i[i]) * abs(u_f[i] - u_i[i]);
    }
    temp = sqrt(temp);
    qDebug() << Q_FUNC_INFO << "Norm of difference: " << temp.str().c_str();

    return 0;
}

int interpolationLagrange::clearAll()
{
    this->coefficientsAtT.clear();
    this->u_fin.clear();

    return 0;
}

int interpolationLagrange::clearCoefficients()
{
    this->coefficientsAtT.clear();

    return 0;
}

int interpolationLagrange::calculateCoefficients(const std::vector<mpTypes::mpComplex_t>& t_i, const std::vector<mpTypes::mpComplex_t> &u_i, mpTypes::mpComplex_t t)
{
    if (t_i.size() == u_i.size()){
        this->clearCoefficients();
        this->coefficientsAtT.resize(u_i.size());
        mpTypes::mpComplex_t temp {"1.0", "0.0"};
        for (int i = 0; i < u_i.size(); ++i){
            temp = mpTypes::mpComplex_t {"1.0", "0.0"};
            for (int j = 0; j < t_i.size(); ++j){
                if (j != i){
                    temp *= (t - t_i[j]) / (t_i[i] - t_i[j]);
                }
            }
            this->coefficientsAtT[i] = temp;
        }
        return 0;
    }else{
        qDebug() << Q_FUNC_INFO << "Init vectors have different size!";
        return -1;
    }
}
