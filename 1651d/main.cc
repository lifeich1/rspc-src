#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>
#include <functional>

// Placeholder for upcoming includes, by rspc

#if 1 // Placeholder for trace toggle, by rspc
# define TRACE(FMT) do { std::cout << "d: " << FMT << std::endl; } while (0)
# define TRACEE(BLK) do { BLK; } while (0)
#else
# define TRACE(FMT)
# define TRACEE(BLK)
#endif

// Placeholder for upcoming un-std algorithm, by rspc

using namespace std;


#if __cplusplus >= 201402L
# define CONSTEXPR14 constexpr
#else
# define CONSTEXPR14
#endif

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

    CONSTEXPR14 bool operator< (Point2d const & rhs) const {
        return this->x < rhs.x || (this->x == rhs.x && this->y < rhs.y);
    }

    struct YXLess {
        CONSTEXPR14 bool operator()(Point2d const & lhs, Point2d const & rhs) {
            return lhs.y < rhs.y || (lhs.y == rhs.y && lhs.x < rhs.x);
        }
    };
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

template <class T, class Size>
class Input2dCoord {
public:
    typedef Point2d<T> Pn;
    typedef std::vector<Pn> Vec;

    template <class CharT>
    explicit Input2dCoord(std::basic_istream<CharT> &s, Size n) {
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
    typedef Point2d<T> Pn;
    typedef std::vector<Pn> Vec;
    typedef typename Vec::size_type size_type;

    explicit Discrete2dCoord(Vec * v): v{v}, discre{v->size()} {
        auto ds = make_discrete(&Pn::x);
        std::transform(ds.begin(), ds.end(), discre.begin(),
                discre.begin(), [](T x, Pn const & p) { return Pn{x, p.y}; });

        ds = make_discrete(&Pn::y);
        std::transform(ds.begin(), ds.end(), discre.begin(),
                discre.begin(), [](T y, Pn const & p) { return Pn{p.x, y}; });

        sort_v(std::less<Pn>{}, xh, xi).swap(sorted_xy);
        sort_v(typename Pn::YXLess{}, yh, yi).swap(sorted_yx);
    }

    Vec const & discreted() { return discre; }
    Vec const & sorted_x() { return sorted_xy; }
    Vec const & sorted_y() { return sorted_yx; }

    std::vector<size_type> const & x_order() { return xh; }
    std::vector<size_type> const & y_order() { return yh; }

    std::vector<size_type> const & x_index() { return xi; }
    std::vector<size_type> const & y_index() { return yi; }

private:
    template <class Cmp>
    Vec sort_v(Cmp cmp, std::vector<size_type> & ord, std::vector<size_type> & ind) {
        Vec s;
        auto n = v->size();
        s.reserve(n);
        std::copy(v->begin(), v->end(), std::back_inserter(s));
        std::sort(s.begin(), s.end(), cmp);

        auto f = [&](Pn const & p) {
            return std::lower_bound(s.begin(), s.end(), p, cmp) - s.begin();
        };
        ord.clear();
        ord.reserve(n);
        std::transform(v->begin(), v->end(), std::back_inserter(ord), f);

        std::vector<size_type>(n).swap(ind);
        size_type i = 0;
        std::for_each(ord.begin(), ord.end(), [&](size_type o) { ind[o] = i++; });
        return s;
    }

    template <class Extractor>
    std::vector<T> make_discrete(Extractor ext) {
        auto n = v->size();
        std::vector<T> dx;
        dx.reserve(n);
        auto f = std::bind(ext, std::placeholders::_1);
        std::transform(v->begin(), v->end(), std::back_inserter(dx), f);
        std::sort(dx.begin(), dx.end());
        dx.erase(std::unique(dx.begin(), dx.end()), dx.end());
        auto g = [&](Pn const & p) {
            auto x = f(p);
            return std::lower_bound(dx.begin(), dx.end(), x) - dx.begin();
        };
        std::vector<T> res;
        res.reserve(n);
        std::transform(v->begin(), v->end(), std::back_inserter(res), g);
        return res;
    }

    Vec * v;
    Vec discre, sorted_xy, sorted_yx;
    std::vector<size_type> xh, yh, xi, yi;
};


typedef Input2dCoord<int, int> I2d;
typedef I2d::Vec Vec;
typedef I2d::Pn Pn;
typedef Discrete2dCoord<int> Dsc;

int n;
Vec v;

int main() {
    cin >> n;
    I2d{cin, n} >> v;
    TRACEE(copy(v.begin(), v.end(), ostream_iterator<Pn>(cout, "\n")));

    Dsc dsc{&v};
    TRACE("discrete");
    TRACEE(auto const & v = dsc.discreted(); copy(v.begin(), v.end(), ostream_iterator<Pn>(cout, "\n")));
    TRACE("sorted_x");
    TRACEE(auto const & v = dsc.sorted_x(); copy(v.begin(), v.end(), ostream_iterator<Pn>(cout, "\n")));
    TRACE("sorted_y");
    TRACEE(auto const & v = dsc.sorted_y(); copy(v.begin(), v.end(), ostream_iterator<Pn>(cout, "\n")));

    TRACE("x-ord");
    TRACEE(auto const & v = dsc.x_order(); copy(v.begin(), v.end(), ostream_iterator<size_t>(cout, " ")); cout << endl);
    TRACE("y-ord");
    TRACEE(auto const & v = dsc.y_order(); copy(v.begin(), v.end(), ostream_iterator<size_t>(cout, " ")); cout << endl);
    TRACE("x-index");
    TRACEE(auto const & v = dsc.x_index(); copy(v.begin(), v.end(), ostream_iterator<size_t>(cout, " ")); cout << endl);
    TRACE("y-index");
    TRACEE(auto const & v = dsc.y_index(); copy(v.begin(), v.end(), ostream_iterator<size_t>(cout, " ")); cout << endl);

    return 0;
}
