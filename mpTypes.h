#ifndef MPTYPES_H
#define MPTYPES_H

#include <eigen3/Eigen/Core>

#include <boost/config.hpp> /// REQUIRED!!!
#include <boost/multiprecision/fwd.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_int/cpp_int_config.hpp>
#include <boost/multiprecision/cpp_bin_float.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_complex.hpp>
#include <boost/multiprecision/complex_adaptor.hpp>
#include <boost/multiprecision/number.hpp>
#include <boost/math/constants/constants.hpp>
#include <boost/operators.hpp>
#include <boost/multiprecision/eigen.hpp> /// Eigen спецификация для типов из boost::multiprecision

#define prec std::setprecision(std::numeric_limits<mpComplex_t::value_type>::digits10)

/*!
 * \brief mpTypes - типы данных с произвольным числом значащих цифр
 * (из boost::multiprecision)
 */
namespace mpTypes {

using namespace boost::multiprecision;

/*!
 * \brief prc - разрядность, с которой хотим провести расчет
 */
const unsigned int prc = 32u;

/*!
 * \brief prcToPrint - сколько знаков у чисел буем выводить в консоль/файлы
 */
const unsigned int prcToPrint = 16u;

/*!
 * \brief mpFloat_t - тип с плавающей точкой и произвольной разрядностью (32 * 4 = 128)
 */
typedef number<cpp_bin_float<prc>> mpFloat_t;

/*!
 * \brief mpComplex_t - тип комплексного числа с плавающей точкой и произвольной разрядностью (32 * 4 = 128)
 */
typedef number<complex_adaptor<cpp_bin_float<prc>>> mpComplex_t;

};

#endif // MPTYPES_H
