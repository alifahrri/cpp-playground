#include <iostream>
#include <sstream>

class Printer {
public:
    Printer(std::ostream &streamer) : streamer(streamer) {}
    template <typename T>
    void print(const T& data) {
        streamer << data;
    }
    template <typename T>
    void println(const T& data) {
        streamer << data << std::endl;
    }
private:
    std::ostream &streamer;
};

template <typename PrinterImpl>
class ColorPrinter : public PrinterImpl {
public:
    template <typename ...Ts>
    ColorPrinter(Ts&...ts) : PrinterImpl(ts...) {}
    template <typename T>
    void colorPrint(const T& data, size_t color) {
        std::stringstream ss;
        ss << "\033[1;" << color << "m" 
            << data 
            << "\033[0m";
        this->print(ss.str());
    }
    template <typename T>
    void colorPrintln(const T& data, size_t color) {
        std::stringstream ss;
        ss << "\033[1;" << color << "m" 
            << data 
            << "\033[0m";
        this->println(ss.str());
    }
};

int main(int argc, char** argv) 
{
    ColorPrinter<Printer> printer(std::cout);
    printer.print("normal color; ");
    printer.colorPrint("other color; ",36);
    printer.println("back to normal; ");
    printer.colorPrintln("blue color; ",34);
    return 0;
}