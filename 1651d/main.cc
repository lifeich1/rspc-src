#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>

// Placeholder for upcoming includes, by rspc
using namespace std;

// Placeholder for upcoming un-std algorithm, by rspc


template <class T>
struct Point2d {
    T x, y;
    Point2d() {}
    Point2d(T x, T y): x(x), y(y) {}

    inline T mdis(const Point2d& other) {
        return std::abs(x - other.x) + std::abs(y - other.y);
    }
    inline bool near(const Point2d& other, T th = 1) {
        return this->mdis(other) <= th;
    }
};
template <class CharT, class T>
std::basic_istream<CharT> & operator>>(std::basic_istream<CharT> &s, Point2d<T> & value) {
    return s >> value.x >> value.y;
}
template <class CharT, class T>
std::basic_ostream<CharT> & operator<<(std::basic_ostream<CharT> &s, Point2d<T> const & value) {
    return s << value.x << ' ' << value.y;
}

#if __cplusplus >= 201103L && !defined(RSPC_ALL_TEST)
using std::copy_n;
#else
template <class InputIt, class Size, class OutputIt>
OutputIt copy_n(InputIt first, Size count, OutputIt result) {
    if (count > 0) {
        *result++ = *first;
        for (Size i = 1; i < n; ++ i) {
            *result++ = * ++first;
        }
    }
    return result;
}
#endif

template <class T>
class Input2dCoord {
public:
    typedef Point2d<T> Pn;
    typedef std::vector<Pn> Vec;

    template <class CharT>
    explicit Input2dCoord(std::basic_istream<CharT> &s, int n) {
        v.reserve(n);
        copy_n(std::istream_iterator<Pn>(s), n, std::back_inserter(v));
    }

    Vec & operator>>(Vec & taker) {
        taker.swap(v);
        return taker;
    }

private:
    Vec v;
};

template <class T>
class Discrete2dCoord {
public:
    typedef typename std::vector<T>::size_type size_type;

private:
    size_type n;
    std::vector<T> x, y;
    std::vector<size_type> xh, yh;
};

struct Data {
    typedef Input2dCoord<int> I2d;
    typedef I2d::Vec Vec;
    typedef I2d::Pn Pn;

    int n;
    Vec v;

    void load() {
        cin >> n;
        I2d{cin, n} >> v;
        copy(v.begin(), v.end(), ostream_iterator<Pn>(cout, "\n"));
    }
} a;

int main() {
    a.load();
    cout << a.n << endl;
    return 0;
}
