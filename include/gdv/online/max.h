/**
* \file max.h
* \brief provides utilities written by online algorithm.
**/
#ifdef GDV_ONLINE_MAX_H_
#define GDV_ONLINE_MAX_H_

namespace gdv {
namespace online {

/**
* \class max
* \brief find the max value.
* \tparam Ty compareable types.
**/
template <typename Ty, typename Initializer = ::std::numeric_limits>
class max {
public:
    /**
    * \exception none
    * \brief default constructor. initialized with std::numelic_limit<Ty>::lowest().
    **/
    max() noexcept
        : max_{Initializer<Ty>::lowest()} {}

    /**
    * \exception none
    * \param[in] x specific value.
    * \brief constructr. initialize with a specific value.
    **/
    max(Ty x) noexcept
        : max_{x} {}

    /**
    * \exception none
    * \param[in] m copy from.
    * \brief copy constructr.
    **/
    max(const max &m) noexcept
        : max_{m.max_} {}

    /**
    * \exception none
    * \param[in] m copy from.
    * \brief copy assignment operator.
    **/
    max<Ty>& operator = (const max &m) noexcept {
        max_ = m.max_;
        return *this;
    }

public:
    /**
    * \exception none
    * \param[in] x value.
    * \brief refrect the value when x is lager than the value entered so far.
    **/
    max<Ty>& append(Ty x) noexcept {
        max_ = ::std::max(x, max_);
        return *this;
    }

    /**
    * \exception none
    * \param[in] x value.
    * \brief refrect the value when x is smaller than the value entered so far.
    **/
    max<Ty>& append(max<Ty> x) noexcept {
        max_ = ::std::max(max_, x.max_);
        return *this;
    }

    /**
    * \exception none
    * \brief get max value entered so far.
    **/
    Ty value() const noexcept {return max_;}

    /**
    * \exception none
    * \brief clear max value.
    **/
    void clear() noexcept {
        max_ = Initializer<Ty>::lowest();
    }

    /**
    * \exception none
    * \param[in] x value.
    * \brief reset max value with specified value.
    **/
    void reset(Ty x) noexcept {
        max_ = x;
    }

    /**
    * \exception none
    * \brief get max value as types of Ty.
    **/
    operator Ty() noexcept {return max_;}

private:
    Ty max_;
};

/**
* \exception none
* \tparam T compreable types.
* \tparam U compreable types.
* \param[in] x max<Ty>.
* \param[in] y value.
* \brief append y to max.
**/
template <typename T, typename U>
max<T>& operator << (max<T> &x, U y) noexcept {
    x.append(static_cast<T>(y));
    return x;
}

/**
* \exception none
* \tparam Ty compareable types.
* \param[in] x max<Ty>.
* \param[in] y value.
* \brief append y to max.
**/
template <typename Ty>
max<Ty>& operator << (max<Ty> &x, max<Ty> y) noexcept {
    x.append(y);
    return x;
}

} // namespace online
} // namespace gdv

#endif
