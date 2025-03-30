#ifndef INTERPOLATIONLAGRANGE_H
#define INTERPOLATIONLAGRANGE_H

#include <QDebug>
#include <vector>
#include <cmath>

#include "mpTypes.h"
#include "myTimer.h"
#include "lexicalCast.h"

class interpolationLagrange
{
public:
    interpolationLagrange();
    ~interpolationLagrange();
    mpTypes::mpComplex_t interpolateSingleValue(const std::vector<mpTypes::mpComplex_t>& t_i,
                                                const std::vector<mpTypes::mpComplex_t>& u_i,
                                                const mpTypes::mpComplex_t t_f);
    std::vector<mpTypes::mpComplex_t> interpolateVector(const std::vector<mpTypes::mpComplex_t>& t_i,
                                                        const std::vector<mpTypes::mpComplex_t>& u_i,
                                                        const std::vector<mpTypes::mpComplex_t>& t_f);
    int interpolateTest();
    int clearAll();
    int clearCoefficients();

private:
    const mpTypes::mpFloat_t pi = mpTypes::mpFloat_t("4.0") * atan( mpTypes::mpFloat_t("1.0") );
    const mpTypes::mpComplex_t PI {pi, "0.0"};

    std::vector<mpTypes::mpComplex_t> coefficientsAtT{};
    std::vector<mpTypes::mpComplex_t> u_fin{};

    int calculateCoefficients(const std::vector<mpTypes::mpComplex_t>& t_i,
                              const std::vector<mpTypes::mpComplex_t>& u_i,
                              const mpTypes::mpComplex_t t);
};

#endif // INTERPOLATIONLAGRANGE_H
