#include <cstdlib>
#include <log4cxx/logger.h>
#include <log4cxx/consoleappender.h>
#include <log4cxx/patternlayout.h>
#include "app.h"
#include "app.moc"
#include "appinfo.h"

namespace
{
    bool matches_option(const QString& str1, const QString& str2, int mindashes=1, int maxdashes=2){
        int dashes = 0;
        if ( str2.length() > 0 ){
            while ((dashes<str2.length())&&(str2[dashes]=='-')){
                dashes++;
            }
        }
        if ( (dashes < mindashes) || (dashes > maxdashes) ){
            return false;
        }
        QString substr=str2.right(str2.length()-dashes);
        return (str1.compare(substr,Qt::CaseInsensitive)==0);
    }
}


App::App(int& argc, char** argv) : QApplication(argc,argv), _invocation(argv[0])
{
    // Enforce singleton property
    if ( _instance ){
        throw std::runtime_exception("Only one instance of App allowed.");
    }

    // Set the singleton instance to this
    _instance = this;

    // Set the application properties
    setApplicationName(APPLICATION_NAME);
    setApplicationVersion(APPLICATION_VERSION_STRING);
    setOrganizationName(APPLICATION_VENDOR_NAME);
    setOrganizationDomain(APPLICATION_VENDOR_URL);
    
    // Configure the logging mechanism
    log4cxx::LoggerPtr rootlogger = Logger::getRootLogger();
    rootlogger->addAppender(new ConsoleAppender(PatternLayout("[%-5p] %m%n")));
    
    // Parse the commandline
    int idx = 1;
    while ( idx < argc ){
        QString arg(argv[idx]);
        if ( matches_option(arg,"help",0) || matches_options(arg,"h") || matches_option(arg,"?",0) ){
            printHelpMessage();
            std::exit(0);
        }else if ( matches_option(arg,"version",0) ){
            print
        }else if ( matches_option(arg,"version-triplet") ){
        }else if ( matches_option(arg,"prefset") ){
        }else if ( matches_option(arg,"prefdel") ){
        }else if ( matches_option(arg,"preflist") ){
        }else if ( matches_option(arg,"prefget") ){
        }else if ( matches_option(arg,"log-level") ){
        }else if ( matches_option(arg,"appid") || matches_option("application-identifier") ){
        }else{
        }
    }
}

App::~App()
{
}

App*
App::INSTANCE()
{
    return _instance;
}

void 
App::printHelpMessage()
{
    std::cout << "Usage: " << getProjectInvocation() << " [options]" << std::endl;
    std::cout << "Options:" << std::endl;
    std::cout << "    --help                       Displays this help message." << std::endl;
    std::cout << "    --version                    Prints the program version." << std::endl;
    std::cout << "    --version-triplet            Prints the undecorated program version." << std::endl;
    std::cout << "    --appid                      Prints the unique application identifier." << std::endl;
    std::cout << "    --prefset <key>=<val>        Sets the given preference." << std::endl;
    std::cout << "    --prefdel <key>              Unsets the given preference." << std::endl;
    std::cout << "    --prefget <key>              Prints the given preference." << std::endl;
    std::cout << "    --preflist                   Lists all preferences that are set." << std::endl;
    std::cout << "    --loglevel <level>           Sets the current logging level." << std::endl;
    std::cout << "    --loglevel <logger>=<level>  Sets the logging level for the given logger." << std::endl;
    std::cout << "Log Levels:" << std::endl;
    std::cout << "    all" << std::endl;
    std::cout << "    trace" << std::endl;
    std::cout << "    debug" << std::endl;
    std::cout << "    info" << std::endl;
    std::cout << "    warn" << std::endl;
    std::cout << "    error" << std::endl;
    std::cout << "    fatal" << std::endl;
    std::cout << "    off" << std::endl;
}

void 
App::printVersionMessage()
{
}

void 
App::printVersionTripletMessage()
{
}

void 
App::printApplicationIdentifier()
{
}

QString 
App::getProjectName()
{
    return APPLICATION_NAME;
}


QString 
App::getProjectCodeName()
{
    return APPLICATION_CODENAME;
}

QString 
App::getProjectVendorID()
{
    return APPLICATION_VENDOR_ID;
}

QString 
App::getProjectVendorName()
{
    return APPLICATION_VENDOR_NAME;
}

QString 
App::getProjectID()
{
    return APPLICATION_ID;
}

int 
App::getProjectMajorVersion()
{
    return APPLICATION_VERSION_MAJOR;
}

int 
App::getProjectMinorVersion()
{
    return APPLICATION_VERSION_MINOR;
}

int 
App::getProjectPatchVersion()
{
    return APPLICATION_VERSION_PATCH;
}

QString 
App::getProjectVersion()
{
    return APPLICATION_VERSION_STRING;
}

QString 
App::getProjectCopyrightYears()
{
    return APPLICATION_COPYRIGHT_YEARS;
}

QString
App::getProjectInvocation()
{
    return _invocation;
}

App*
App::_instance = 0;
