/**
* \file online.h
* \brief provides utilities written by online algorithm.
**/
#ifndef GDV_ONLINE_H_
#define GDV_ONLINE_H_

#include <type_traits>

namespace gdv {

/**
* \namespace online
**/
namespace online {

/**
* \class variance
* \brief calculate the variance value of the entire input stream.
* \tparam Ty types that can arithmetic operate.
**/
template <typename Ty>
class variance {
    static_assert(::std::is_floating_point<Ty>::value, "template parameter Ty must be floating point.");

public:
    /**
    * \exception none
    * \brief default constructor.
    **/
    variance() noexcept
        : variance_{}
        , average_{}
        , count_{} {}

    /**
    * \exception none
    * \brief copy constructor.
    **/
    variance(const variance& x) noexcept
        : variance_{x.variance_}
        , average_{x.average_}
        , count_{x.count_} {}

    /**
    * \exception none
    * \brief copy assignment operator.
    **/
    variance<Ty>& operator = (const variance& x) {
        average_ = x.average_;
        count_ = x.count_;
        return *this;
    }

public:
    /**
    * \exception none
    * \param[in] x value.
    * \brief recalculate the variance value with x append.
    **/
    variance<Ty>& append(Ty x) noexcept {
        Ty average_old = average_ * average_;
        average_ += (x - average_) / static_cast<Ty>(count_ + 1);
        Ty average_new = average_ * average_;
        variance_ += ((static_cast<Ty>(count_)
            * average_old - variance_ + (x * x))
            / static_cast<Ty>(count_ + 1)) - average_new;
        ++count_;
        return *this;
    }

    /**
    * \exception none
    * \param[in] x value.
    * \brief recalculate the variance value with stream x append.
    **/
    variance<Ty>& append(variance x) noexcept {
        Ty average_me = average_ * average_;
        Ty average_dst = x.average_ * x.average_;
        average_ += (x.average_ - average_)
            * static_cast<Ty>(x.count_) / static_cast<Ty>(count_ + x.count_);
        variance_ += (static_cast<Ty>(count_)
            * average_me + static_cast<Ty>(x.count_) * (x.variance_ - variance_ + average_dst))
            / static_cast<Ty>(count_ + x.count_) - (average_ * average_);
        count_ += x.count_;
        return *this;
    }

    /**
    * \exception none
    * \brief get variance.
    **/
    Ty value() const noexcept {return variance_;}

    /**
    * \exception none
    * \brief get average.
    **/
    Ty average() const noexcept {return average_;}

    /**
    * \exception none
    * \brief get sample variance.
    **/
    Ty sample_variance() const noexcept {return variance_;}

    /**
    * \exception none
    * \brief get unbiased variance.
    **/
    Ty unbiased_variance() const noexcept {return variance_;}

    /**
    * \exception none
    * \brief get the number of input values
    **/
    size_t size() const noexcept {return count_;}

    /**
    * \exception none
    * \brief clear the average
    **/
    void clear() noexcept {
        count_ = 0;
        average_ = static_cast<Ty>(0);
        variance_ = static_cast<Ty>(0);
    }

private:
    Ty      variance_;
    Ty      average_;
    size_t  count_;
};

/**
* \exception none
* \tparam Ty types that can arithmetic operate.
* \param[in] x variance<Ty>.
* \param[in] y value.
* \brief append stream y to variance.
**/
template <typename Ty>
variance<Ty>& operator << (variance<Ty> &x, Ty y) noexcept {
    x.append(y);
    return x;
}

/**
* \exception none
* \tparam Ty types that can arithmetic operate.
* \param[in] x variance<Ty>.
* \param[in] y variance<Ty>.
* \brief append stream y to variance.
**/
template <typename Ty>
variance<Ty>& operator << (variance<Ty> &x, variance<Ty> y) noexcept {
    x.append(y);
    return x;
}

} // namespace online
} // namespace gdv

#endif

