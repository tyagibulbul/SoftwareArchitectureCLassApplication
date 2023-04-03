#include "LoggerUtils.h"

#include "CoreUtils.h"

// Inspired below

/*
 *          Copyright Andrey Semashev 2007 - 2015.
 * Distributed under the Boost Software License, Version 1.0.
 *    (See accompanying file LICENSE_1_0.txt or copy at
 *          http://www.boost.org/LICENSE_1_0.txt)
 */

#include <cstddef>
#include <string>
#include <ostream>
#include <fstream>
#include <iomanip>
#include <boost/smart_ptr/shared_ptr.hpp>
#include <boost/smart_ptr/make_shared_object.hpp>
#include <boost/phoenix/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/log/common.hpp>
#include <boost/log/core.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/attributes.hpp>
#include <boost/log/sources/basic_logger.hpp>
#include <boost/log/sources/logger.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/severity_channel_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <boost/log/sinks/sync_frontend.hpp>
#include <boost/log/sinks/text_ostream_backend.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/attributes/scoped_attribute.hpp>
#include <boost/log/utility/value_ref.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>

namespace logging = boost::log;
namespace src = boost::log::sources;
namespace expr = boost::log::expressions;
namespace sinks = boost::log::sinks;
namespace attrs = boost::log::attributes;
namespace keywords = boost::log::keywords;

typedef sinks::synchronous_sink< sinks::text_file_backend > file_sink;

// The operator puts a human-friendly representation of the severity level to the stream
std::ostream& operator<< (std::ostream& strm, severity_level level)
{
    static const char* strings[] =
    {
        "normal",
        "notification",
        "warning",
        "error",
        "critical"
    };

    if (static_cast<std::size_t>(level) < sizeof(strings) / sizeof(*strings))
        strm << strings[level];
    else
        strm << static_cast<int>(level);

    return strm;
}

//[ example_tutorial_filtering
BOOST_LOG_ATTRIBUTE_KEYWORD(line_id, "LineID", unsigned int)
BOOST_LOG_ATTRIBUTE_KEYWORD(severity, "Severity", severity_level)
BOOST_LOG_ATTRIBUTE_KEYWORD(tag_attr, "Tag", std::string)

bool isInit = false;

void init()
{
    if (isInit)
    {
        return;
    }
    else
    {
        isInit = true;
    }

    // Setup the common formatter for all sinks
    logging::formatter fmt = expr::stream
        << std::setw(6) << std::setfill('0') << line_id << std::setfill(' ')
        << ": <" << severity << ">\t"
        << expr::if_(expr::has_attr(tag_attr))
        [
            expr::stream << "[" << tag_attr << "] "
        ]
    << expr::smessage;

    // Initialize sinks
    typedef sinks::synchronous_sink< sinks::text_ostream_backend > text_sink;
    boost::shared_ptr< text_sink > sink = boost::make_shared< text_sink >();

    sink->locked_backend()->add_stream(
        boost::make_shared< std::ofstream >(BasePath() + "\\Logfiles\\full.log"));

    sink->set_formatter(fmt);

    logging::core::get()->add_sink(sink);

    sink = boost::make_shared< text_sink >();

    sink->locked_backend()->add_stream(
        boost::make_shared< std::ofstream >(BasePath() + "\\Logfiles\\important.log"));

    sink->set_formatter(fmt);

    sink->set_filter(severity >= warning || (expr::has_attr(tag_attr) && tag_attr == "IMPORTANT_MESSAGE"));

    logging::core::get()->add_sink(sink);


    boost::shared_ptr< file_sink > sink2(new  file_sink(
        keywords::file_name = "file.log",                       // file name pattern
        keywords::target_file_name = "%Y%m%d_%H%M%S_%5N.log",   // file name pattern
        keywords::rotation_size = 500           // rotation size, in characters
    ));

    // Set up where the rotated files will be stored
    sink2->locked_backend()->set_file_collector(sinks::file::make_collector(
        keywords::target = BasePath() + "\\Logfiles",                              // where to store rotated files
        keywords::max_size = 16 * 1024 * 1024,                  // maximum total size of the stored files, in bytes
        keywords::min_free_space = 100 * 1024 * 1024,           // minimum free space on the drive, in bytes
        keywords::max_files = 512                               // maximum number of stored files
    ));

    //sink->locked_backend()->add_stream(
    //    boost::make_shared< std::ofstream >(BasePath() + "\\Logfiles\\SizeLimited.log"));


    logging::core::get()->add_sink(sink2);



    // Add attributes
    logging::add_common_attributes();
}
//]

void LogMessages(const std::string& ctx, severity_level level)
{

    init();

    static src::severity_logger< severity_level > slg;

    BOOST_LOG_SEV(slg, level) << ctx << std::endl;

    // Below code is to spam the log file is different severity.
    // Just for Demo purposes

    //BOOST_LOG_SEV(slg, normal) << "A regular message" << std::endl;
    //BOOST_LOG_SEV(slg, normal) << ctx << std::endl;
    //BOOST_LOG_SEV(slg, warning) << "Something bad is going on but I can handle it" << std::endl;
    //BOOST_LOG_SEV(slg, warning) << ctx << std::endl;

    //BOOST_LOG_SEV(slg, critical) << "Everything crumbles, shoot me now!" << std::endl;
    //BOOST_LOG_SEV(slg, critical) << ctx << std::endl;

    //{
    //    BOOST_LOG_SCOPED_THREAD_TAG("Tag", "IMPORTANT_MESSAGE");
    //    BOOST_LOG_SEV(slg, normal) << "An important message" << std::endl;;
    //}



}



