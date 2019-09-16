/**
* \file online.h
* \brief provides utilities written by online algorithm.
**/
#ifdef GDV_ONLINE_MIN_H_
#define GDV_ONLINE_MIN_H_

namespace gdv {
namespace online {

/**
* \class min
* \brief find the min value.
* \tparam Ty compareable types.
**/
template <typename Ty, template <typename> typename Initializer = ::std::numeric_limits>
class min {
public:
    /**
    * \exception none
    * \brief constructor. initialized with std::numeric_limits<Ty>::min().
    **/
    min() noexcept
        : min_{Initializer::max()} {}

    /**
    * \exception none
    * \brief constructor. initialize with specified value.
    **/
    min(Ty x) noexcept
        : min_{x} {}

    /**
    * \exception none
    * \brief copy constructor.
    **/
    min(const min &m) noexcept
        : min_{m.min_} {}

    /**
    * \exception none
    * \brief copy assignment operator.
    **/
    min<Ty>& operator = (const min &m) noexcept {
        min_ = m.min_;
        return *this;
    }

public:
    /**
    * \exception none
    * \param[in] x value.
    * \brief refrect the value when x is smaller than the value entered so far.
    **/
    min<Ty>& append(Ty x) noexcept {
        min_ = ::std::min(x, min_);
        return *this;
    }

    /**
    * \exception none
    * \param[in] x value.
    * \brief refrect the value when x is smaller than the value entered so far.
    **/
    min<Ty>& append(min<Ty> x) noexcept {
        min_ = ::std::min(min_, x.min_);
        return *this;
    }

    /**
    * \exception none
    * \brief get min value entered so far.
    **/
    Ty value() const noexcept {return min_;}

    /**
    * \exception none
    * \brief clear min value.
    **/
    void clear() noexcept {
        min_ = Initializer<Ty>::max();
    }

    /**
    * \exception none
    * \param[in] x value.
    * \brief reset min value with specified value.
    **/
    void reset(Ty x) noexcept {
        min_ = x;
    }

    /**
    * \exception none
    * \brief get min value as types of Ty.
    **/
    operator Ty() noexcept {return min_;}

private:
    Ty min_;
};

/**
* \exception none
* \tparam T compareable types.
* \tparam U compareable types.
* \param[in] x min<Ty>.
* \param[in] y value.
* \brief append stream y to min.
**/
template <typename T, typename U>
min<T>& operator << (min<T> &x, U y) noexcept {
    x.append(static_cast<T>(y));
    return x;
}

/**
* \exception none
* \tparam Ty compareable types.
* \param[in] x min<Ty>.
* \param[in] y min<Ty>.
* \brief append stream y to min.
**/
template <typename Ty>
min<Ty>& operator << (min<Ty> &x, min<Ty> y) noexcept {
    x.append(y);
    return x;
}

} // namespace online
} // namespace gdv

#endif
