/**
 * @file logcpp.h LogCpp library
 * @details Simple, optimized, generic and thread safe logging routines.
 * @author Sebastian Bialobrzecki <sbb@openmailbox.org>
 * @version 0.0.1
 * @date 09.12.2015
 * @copyright GNU GPLv3 or newer
 */
#ifndef _LOGCPP_H
#define _LOGCPP_H 1
// Standard includes
#include <chrono>
#include <string>
#include <iomanip>
#include <fstream>
#include <ctime>

//! @def __LOGCPP_VERSION__ LogCpp version
//! @def __LOG_FILE__ Path and filename of the log file.
//! @def __LOGCPP_API__ Platform independant API.
//! @def TIME_BUFFER_SIZE Holds buffer used in get_localtime().

#define __LOGCPP_VERSION__ 0.0.1    
#ifdef __unix__
#   define __LOG_FILE__ "logfile"   
#   define __LOGCPP_API__           
#else
#   define __LOG_FILE__ "logfile"
#   define __LOGCPP_API__
#endif

// Buffer size used in conversion to localtime
#define TIME_BUFFER_SIZE 100

//! All functions from the logcpp library resides within the logcpp namespace.
namespace logcpp {

// __API__
/**
 * Create string with date and time (thread safe).
 * @return string with date and time info.
 */
static
std::string get_localtime();

/**
 * Output the characters from 'params' into 'out' stream.
 * This is the base function of __log_variadic function.
 * @param params   - Holds null terminated string with data to output.
 * @param out      - Holds opened file stream or other file handler.
 * @sa __log_variadic()
 */
template<typename Output>
// Requirements:
// 'out' has operator<< defined as the standard streams.
__LOGCPP_API__
void __log_variadic(const char* params, Output& out);

/**
 * Output the characters from 'params' into 'out' stream.
 *    This is the recursive function of __log_variadic function.
 *    Output each character from @params into 'out'.
 *    If "%v" string is found, output 'first_arg' and call this function
 *    recursively.
 * @param params       - Holds null terminated string with data to output.
 * @param out          - Holds opened file stream or other file handler.
 * @param first_arg    - First argument of the parameter pack.
 * @param args         - Holds parameters pack to output.
 * @sa __log_variadic(const char* params, Output& out)
 */
template<typename Output, typename T, typename... Args>
// Requirements:
// 'out' has operator<< defined as the standard streams.
// 'first_arg' has operator<< defined.
__LOGCPP_API__
void __log_variadic(const char* params,
                    Output&     out,
                    const T&    first_arg,
                    Args...     args);

/**
 * Interface for calling __log_variadic().
 * Front-end user function, calls __log_variadic().
 * @param params       - Holds null terminated string with data to output.
 * @param args         - Holds parameters pack to output.
 * @sa __log_variadic(const char* params, Output& out)
 */
template<typename... Args>
__LOGCPP_API__
void log(const char* params, Args... args);

/**
 * Overloaded version for std::string.
 * @param params       - Holds null terminated string with data to output.
 * @param args         - Holds parameters pack to output.
 * @sa __log_variadic(const char* params, Output& out)
 */
template<typename... Args>
__LOGCPP_API__ inline
void log(const std::string& params, Args... args);

#include "logcpp.tcc"

} // logcpp

#endif // __LOGCPP_GUARD__
