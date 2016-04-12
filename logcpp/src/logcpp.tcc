#ifndef _LOGCPP_TCC
#define _LOGCPP_TCC 1
#ifndef _LOGCPP_H
#   error logcpp.tcc must be included from logcpp.h
#endif // _LOGCPP_H

template<typename Output>
__LOGCPP_API__
void __log_variadic(const char* params, Output& out)
{
    out << params;
} // __log_variadic()

template<typename Output, typename T, typename... Args>
__LOGCPP_API__
void __log_variadic(const char* params,
                    Output&     out,
                    const T&    first_arg,
                    Args...     args)
{
    while (params) {
        if (*params == '%') {
            ++params;
            if (*params == 'v') {
                out << first_arg;
                ++params;
                __log_variadic(params,out,args...);
                return;
            }
        }
        out << *params;
        ++params;
    }
} // __log_variadic()

static
std::string get_localtime()
{
    using namespace std::chrono;

    // Holds buffer returned by strftime
    char buffer[TIME_BUFFER_SIZE];

    // Get current time and convert it into the string
    auto now = system_clock::to_time_t(system_clock::now());
    strftime(buffer, sizeof(buffer), "%c %Z", localtime(&now));

    return buffer;
} // get_localtime()

template<typename... Args>
__LOGCPP_API__
void log(const char* params, Args... args)
{
    std::ofstream ofs(__LOG_FILE__, std::ofstream::app | std::ofstream::out);

    ofs << get_localtime() << ' ';

    __log_variadic(params, ofs, args...);

    ofs << '\n';
} // log()

template<typename... Args>
__LOGCPP_API__ inline
void log(const std::string& params, Args... args)
{
    log(params.c_str(), args...);
} // log()

#endif // _LOGCPP_TCC
