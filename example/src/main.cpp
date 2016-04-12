#include <logcpp>

using namespace logcpp;

int main()
{
    log("INFO: Library loaded succesfully with params:%v, %v, %v", 'c', "string", 2.48);
    log("ERROR: Error log with value: %v", 420);
    log("INFO: Log %v, anywhere you want!", "anything");
}
