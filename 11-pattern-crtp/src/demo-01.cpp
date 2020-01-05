#include <iostream>
#include <sstream>

/** method chaining using crtp
 */

template <typename PrinterImpl>
class PrinterBase {
public:
    PrinterBase(std::ostream& streamer) : ss(streamer) {}
    template <typename T>
    PrinterImpl& print(const T &t) {
        ss << t;
        return static_cast<PrinterImpl&>(*this);
    }
    template <typename T>
    PrinterImpl& println(const T &t) {
        ss << t << std::endl;
        return static_cast<PrinterImpl&>(*this);
    }
private:
    std::ostream& ss;
};

class Printer : public PrinterBase<Printer> {
public:
    Printer() : PrinterBase(std::cout) {}
    Printer& setColor(size_t c) {
        std::cout << "\033[1;" << c << "m";
        return *this;
    }
    Printer& resetColor() {
        std::cout << "\033[0m";
        return *this;
    }
};

int main(int,char**) {
    Printer printer;
    printer.println("hello world!").setColor(34).print("blue color! ").resetColor().println("normal color");
    return 0;
}