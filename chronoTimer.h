#ifndef CHRONOTIMER_H
#define CHRONOTIMER_H

#include <chrono>
#include <functional>
#include <utility>

/*!
 * \brief chronoTimer - всё необходимое для измерения времени на ЦП
 */
namespace chronoTimer {

/*!
 * \brief time_var - тип данных, хранящий временную метку
 */
typedef std::chrono::high_resolution_clock::time_point timeVar;

/**
 * \brief timeNow - макрос, возвращающий текущий момент времени
 */
#define timeNow()\
(\
    std::chrono::system_clock::now()\
)

/**
 * \brief timeTaken - макрос, возвращающий промежуток времени между p1 и p2 в секундах
 */
#define timeTaken(p1, p2)\
(\
    std::chrono::duration_cast<std::chrono::nanoseconds>( (p2) - (p1) ).count() / 1e9\
)

template <typename F, typename...Args>
auto timedFunction(const F& f, Args&&... args){
    timeVar tS = timeNow();

    auto result = f(std::forward<Args>(args)...);

    timeVar tF = timeNow();
    double t = timeTaken(tS, tF);
    return std::make_pair(result, t);
}

};

#endif // CHRONOTIMER_H
