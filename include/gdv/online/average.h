/**
* \file online.h
* \brief provides utilities written by online algorithm.
**/
#ifndef GDV_ONLINE_AVERAGE_H_
#define GDV_ONLINE_AVERAGE_H_

namespace gdv {
namespace online {

/**
* \class average
* \brief calculate the average value of the entire input stream.
* \tparam Ty types that can arithmetic operate.
**/
template <typename Ty>
class average {
    static_assert(::std::is_floating_point<Ty>::value, "template parameter Ty must be floating point.");

public:
    /**
    * \exception none
    * \brief default constructor.
    **/
    average() noexcept
        : average_{}
        , count_{} {}

    /**
    * \exception none
    * \brief constructor.
    **/
    average(Ty avrg) noexcept
        : average_{avrg}
        , count_{} {}


    /**
    * \exception none
    * \brief copy constructor.
    **/
    average(const average &avrg) noexcept
        : average_{avrg.average_}
        , count_{avrg.count_} {}

    /**
    * \exception none
    * \brief copy assignment operator.
    **/
    average<Ty>& operator = (const average &avrg) noexcept {
        average_ = avrg.average_;
        count_ = avrg.count_;
        return *this;
    }

public:
    /**
    * \exception none
    * \param[in] x value.
    * \brief recalculate the average value with x append.
    **/
    average<Ty>& append(Ty x) noexcept {
        average_ += (x - average_) / static_cast<Ty>(++count_);
        return *this;
    }

    /**
    * \exception none
    * \param[in] x value.
    * \brief recalculate the average value with stream x append.
    **/
    average<Ty>& append(average x) noexcept {
        average_ += (x.average_ - average_)
            * static_cast<Ty>(x.count_) / static_cast<Ty>(count_ + x.count_);
        count_ += x.count_;
        return *this;
    }

    /**
    * \exception none
    * \brief get average.
    **/
    Ty value() const noexcept {return average_;}

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
    }

    /**
    * \exception none
    * \brief get average.
    **/
    operator Ty() noexcept {return average_;}

private:
    Ty      average_;
    size_t  count_;
};

/**
* \exception none
* \tparam T types that can arithmetic operate.
* \tparam U types that can be cast to T.
* \param[in] x average<Ty>.
* \param[in] y value.
* \brief append stream y to average.
**/
template <typename T, typename U>
average<T>& operator << (average<T> &x, U y) noexcept {
    x.append(static_cast<T>(y));
    return x;
}

/**
* \exception none
* \tparam Ty types that can arithmetic operate.
* \param[in] x average<Ty>.
* \param[in] y average<Ty>.
* \brief append stream y to average.
**/
template <typename Ty>
average<Ty>& operator << (average<Ty> &x, average<Ty> y) noexcept {
    x.append(y);
    return x;
}
} // namespace online
} // namespace gdv

#endif
