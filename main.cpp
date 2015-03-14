#include <boost/program_options.hpp>
#include <iostream>
#include <function>

using namespace std;
namespace po = boost::program_options;

typedef st

template <typename Generator, typename Distribution>
void run() {
    Generator gen;
}

int main(int argc, char** argv) {
    // Declare the supported options.
    po::options_description all("Allowed options");
    all.add_options()
        ("help", "produce help message")
        ("g,generator", po::value<int>(), "Select the generator to use")
    ;

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    if (vm.count("help")) {
        cout << desc << "\n";
        return 1;
    }

    if (vm.count("compression")) {
        cout << "Compression level was set to " 
     << vm["compression"].as<int>() << ".\n";
    } else {
        cout << "Compression level was not set.\n";
    }

}